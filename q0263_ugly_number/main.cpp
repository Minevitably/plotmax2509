#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {

public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        bool flag = true;
        while (n > 1) {
            flag = false;
            if (n % 2 == 0) {
                n /= 2;
                flag = true;
            }
            if (n % 3 == 0) {
                n /= 3;
                flag = true;
            }
            if (n % 5 == 0) {
                n /= 5;
                flag = true;
            }
            if (!flag) {
                return false;
            }
        }
        return true;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
