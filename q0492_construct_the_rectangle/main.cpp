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
    vector<int> constructRectangle(int area) {
        vector<int> min = {INT_MAX, 0};
        int n = sqrt(area);
        for (int i = 1; i <= n; i++) {
            if (area % i == 0) {
                int length = i;
                int width = area / i;
                if (length < width) {
                    swap(length, width);
                }
                if (length - width < min[0] - min[1]) {
                    min[0] = length;
                    min[1] = width;
                }
            }
        }
        return min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
