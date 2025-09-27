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
    bool checkRecord(string s) {
        int absent = 0;
        int late = 0;
        for (int i = 0; i < s.size(); i++) {
            late = 0;
            while (i < s.size() && s[i] == 'L') {
                late++;
                if (late >= 3) {
                    return false;
                }
                i++;
            }

            if (i < s.size() && s[i] == 'A') {
                absent++;
                if (absent >= 2) {
                    return false;
                }
            }

        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
