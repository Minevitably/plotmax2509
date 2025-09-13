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
    int thirdMax(vector<int>& nums) {
        int max = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        int min = INT_MAX;
        for (int num: nums) {
            if (num > max) {
                third = second;
                second = max;
                max = num;
            }
            if ( num < max && num > second) {
                third = second;
                second = num;
            }
            if ( num < second && num > third) {
                third = num;
            }

            if (num < min) {
                min = num;
            }
        }
        return (third >= min && third < second) ? third : max;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
