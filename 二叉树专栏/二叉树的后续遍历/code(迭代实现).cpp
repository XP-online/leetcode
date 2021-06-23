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
    TreeNode* lastPopNode = nullptr;
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    
    while (!nodeStack.empty()) {
      if (!nodeStack.top()) {
        while (!nodeStack.top() || nodeStack.top()->right == lastPopNode) {
          //后序遍历出栈顺序即为输出顺序
          if (nodeStack.top()) list.push_back(nodeStack.top()->val);
          lastPopNode = nodeStack.top();
          nodeStack.pop();
          if (nodeStack.empty()) {
            break;
          }
        }
        if (nodeStack.empty()) {
          break;
        }
        nodeStack.push(nodeStack.top()->right);
        continue;
      }

      nodeStack.push(nodeStack.top()->left);
    }

    return list;
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