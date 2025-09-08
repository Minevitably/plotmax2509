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
        if (num == 1 || num == 4) {
            return true;
        }
        if (num < 4) {
            return false;
        }
        int half = num / 2;
        for (int i = 1; i < half && i < 46341; i++) {
            if (i * i == num) {
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
