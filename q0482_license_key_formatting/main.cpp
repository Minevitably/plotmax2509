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
    string licenseKeyFormatting(string s, int k) {
        string t;
        string res;
        for (char ch: s) {
            if (ch != '-') {
                t += toupper(ch);
            }
        }
        std::reverse(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++) {
            res += t[i];
            if (((i + 1) % k == 0) && i != t.size() - 1) {
                res += '-';
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
