#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    int get1Count(int num) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                count++;
            }
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            ans.push_back(get1Count(i));
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
