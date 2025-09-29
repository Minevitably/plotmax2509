#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip> // 👈 加上这一行！

using namespace std;

// ===================================
// 1. 树节点定义
// ===================================
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // 析构函数：释放内存
    ~TreeNode() {
        delete left;
        delete right;
    }
};

// ===================================
// 2. 随机树生成函数
// ===================================
/**
 * 随机生成一棵二叉树
 * @param max_depth 树的最大深度
 * @param node_count 当前节点数
 * @param max_nodes 树的最大节点总数
 * @param gen 随机数生成器
 * @return 生成的树的根节点
 */
TreeNode* generateRandomTree(int max_depth, int& node_count, int max_nodes, mt19937& gen) {
    if (node_count >= max_nodes || max_depth == 0) {
        return nullptr;
    }

    uniform_real_distribution<> dist(0.0, 1.0);
    // 随机决定是否创建当前节点，控制稀疏度
    if (dist(gen) < 0.2 && node_count > 0) {
        return nullptr;
    }

    int val = uniform_int_distribution<>(1, 100)(gen); // 节点值随机
    TreeNode* root = new TreeNode(val);
    node_count++;

    // 递归创建左右子树
    root->left = generateRandomTree(max_depth - 1, node_count, max_nodes, gen);
    root->right = generateRandomTree(max_depth - 1, node_count, max_nodes, gen);

    return root;
}


// ===================================
// 3. 算法实现 (Solution A - 剪枝优化版)
// ===================================
// 这是您提供的**算法二**：在递归前检查值，可以更快剪枝。
class SolutionA {
private:
    bool isSameTree(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }
        // **剪枝点**：提前检查值，不等则立即返回
        if (root1->val != root2->val) {
            return false;
        }
        bool l = isSameTree(root1->left, root2->left);
        bool r = isSameTree(root1->right, root2->right);
        // 如果值相等，继续检查子树
        return l && r;
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

// ===================================
// 4. 算法实现 (Solution B - 无剪枝版)
// ===================================
// 这是您提供的**算法一**：值检查放在递归后，没有提前剪枝。
class SolutionB {
private:
    bool isSameTree(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }

        bool l = isSameTree(root1->left, root2->left);
        bool r = isSameTree(root1->right, root2->right);

        // **值检查点**：在递归完成后检查，即使值不等也会遍历所有节点
        return (root1->val == root2->val) && l && r;
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


// ===================================
// 5. 性能测试主函数
// ===================================
int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    // 随机数种子
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    mt19937 gen(seed);

    const int NUM_TESTS = 50;  // 运行测试的次数
    const int MAX_DEPTH = 12;  // 主树的最大深度
    const int MAX_NODES = 2048; // 主树的最大节点数

    long long time_A = 0;
    long long time_B = 0;

    cout << "--- 性能测试开始 (" << NUM_TESTS << " 次迭代) ---" << endl;

    for (int i = 0; i < NUM_TESTS; ++i) {
        // 随机生成主树 (root)
        int nodes_root = 0;
        TreeNode* root = generateRandomTree(MAX_DEPTH, nodes_root, MAX_NODES, gen);

        // 随机选择主树中的一个子节点作为子树 (subRoot)
        // 为了确保 subRoot 存在，我们用一个占位符，实际测试 isSubtree
        TreeNode* subRoot = nullptr;
        int nodes_subRoot = 0;
        // 随机生成一个较小的子树来测试
        subRoot = generateRandomTree(6, nodes_subRoot, 64, gen);

        if (root == nullptr || subRoot == nullptr) {
            // 清理并跳过本次不成功的生成
            delete root;
            delete subRoot;
            i--; // 重新计数
            continue;
        }

        // --- 运行 Solution A (剪枝优化版) ---
        auto start_A = chrono::high_resolution_clock::now();
        volatile bool res_A = SolutionA().isSubtree(root, subRoot);
        auto end_A = chrono::high_resolution_clock::now();
        time_A += chrono::duration_cast<chrono::microseconds>(end_A - start_A).count();

        // --- 运行 Solution B (无剪枝版) ---
        auto start_B = chrono::high_resolution_clock::now();
        volatile bool res_B = SolutionB().isSubtree(root, subRoot);
        auto end_B = chrono::high_resolution_clock::now();
        time_B += chrono::duration_cast<chrono::microseconds>(end_B - start_B).count();

        // 确保结果一致
        if (res_A != res_B) {
            cout << "错误：两种算法的结果不一致！" << endl;
        }

        // 内存清理
        delete root;
        delete subRoot;
    }

    cout << "--- 性能测试结果 ---" << endl;
    cout << "总测试次数: " << NUM_TESTS << endl;
    cout << "--------------------------------------" << endl;
    cout << "Solution A (剪枝优化版) 总耗时: " << time_A << " 微秒" << endl;
    cout << "Solution B (无剪枝版) 总耗时:   " << time_B << " 微秒" << endl;
    cout << "--------------------------------------" << endl;

    if (time_A < time_B) {
        double ratio = (double)time_B / time_A;
        cout << "结论：Solution A **更快**，快了约 " << fixed << setprecision(2) << ratio << " 倍。" << endl;
    } else if (time_B < time_A) {
        double ratio = (double)time_A / time_B;
        cout << "结论：Solution B **更快**（**反常**），快了约 " << fixed << setprecision(2) << " 倍。" << ratio << endl;
    } else {
        cout << "结论：两种算法速度基本一致。" << endl;
    }

    return 0;
}