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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> list;
    TreeNode* lastPopNode = nullptr;
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
      if (!nodeStack.top()) {
        while (!nodeStack.top() || nodeStack.top()->right == lastPopNode) {
          //这里为了防止一个节点左右节点都为空时，左侧空节点出栈，被判断成右节点出栈。根节点直接退出没有输出的情况
          if (nodeStack.top() && !nodeStack.top()->left &&
              !nodeStack.top()->right) {
            list.push_back(nodeStack.top()->val);
          }
          lastPopNode = nodeStack.top();
          nodeStack.pop();
          if (nodeStack.empty()) {
            break;
          }
        }
        if (nodeStack.empty()) {
          break;
        }
        list.push_back(
            nodeStack.top()->val);  //中序遍历，右节点入站前输出当前节点
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
  vector<int> list = s.inorderTraversal(&root);

  for (int i = 0; i < list.size(); i++) {
    cout << list.at(i) << " ";
  }
  return 0;
}