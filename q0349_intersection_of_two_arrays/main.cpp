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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1Set;
        set<int> nums2Set;
        set<int> inter2Set;
        vector<int> inter;

        for (int num: nums1) {
            nums1Set.insert(num);
        }
        for (int num: nums2) {
            nums2Set.insert(num);
        }
        for (int num: nums1Set) {
            if (nums2Set.count(num) > 0) {
                inter2Set.insert(num);
            }
        }
        for (int num: inter2Set) {
            inter.push_back(num);
        }
        return inter;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
