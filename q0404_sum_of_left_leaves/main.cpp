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
    bool isLeaf(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        return root->left == nullptr && root->right == nullptr;
    }
    void preOrder(TreeNode* root, int &sum) {
        if (root == nullptr) {
            return;
        }
        if (!isLeaf(root) && isLeaf(root->left)) {
            sum += root->left->val;
        }
        preOrder(root->left, sum);
        preOrder(root->right, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preOrder(root, sum);
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
