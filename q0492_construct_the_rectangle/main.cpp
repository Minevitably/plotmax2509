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
        vector<vector<int>> lwVec;
        int n = sqrt(area);
        for (int i = 1; i <= n; i++) {
            if (area % i == 0) {
                vector<int> vec;
                int p = area / i;
                if (p >= i) {
                    vec.emplace_back(p);
                    vec.emplace_back(i);
                } else {
                    vec.emplace_back(i);
                    vec.emplace_back(p);
                }
                lwVec.emplace_back(vec);
            }
        }

        int min = INT_MAX;
        int j = 0;
        for (int i = 0; i < lwVec.size(); i++) {
            int current = lwVec[i][0] - lwVec[i][1];
            if (current < min) {
                min = current;
                j = i;
            }
        }
        return lwVec[j];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
