#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
//    q0387_first_unique_character_in_a_string
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
