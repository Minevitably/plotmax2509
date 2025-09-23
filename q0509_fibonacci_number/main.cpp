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
        // 0 1 1
        if (n == 0 || n == 1) {
            return n;
        }
        int fn = 0;
        int f1 = 1;
        int f2 = 0;
        for (int i = 0; i < n - 1; i++) {
            fn = f1 + f2;
            f2 = f1;
            f1 = fn;
        }
        return fn;
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
