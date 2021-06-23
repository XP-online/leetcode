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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> list;
    TreeNode* lastPopNode = nullptr;
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    //前(先)序遍历入栈顺序即为输出顺序
    if (nodeStack.top()) list.push_back(nodeStack.top()->val);
    while (!nodeStack.empty()) {
      if (!nodeStack.top()) {
        while (!nodeStack.top() || nodeStack.top()->right == lastPopNode) {
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
        //前(先)序遍历入栈顺序即为输出顺序
        if (nodeStack.top()) list.push_back(nodeStack.top()->val);
        continue;
      }

      nodeStack.push(nodeStack.top()->left);
      //前(先)序遍历入栈顺序即为输出顺序
      if (nodeStack.top()) list.push_back(nodeStack.top()->val);
    }

    return list;
  }
};

int main() {
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