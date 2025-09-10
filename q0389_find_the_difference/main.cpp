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
        char ch = 0;
        for (char sc: s) {
            ch ^= sc;
        }
        for (char tc: t) {
            ch ^= tc;
        }
        return ch;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
