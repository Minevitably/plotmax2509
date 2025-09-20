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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), 0);
        for (int i = 0; i < nums1.size(); i++) {
            int j;
            bool startFind = false;
            for (j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    startFind = true;
                }
                if (startFind && nums2[j] > nums1[i]) {
                    break;
                }
            }
            if (j == nums2.size()) {
                ans[i] = -1;
            } else {
                ans[i] = nums2[j];
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
