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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int n = g.size();
        int m = s.size();

        for (int j = 0; j < m && i < n; j++) {
            if (g[i] > s[j]) {
                continue;
            }
            i++;
            count++;
        }

        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
