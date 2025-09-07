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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nums1Map;
        map<int, int> nums2Map;
        map<int, int> interMap;
        vector<int> interNums;

        for (int num: nums1) {
            if (nums1Map.count(num) == 0) {
                nums1Map[num] = 0;
            }
            nums1Map[num]++;
        }

        for (int num: nums2) {
            if (nums2Map.count(num) == 0) {
                nums2Map[num] = 0;
            }
            nums2Map[num]++;
        }

        for (auto item: nums1Map) {
            if (nums2Map.count(item.first) > 0) {
                int v = min(nums2Map[item.first], item.second);
                interMap[item.first] = v;
            }
        }

        for (auto item: interMap) {
            for (int i = 0; i < item.second; i++) {
                interNums.push_back(item.first);
            }
        }
        return interNums;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
