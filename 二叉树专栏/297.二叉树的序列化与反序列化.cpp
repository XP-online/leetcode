/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include <iostream>
#include <list>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string str;
    if (root) {
      str += to_string(root->val);
      str += ',';
      str += serialize(root->left);
      str += serialize(root->right);
    } else {
      str += "null";
      str += ',';
    }
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    auto it = data.begin();

    list<TreeNode*> nodelist;
    string str;
    while (it != data.end()) {
      if (*it == ',') {
        if (str == "null") {
          nodelist.push_back(nullptr);
          str.clear();
        } else {
          TreeNode* node = new TreeNode(stoi(str));
          nodelist.push_back(node);
          str.clear();
        }
      } else {
        str += *it;
      }
      it++;
    }
    TreeNode* root = buildTree(nodelist);
    return root;
  }

  TreeNode* buildTree(list<TreeNode*>& nodelist) {
    if (nodelist.begin() == nodelist.end()) {
      return nullptr;
    }
    TreeNode* node = nodelist.front();
    nodelist.pop_front();
    if (!node) return nullptr;
    node->left = buildTree(nodelist);
    node->right = buildTree(nodelist);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

int main() {
  Codec c;
  TreeNode* root = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);

  root->left = n2;
  root->right = n3;

  cout << c.serialize(root);
  return 0;
}
