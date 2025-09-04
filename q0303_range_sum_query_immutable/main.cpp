#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class NumArray {
private:
    vector<int> array;
public:
    NumArray(vector<int>& nums) {
        for (auto num: nums) {
            array.push_back(num);
        }
    }

    int sumRange(int left, int right) {
        int sum = 0;
        if (left < 0) {
            left = 0;
        }
        if (right > array.size() - 1) {
            right = array.size() - 1;
        }
        for (int i = left; i <= right; i++) {
            sum += array[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
