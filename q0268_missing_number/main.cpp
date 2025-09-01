#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        return nums.size()*(nums.size() + 1) / 2 - sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
