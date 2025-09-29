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
    bool isSameTree(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSameTree(root1->left, root2->left) &&
               isSameTree(root1->right, root2->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) {
            return subRoot == nullptr;
        }
        if (isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
