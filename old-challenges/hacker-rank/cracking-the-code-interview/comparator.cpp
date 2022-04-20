/*
 * https://www.hackerrank.com/challenges/ctci-comparator-sorting
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "quicksort.hpp"

template <class T>
class Comparator {
public:
    virtual int compare(T o1, T o2) = 0;
};

template <class T>
class Checker : public Comparator<T> {
public:
    int compare(T o1, T o2) {
        int score(o1.score - o2.score);
        return -1 * ( score ? score : o2.name.compare(o1.name) );
    }
};

struct Player {
    std::string name;
    int score;
    int operator<(const Player& another) {
        Checker<Player> checker;
        return checker.compare(*this, another) < 0;
    }
    int operator<=(const Player& another) {
        Checker<Player> checker;
        return checker.compare(*this, another) <= 0;
    }
    int operator>(const Player& another) {
        Checker<Player> checker;
        return checker.compare(*this, another) > 0;
    }
    int operator>=(const Player& another) {
        Checker<Player> checker;
        return checker.compare(*this, another) >= 0;
    }
};

std::vector<Player> comparator(std::vector<Player>& players) {
    Quicksort<Player> quicksort;
    return quicksort.sort(players);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Player> players;
    std::string name;
    int score;
    for (int i = 0; i < n; ++i) {
        std::cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }

    std::vector<Player> answer = comparator(players);
    for (std::vector<Player>::size_type i = 0; i < answer.size(); ++i) {
        std::cout << answer[i].name << " " << answer[i].score << std::endl;
    }
    return 0;
}
