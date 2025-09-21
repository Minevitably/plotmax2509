#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

private:
    void inOrder(TreeNode* root, map<int, int> &count) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, count);
        count[root->val]++;
        inOrder(root->right, count);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> count;
        int max = INT_MIN;
        vector<int> res;
        inOrder(root, count);

        for (pair<int, int> item: count) {
            if (item.second > max) {
                max = item.second;
            }
        }

        for (pair<int, int> item: count) {
            if (item.second == max) {
                res.emplace_back(item.first);
            }
        }

        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
