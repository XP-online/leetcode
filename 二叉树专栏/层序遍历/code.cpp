#include <iostream>
#include <queue>
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

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> list;
    if (!root) return list;
    queue<vector<TreeNode *>> traverqueue;
    vector<TreeNode *> firstLayerList;

    firstLayerList.push_back(root);
    traverqueue.push(firstLayerList);

    while (!traverqueue.empty()) {
      auto topLayerNodes = traverqueue.front();
      traverqueue.pop();

      vector<int> topLayerValues;
      vector<TreeNode *> nextLayer;
      for (int i = 0; i < topLayerNodes.size(); i++) {
        topLayerValues.push_back(topLayerNodes[i]->val);

        if (topLayerNodes[i]->left) nextLayer.push_back(topLayerNodes[i]->left);
        if (topLayerNodes[i]->right) nextLayer.push_back(topLayerNodes[i]->right);
      }

      list.push_back(topLayerValues);
      if (!nextLayer.empty()) traverqueue.push(nextLayer);
    }

    return list;
  }
};

int main() {
  TreeNode left2(3);
  TreeNode right1(2, &left2, nullptr);

  TreeNode root(1, nullptr, &right1);
  Solution s;
  vector<vector<int>> list = s.levelOrder(&root);

  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list[i].size(); j++) {
      cout << list[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}