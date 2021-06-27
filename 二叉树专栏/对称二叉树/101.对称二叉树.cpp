/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
//迭代：层序遍历，每层用一个数组存储，双指针判断数组是否对称
//递归：双指针，一个优先入栈左指针，一个优先入栈左树，一个优先入栈右树
// @lc code=start

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
      bool ret = false;
      if (root)
      {
        ret = traver(root->left, root->right);
      }
      
      return ret;
  }

  bool traver(TreeNode* left, TreeNode* right){
      if (left == right )
      {
        return true;
      }
      if(left == nullptr || right == nullptr){
        return false;
      }
      if(left->val != right->val){
        return false;
      }
      int ret = traver(left->left, right->right);
      if(ret){
        ret = traver(left->right, right->left);
      }
      
      return ret;
  }
};
// @lc code=end
