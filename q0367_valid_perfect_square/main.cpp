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
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            int mid = right - (right - left) / 2;
            if (mid > 46340) {
                right = mid - 1;
                continue;
            }
            int current = mid * mid;
            if (current == num) {
                return true;
            } else if (current < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
