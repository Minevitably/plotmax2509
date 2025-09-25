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
    void inOrder(TreeNode* root, vector<int> &nodes) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, nodes);
        nodes.emplace_back(root->val);
        inOrder(root->right, nodes);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        int min = INT_MAX;
        for (int i = 0; i < nodes.size() - 1; i++) {
            int val = abs(nodes[i + 1] - nodes[i]);
            if (val < min) {
                min = val;
            }
        }
        return min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
