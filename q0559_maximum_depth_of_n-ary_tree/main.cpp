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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        for (int i = 0; i < (root->children).size(); i++) {
            depth = std::max(maxDepth(root->children[i]), depth);
        }
        return depth + 1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
