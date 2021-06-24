/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
public:
  int maxDepth(TreeNode *root) {
    int maxDepthVaule = 0;
    traver(0, maxDepthVaule, root);
    return maxDepthVaule;
  }
  void traver(int depth, int &maxDepthVaule, TreeNode *node) {
    if (!node) return;

    depth++;
    if (depth > maxDepthVaule) maxDepthVaule = depth;
    traver(depth, maxDepthVaule, node->left);
    traver(depth, maxDepthVaule, node->right);
  }
};
// @lc code=end
int main() { return 0; }