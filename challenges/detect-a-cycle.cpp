/*
 * https://www.hackerrank.com/challenges/ctci-linked-list-cycle
 */

#include <iostream>
#include <stdexcept>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        if (!head) {
            head = new Node(data);
            return;
        }

        auto current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    Node* get(int n) {
        if (!head) throw std::length_error("we need at least one element for getting");
        auto current = head;
        for (int i(0); i < n; ++i) {
            if (!current->next) throw std::out_of_range("we need at least "+std::to_string(n)+" element/s");
            current = current->next;
        }
        return current;
    }

    void print() const {
        auto current = head;
        while (current) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    void makeCycle(Node* node) {
        if (!head) throw std::length_error("we need at least one element");
        auto current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    bool cycle() {
        if (!head) return false;
        Node* fast = head->next;
        Node* slow = head;
        while (fast && fast->next) {
            if (fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
            std::cerr << "." << std::endl;
        }
        return false;
    }
};

bool has_cycle(Node* head) {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    LinkedList ll;
    ll.insert(8);
    ll.insert(3);
    ll.insert(5);
    ll.insert(50);
    ll.print();
    ll.makeCycle(ll.get(2));
    if (ll.cycle()) {
        std::cerr << "Cycle detected" << std::endl;
    }
    return 0;
}
