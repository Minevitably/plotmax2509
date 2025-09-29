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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (r * c != m * n) {
            return mat;
        }

        vector<vector<int>> res(r, vector<int>(c));
        // i1 * n + j1 == i2 * c + j2
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int k = i * c + j;
                int i1 = k / n;
                int j1 = k % n;
                res[i][j] = mat[i1][j1];
            }
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
