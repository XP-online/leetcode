#include <iostream>
#include <vector>
/**
 * Definition for singly-linked list.
 **/
 struct ListNode {

    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* p = nullptr;
        ListNode* ret = nullptr;

        int tmp = 0;
        int curVal = 0;
        int nextVal = 0;

        while(l1 != nullptr || l2 != nullptr || nextVal != 0){

            tmp = 0;

            if(l1 != nullptr){
                tmp += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                tmp += l2->val;
                l2 = l2->next;
            }

            tmp += nextVal;
            curVal = tmp % 10;
            nextVal = tmp / 10;
            
            if(p == nullptr) {
                p = new ListNode(curVal);
                ret = p;
            } else {
                p->next = new ListNode(curVal);
                p = p->next;
            }
            
        }
        return ret;
    }
};

int main(){
    //Solution sol;
    //std::vector<int> l1,l2;
    return 0;
}