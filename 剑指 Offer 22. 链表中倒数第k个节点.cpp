
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* index = head;
    ListNode* ret = nullptr;
    while (index != nullptr) {
      if (k == 1) {
        ret = head;
        index = index->next;
        break;
      }
      k--;
      index = index->next;
    }
    while (index != nullptr) {
      index = index->next;
      ret = ret->next;
    }
    return ret;
  }
};

int main(){
  return 0;
}