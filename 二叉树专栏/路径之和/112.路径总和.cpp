/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include <map>

using namespace std;

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
  bool hasPathSum(TreeNode *root, int targetSum) {
    bool ret = false;
    if (root) {
      ret = traver(targetSum, 0, root);
    }

    return ret;
  }
  bool traver(const int &targetSum, int sum, TreeNode *node) {
    if (!node) {
       return false;
    }
    sum = node->val + sum;
    if(sum == targetSum && !node->left && !node->right) return true; 
    bool ret = traver(targetSum, sum, node->left);
    if (!ret) {
      ret = traver(targetSum, sum, node->right);
    }
    return ret;
  }
};
// @lc code=end

int main(){

}