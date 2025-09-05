#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        for (int x = 0; x <= 15; x++) {
            if (pow(4, x) == n) {
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
