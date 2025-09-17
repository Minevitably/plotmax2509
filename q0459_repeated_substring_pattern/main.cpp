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
    /**
     * check if main string can be constructed by taking a substring length of n
     * @param n length of sub string
     * @param s main string
     * @return match result
     */
    bool testSub(int n, const string &s) {
        for (int j = 0; j < n; j++) {
            for (int k = j; k < s.size(); k += n) {
                if (s[j] != s[k]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        for (int i = 1; i <= size / 2; i++) {
            if (size % i != 0) {
                continue;
            }
            bool isMatch = testSub(i, s);

            if (isMatch) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
