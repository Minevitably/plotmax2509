#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    string vowels = "aeiou";
private:
    bool isVowel(char ch) {
        for (char vowel: vowels) {
            if (tolower(ch) == vowel) {
                return true;
            }
        }
        return false;
    }

    int updateLeft(const string &s, int left) {
        int size = s.size();
        while (left < size) {
            if (isVowel(s[left])) {
                return left;
            }
            left++;
        }
        return size - 1;
    }

    int updateRight(const string &s, int right) {
        while (0 <= right) {
            if (isVowel(s[right])) {
                return right;
            }
            right--;
        }
        return 0;
    }

public:
    string reverseVowels(string s) {
        int left = updateLeft(s, 0);
        int right = updateRight(s, s.size() - 1);
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left = updateLeft(s, left + 1);
            right = updateRight(s, right - 1);
        }
        return s;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
