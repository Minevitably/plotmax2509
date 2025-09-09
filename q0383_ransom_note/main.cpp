#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);


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
