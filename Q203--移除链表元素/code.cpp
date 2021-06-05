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
        if (!head)
        {
            return nullptr;
        }

        //如果头结点的值等于val，删除头结点
        while (head->val == val)
        {
            if (head->next)
            {
                ListNode *next = head->next;
                delete head;
                head = next;
            }
            else
            {
                return nullptr;
            }
        }
        ListNode *it = head;
        while (it && it->next)
        {
            if (it->next->val == val)
            {
                if (!it->next->next)
                {
                    delete it->next;
                    it->next = nullptr;
                    return head;
                }
                else
                {
                    ListNode *temp = it->next->next;
                    delete it->next;
                    it->next = temp;
                    continue;
                }
            }
            it = it->next;
        }
        return head;
    }
};

int main()
{
    cout << "hello world." << endl;
    return 0;
}