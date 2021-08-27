/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */


#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// @lc code=start


class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;

        bfs(root);
        return root;
    }

    void bfs(Node* header){
        Node* firstNode = header;
        Node* parent = header;
        while (parent)
        {
            if(parent->left){
                parent->left->next = parent->right;
            }
            if(parent->right && parent->next){
                parent->right->next = parent->next->left;
            }
            parent = parent->next;
        }
        if(firstNode->left){
            bfs(firstNode->left);
        }
    }
};
// @lc code=end

int main() {
  Solution s;
  return 0;
}