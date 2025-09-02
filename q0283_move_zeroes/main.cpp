#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int j;
                for (j = i + 1; j < n && nums[j] == 0; j++) {
                    ;
                }
                if (j >= n) {
                    return;
                }
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
