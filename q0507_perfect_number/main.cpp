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
        int sum = 0;
        int end = sqrt(num);
        for (int i = 1; i <= end; i++) {
            if (num % i == 0) {
                int d = num / i;
                if (num != d) {
                    sum += d;
                }
                if (num != i) {
                    sum += i;
                }
            }
        }
        return num == sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
