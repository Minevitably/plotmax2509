#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
private:
    bool hit(int n) {
        return !isBadVersion(n - 1) &&
               ((n == INT_MAX) || isBadVersion(n + 1));
    }

public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int versionVal = mid + 1;
            if (!isBadVersion(versionVal)) {
                left = mid + 1;
            } else if (hit(versionVal)) {
                return versionVal;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
