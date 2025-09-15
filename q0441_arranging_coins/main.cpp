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
    int arrangeCoins(int n) {
        int full = 0;
        for (int i = 0; n > 0; i++) {
            n -= (i + 1);
            if (n >= 0) {
                full++;
            }
        }
        return full;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
