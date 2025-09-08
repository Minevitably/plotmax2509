#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);


class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = right - (right - left) / 2;
            int v = guess(mid);
            if (v == 0) {
                return mid;
            } else if (v == 1){
                left = mid + 1;
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
