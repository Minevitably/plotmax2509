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
    int countSegments(string s) {
        vector<string> tokens;
        char delimiter = ' ';
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != delimiter) {
                count++;
            }
            while (i < s.size() && s[i] != delimiter) {
                i++;
            }
        }
        return count;
    }
};

int main() {
    (new Solution())->countSegments("hell me  me mm");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
