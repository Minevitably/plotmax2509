#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;


class Solution {
private:
    bool allCapital(const string &word) {
        for (char ch: word) {
            if (islower(ch)) {
                return false;
            }
        }
        return true;
    }
    bool allLower(const string &word) {
        for (char ch: word) {
            if (isupper(ch)) {
                return false;
            }
        }
        return true;
    }
    bool onlyFirstCapital(const string &word) {
        if (islower(word[0])) {
            return false;
        }
        for (int i = 1; i < word.size(); i++) {
            if (isupper(word[i])) {
                return false;
            }
        }
        return true;
    }
public:
    bool detectCapitalUse(string word) {
        return allCapital(word) || allLower(word) || onlyFirstCapital(word);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
