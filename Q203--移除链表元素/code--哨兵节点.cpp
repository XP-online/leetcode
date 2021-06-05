#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        //设置哨兵节点，减少对头结点的判断
        ListNode* guardHeadNode = new ListNode(0,head);

        ListNode* it = guardHeadNode;
        while (it->next)
        {
            if(it->next->val == val){
                ListNode* temp = it->next->next;
                delete it->next;
                it->next = temp;
            }else{
                it = it->next;
            }
        }
        
        //删掉哨兵节点，返回真正的头
        head = guardHeadNode->next;
        delete guardHeadNode;
        return head;
    }
};

int main()
{
    cout << "hello world." << endl;
    return 0;
}