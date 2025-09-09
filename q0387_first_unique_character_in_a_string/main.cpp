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
    bool isRepeat(int index, const string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (i == index) {
                continue;
            }
            if (s[i] == s[index]) {
                return true;
            }
        }
        return false;
    }
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (!isRepeat(i, s)) {
                return i;
            }
        }
        return -1;
    }
};


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magaMap;
        for (int i = 0; i < magazine.size(); i++) {
            if (magaMap.count(magazine[i]) == 0) {
                magaMap[magazine[i]] = 0;
            }
            magaMap[magazine[i]] += 1;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (magaMap.count(ransomNote[i]) > 0 &&
            magaMap[ransomNote[i]] > 0) {
                magaMap[ransomNote[i]] -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    (new Solution())->canConstruct("aa", "ab");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
