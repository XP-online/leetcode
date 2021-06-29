/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <vector>

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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *root =
        createSubTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    return root;
  }
  TreeNode *createSubTree(vector<int> &inorder, vector<int> &postorder, int inorderStartIndex,
                          int inorderEndIndex, int postorderStartIndex, int postorderEndIndex) {
    if (postorder.size() < postorderEndIndex || inorder.size() < inorderEndIndex)
      return nullptr;  //异常判断：坐标越界

    //在中序遍历表中找到根节点
    int rootIndex = -1;
    for (int i = inorderStartIndex; i <= inorderEndIndex; i++) { 
      if (postorder[i] == postorder[postorderEndIndex]) {
        rootIndex = i;
        break;
      }
    }
    if (rootIndex == -1) return nullptr;  //异常判断：未找到

    TreeNode *root = new TreeNode(postorder[postorderEndIndex]);  //构建根节点

    int leftsize = rootIndex - inorderStartIndex;
    int rightsize = inorderEndIndex - rootIndex;

    if (leftsize > 0) {
      root->left = createSubTree(inorder, postorder, inorderStartIndex, rootIndex - 1,
                                 postorderStartIndex, postorderEndIndex - rightsize - 1);
    }
    if (rightsize > 0) {
      root->right = createSubTree(inorder, postorder, rootIndex + 1, inorderEndIndex,
                                  postorderStartIndex + leftsize, postorderEndIndex - 1);
    }
    return root;
  }
};
// @lc code=end
