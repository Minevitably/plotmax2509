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
    string reverseWords(string s) {
        string res;
        stringstream ss(s);
        string str;
        while (getline(ss, str, ' ')) {
            std::reverse(str.begin(), str.end());
            res += str;
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
