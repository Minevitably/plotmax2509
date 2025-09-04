#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        for (int i = 0; i < 31; i++) {
            if (pow(3, i) > INT_MAX) {
                return false;
            }
            if (pow(3, i) == n) {
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
