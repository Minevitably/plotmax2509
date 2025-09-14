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
    string addStrings(string num1, string num2) {
        int carry = 0;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        string res;
        int maxLength = std::max(num1.size(), num2.size());
        for (int i = 0; i < maxLength; i++) {
            int num1i = 0;
            int num2i = 0;
            if (i < num1.size()) {
                num1i = (int)(num1[i] - '0');
            }
            if (i < num2.size()) {
                num2i = (int)(num2[i] - '0');
            }
            char resi = (num1i + num2i + carry) % 10 + '0';
            carry = (num1i + num2i + carry) / 10;
            res.push_back(resi);
        }
        if (carry > 0) {
            res.push_back('1');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
