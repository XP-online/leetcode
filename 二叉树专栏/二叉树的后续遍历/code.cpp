#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        traver(list,root);
        return list;
    }
    void traver(vector<int>& list, TreeNode* node){
        if(!node){
            return;
        }
        traver(list, node->left);
        traver(list, node->right);
        list.push_back(node->val);
    }
};

int main() {
  TreeNode left2(3);
  TreeNode right1(2, &left2, nullptr);

  TreeNode root(1, nullptr, &right1);
  Solution s;
  vector<int> list = s.postorderTraversal(&root);

  for (int i = 0; i < list.size(); i++) {
    cout << list.at(i) << " ";
  }
  return 0;
}