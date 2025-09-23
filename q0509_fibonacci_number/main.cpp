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
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution solution;
    for (int i = 0; i < 31; i++) {
        std::cout << solution.fib(i) << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
