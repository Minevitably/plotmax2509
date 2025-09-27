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

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
private:
    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(height(root->left), height(root->right)) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int diameter = height(root->left) + height(root->right);
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        diameter = std::max(diameter, l);
        diameter = std::max(diameter, r);
        return diameter;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
