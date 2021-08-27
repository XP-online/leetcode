/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
        Node* parent = header;
        Node  firstNode;
        Node* last = &firstNode;
        while (parent)
        {
           if (parent->left)
           {
               last->next = parent->left;
               last = parent->left;
           }
           if(parent->right){
               last->next = parent->right;
               last = parent->right;
           }
           parent = parent->next;
        }
        if(firstNode.next){
            bfs(firstNode.next);
        }
    }
};
// @lc code=end

int main() {
  Solution s;
  return 0;
}