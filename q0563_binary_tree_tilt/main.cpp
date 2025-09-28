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
    int sumOfTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = root->val;
        sum += sumOfTree(root->left);
        sum += sumOfTree(root->right);
        return sum;
    }
public:
    int findTilt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = abs(sumOfTree(root->left) - sumOfTree(root->right));
        sum += findTilt(root->left) + findTilt(root->right);
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
