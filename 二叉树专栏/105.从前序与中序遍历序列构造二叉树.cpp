/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root =
        createSubTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    return root;
  }

  TreeNode* createSubTree(vector<int>& preorder, vector<int>& inorder, int preStartIndex,
                          int preEndIndex, int inStartIndex, int inEndIndex) {
    //在中序遍历中查找根节点
    int rootIndex = -1;
    for (int i = inStartIndex; i <= inEndIndex; i++) {
      if (inorder[i] == preorder[preStartIndex]) {
        rootIndex = i;
        break;
      }
    }
    if (rootIndex == -1)
    {
        return nullptr;
    }
    
    int leftsize = rootIndex - inStartIndex;
    int rightsize = inEndIndex - rootIndex;

    TreeNode* root = new TreeNode(preorder[preStartIndex]);
    if(leftsize > 0){
        root->left = createSubTree(preorder, inorder, preStartIndex + 1, preStartIndex + leftsize ,inStartIndex, rootIndex -1);
    }
    if(rightsize > 0){
        root->right = createSubTree(preorder, inorder, preStartIndex + leftsize + 1, preEndIndex, rootIndex + 1, inEndIndex);
    }
    //
    return root;
  }
};
// @lc code=end
int main() {
  Solution s;
  vector<int> preorder = {3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7};
  TreeNode *root = s.buildTree(preorder, inorder);
  return 0;
}
