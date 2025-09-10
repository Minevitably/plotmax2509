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
    char findTheDifference(string s, string t) {
        map<char, int> sMap;
        map<char, int> tMap;
        for (auto ch: s) {
            sMap[ch] += 1;
        }
        for (auto ch: t) {
            tMap[ch] += 1;
        }
        for (auto item: tMap) {
            if (tMap[item.first] - sMap[item.first] != 0) {
                return item.first;
            }
        }
        return '0';
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
