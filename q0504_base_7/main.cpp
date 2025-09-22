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
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string res;

        int val = num;
        num = abs(num);
        while (num > 0) {
            res.push_back((num % 7) + '0');
            num /= 7;
        }
        if (val < 0) {
            res.push_back('-');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
