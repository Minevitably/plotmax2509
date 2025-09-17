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
    int hammingDistance(int x, int y) {
        x ^= y;
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += ((x >> i) & 1);
        }
        return count;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
