#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    int nums[46340];
public:
    Solution() {
        for (int i = 0; i < 46340; i++) {
            nums[i] = (i + 1) * (i + 1);
        }
    }
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; i < 46340; i++) {
            if (nums[i] == num) {
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
