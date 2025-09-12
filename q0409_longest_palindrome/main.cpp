#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int sum = 0;
        map<char, int> count;
        for (char ch: s) {
            count[ch]++;
        }

        bool hasOdd = false;
        for (pair<char, int> item: count) {
            int val = item.second;
            if (val & 1) {
                hasOdd = true;
                val--;
            }
            sum += val;
        }
        if (hasOdd) {
            sum++;
        }

        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
