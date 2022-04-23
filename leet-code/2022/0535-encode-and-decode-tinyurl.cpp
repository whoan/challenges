// https://leetcode.com/problems/encode-and-decode-tinyurl/
// Medium

// disclaimer: made this solution after taking some ideas from https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/
// this class represents a service that we can call to get always-unique ids
template<typename T>
class Service {
public:
    T get_unique_id() {
        // using auto_inct is a security threat, but still fine for this exercise
        static std::atomic<T> auto_incr = 1e8; // play with this
        return auto_incr.fetch_add(1);
    }
};

// this class represents the storage to map short to long urls
// we might want to use multiple DB servers and cache for the
// most used short urls
class Storage {
public:
    string get_long_url(const string& short_url) const {
        // suppose it always succeeds for now. easy to fix anyways
        return db.at(short_url);
    }

    void save_long_url(const string& short_url, string long_url) {
        db[short_url] = std::move(long_url);
    }

private:
    std::unordered_map<string, string> db;
};


Service<unsigned int> service;
Storage storage;;

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string long_url) {
        // I am not relying on input to create the short urls
        int unique_id = service.get_unique_id();
        string short_url;
        while (unique_id) {
            short_url.push_back(valid_chars[unique_id % length_valid_chars]);
            unique_id /= length_valid_chars;
        }
        storage.save_long_url(short_url, std::move(long_url));
        return short_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return storage.get_long_url(shortUrl);
    }

private:
    static constexpr int length_valid_chars = 26 + 26 + 10 + 1;
    char valid_chars[length_valid_chars] =
        "ABCDEFGHIJKLMNOPQRSTUVWQYZ"
        "abcdefghijklmnopqrstuvwqyz"
        "0123456789";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
