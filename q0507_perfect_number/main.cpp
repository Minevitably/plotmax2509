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
    bool checkPerfectNumber(int num) {
        vector<int> positiveDivisors;
        int end = sqrt(num);
        for (int i = 1; i <= end; i++) {
            if (num % i == 0) {
                int d = num / i;
                if (num != d) {
                    positiveDivisors.emplace_back(d);
                }
                if (num != i) {
                    positiveDivisors.emplace_back(i);
                }
            }
        }
        for (int positiveDivisor : positiveDivisors) {
            num -= positiveDivisor;
        }
        return num == 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
