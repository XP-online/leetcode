/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include <iostream>
#include <map>
#include <set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return root;
    map<TreeNode*, TreeNode*> parentMap;
    bool findp = false;
    bool findq = false;
    dfs(parentMap, root, p, q, findp, findq);

    set<TreeNode*> plist;
    set<TreeNode*> qlist;
    TreeNode* it = p;
    while (it) {
      plist.insert(it);
      if (parentMap.find(it) != parentMap.end()) {
        it = parentMap[it];
      } else {
        break;
      }
    }
    it = q;
    while (it) {
      qlist.insert(it);
      if (parentMap.find(it) != parentMap.end()) {
        it = parentMap[it];
      } else {
        break;
      }
    }
    decltype(plist.cend()) itt = plist.cend();
    itt--;
    while (itt != plist.cbegin()) {
      if (qlist.find(*itt) != qlist.cend()) {
        break;
      }
      itt--;
    }

    return *itt;
  }

  void dfs(map<TreeNode*, TreeNode*>& parentMap, TreeNode* node, TreeNode* p, TreeNode* q,
           bool& findp, bool& findq) {
    //寻找p
    if (node->left == p) {
      findp = true;
    }
    if (node->right == p) {
      findp = true;
    }
    //寻找q
    if (node->left == q) {
      findq = true;
    }
    if (node->right == q) {
      findq = true;
    }
    //构建父节点map
    if (node->left) {
        parentMap[node->left] = node;  //构建父节点map
      }
      if (node->right) {
        parentMap[node->right] = node;  //构建父节点map
      }
    //遍历左右节点
    if (!findq || !findp) {
      if (node->left) {
        dfs(parentMap, node->left, p, q, findp, findq);
      }
      if (node->right) {
        dfs(parentMap, node->right, p, q, findp, findq);
      }
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  TreeNode* root = new TreeNode(3);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);

  root->left = n5;
  root->right = n1;
  n1->left = n2;
  auto out = s.lowestCommonAncestor(root, n1, n2);
  cout<<out->val;
  return 0;
}
