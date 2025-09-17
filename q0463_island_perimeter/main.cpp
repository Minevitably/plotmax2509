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
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int length = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {

                    int island = 0;
                    if (i - 1 >= 0) {
                        island += grid[i - 1][j];
                    }
                    if (i + 1 < row) {
                        island += grid[i + 1][j];
                    }
                    if (j - 1 >= 0) {
                        island += grid[i][j - 1];
                    }
                    if (j + 1 < col) {
                        island += grid[i][j + 1];
                    }
                    length += (4 - island);
                }
            }
        }
        return length;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
