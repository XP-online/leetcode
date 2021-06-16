#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
    : val(0)
    , left(nullptr)
    , right(nullptr)
  {
  }
  TreeNode(int x)
    : val(x)
    , left(nullptr)
    , right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x)
    , left(left)
    , right(right)
  {
  }
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> list;
    //list.clear();
    traverse(list, root);
    return list;
  }
  void traverse(vector<int>& list, TreeNode* node) {
    if (!node) { return; }
    list.push_back(node->val);
    traverse(list, node->left);
    traverse(list, node->right);
  }
};

int main()
{
  TreeNode left2(3);
  TreeNode right1(2, &left2, nullptr);

  TreeNode root(1, nullptr, &right1);
  Solution s;
  vector<int> list = s.preorderTraversal(&root);

  for (int i = 0; i < list.size(); i++) {
    cout << list.at(i) << " ";
  }
  return 0;
}