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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                // start count
                count = 0;
                while (i < nums.size() && nums[i] == 1) {
                    count++;
                    i++;
                }
                maxCount = std::max(maxCount, count);
            }
        }

        return maxCount;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
