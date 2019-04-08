/*
 * https://www.hackerrank.com/challenges/ctci-contacts
 */

#include <string>
#include <iostream>
#include <unordered_map>

class Node {
    int timesTouched;
public:
    std::unordered_map<char, Node*> children;
    Node() : timesTouched(0) {}
    void incrementTouches() {
        ++timesTouched;
    }
    int getTouches() {
        return timesTouched;
    }
};

class Trie {
    Node root, *current;
public:
    void add(const std::string& word) {
        current = &root;
        for (const auto& character : word) {
            if (!current->children.count(character)) {
                current->children[character] = new Node;
            }
            current = current->children[character];
            current->incrementTouches();
        }
    }
    int find(const std::string& word) {
        current = &root;
        for (const auto& character : word) {
            if (!current->children.count(character)) return 0;
            current = current->children[character];
        }
        return current->getTouches();
    }
};

int main() {
    int n;
    std::cin >> n;
    Trie trie;
    for (int i = 0; i < n; ++i) {
        std::string op;
        std::string contact;
        std::cin >> op >> contact;
        if (op == "add") trie.add(contact);
        else if (op == "find") std::cout << trie.find(contact) << std::endl;
        else return 1; // error
    }
    return 0;
}
