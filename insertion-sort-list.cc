class Solution {
public:
  //check
  ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* p = head->next;
    ListNode* pre = head;
    while(p) {
      ListNode* p1 = &dummy;
      ListNode* next = p->next;
      while(p->val >= p1->next->val && p1->next != p) p1 = p1->next;
      if (p1->next != p) {
        ListNode* tmp = p1->next;
        p1->next = p;
        p->next = tmp;
        pre->next = next;
      } else {
        pre = p;
      }
      p = next;
    }
    return dummy.next;
  }
};
