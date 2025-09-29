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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }
        bool l = isSameTree(root1->left, root2->left);
        bool r = isSameTree(root1->right, root2->right);
        return (root1->val == root2->val) && l && r;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return subRoot == nullptr;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        return l || r;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
