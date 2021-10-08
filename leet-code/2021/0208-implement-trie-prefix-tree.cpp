// https://leetcode.com/problems/implement-trie-prefix-tree

struct Node {
    vector<Node*> children;
    bool word;

    Node() {
        children.resize('z'-'a'+1, nullptr);
        word = false;
    }
};

class Trie {
    Node* root = new Node;
public:
    void insert(const string& word) {
        auto current = root;
        for (char c : word) {
            if (!current->children[c-'a']) {
                current->children[c-'a'] = new Node;
            }
            current = current->children[c-'a'];
        }
        current->word = true;
    }

    bool search(const string& word) {
        auto [count, node] = countMatches(word);
        return count == word.size() && node->word;
    }

    bool startsWith(const string& prefix) {
        auto [count, _node] = countMatches(prefix);
        return count == prefix.size();
    }

    pair<int, Node*> countMatches(const string& word) {
        auto current = root;
        int count=0;
        for (; count < word.size(); ++count) {
            char c = word[count];
            if (!current->children[c-'a']) {
                break;
            }
            current = current->children[c-'a'];
        }
        return {count, current};
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
