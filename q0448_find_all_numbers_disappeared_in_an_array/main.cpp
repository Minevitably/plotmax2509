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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res;
        if (n <= 0) {
            return res;
        }
        vector<bool> existed(n, false);
        for (int i = 0; i < n; i++) {
            existed[nums[i] - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!existed[i]) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
