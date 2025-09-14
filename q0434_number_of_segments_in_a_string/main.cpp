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
        stringstream ss(s);
        string token;
        while (getline(ss, token, delimiter)) {
            if (token.empty()) {
                continue;
            }
            tokens.emplace_back(token);
        }
        return tokens.size();
    }
};

int main() {
    (new Solution())->countSegments("hell me  me mm");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
