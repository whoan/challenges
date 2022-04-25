// https://leetcode.com/problems/design-file-system/
// Medium

class FileSystem {
    std::unordered_map<string, int> values;
public:
    bool createPath(string path, int value) {
        if (values.count(path)) {
            return false;
        }
        auto parent = path.substr(0, path.rfind('/'));
        if (!parent.empty() && values.count(parent) == 0) {
            return false;
        }
        values[path] = value;
        return true;
    }

    int get(string path) {
        auto it = values.find(path);
        if (it == values.end()) {
            return -1;
        }
        return it->second;
    }
};


// Trie version. Susprisingly, horrible performance and memory consumption
class TrieNode {
public:
    TrieNode(int value=0) : value(value) {}

    // also tried with map but memory didn't get better
    std::unordered_map<string, std::shared_ptr<TrieNode>> children;
    int value;
};

class FileSystem {
    std::shared_ptr<TrieNode> root;
public:
    FileSystem() {
        root = std::make_shared<TrieNode>();
    }

    bool createPath(string path, int value) {
        auto current = root;
        auto tokens = split(path);
        auto last = move(tokens.back());
        tokens.pop_back();
        for (auto& token : tokens) {
            auto found = current->children.find(token);
            if (found == current->children.end()) {
                return false;
            }
            current = found->second;
        }
        return current->children.emplace(std::move(last), make_shared<TrieNode>(value)).second;
    }

    int get(string path) {
        auto current = root;
        for (auto& token : split(path)) {
            auto found = current->children.find(token);
            if (found == current->children.end()) {
                return -1;
            }
            current = found->second;
        }
        return current->value;
    }
private:
    std::vector<std::string> split(std::string_view input) const {
        input.remove_prefix(1); // remove first '/'
        std::vector<std::string> tokens;
        size_t start = 0;
        for (auto pos = input.find('/'); pos != std::string_view::npos; pos = input.find('/', start)) {
            tokens.push_back(std::string(input.substr(start, pos-start)));
            start = pos + 1;
        }
        tokens.push_back(std::string(input.substr(start)));
        return tokens;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
