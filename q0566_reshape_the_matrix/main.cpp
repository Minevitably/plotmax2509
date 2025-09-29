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
        for (int k = 0; k < r * c; k++) {
            res[k / c][k % c] = mat[k / n][k % n];
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
