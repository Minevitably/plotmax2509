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
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for (int i = 0; i < n; i++) {
            bool canDiv3 = ((i + 1) % 3 == 0);
            bool canDiv5 = ((i + 1) % 5 == 0);
            if (canDiv3 && canDiv5) {
                res.emplace_back("FizzBuzz");
            } else if (canDiv3) {
                res.emplace_back("Fizz");
            } else if (canDiv5) {
                res.emplace_back("Buzz");
            } else {
                res.emplace_back(to_string(i + 1));
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
