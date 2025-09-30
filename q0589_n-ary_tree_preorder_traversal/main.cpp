#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void doPreOrder(Node *root, vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        ans.emplace_back(root->val);
        for (Node *item: root->children) {
            doPreOrder(item, ans);
        }
    }

public:
    vector<int> preorder(Node *root) {
        vector<int> ans;
        doPreOrder(root, ans);
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
