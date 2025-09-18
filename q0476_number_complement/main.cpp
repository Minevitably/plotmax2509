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
    int findComplement(int num) {
        bool flag = false;
        for (int i = 31; i >= 0; i--) {
            if (!flag && (((num >> i) & 1) == 1)) {
                flag = true;
            }
            if (flag) {
                num ^= (1 << i);
            }
        }
        return num;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
