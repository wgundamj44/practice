class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    auto oddHead = head;
    if (head == nullptr) return head;
    auto evenHead = head->next;
    auto p1 = oddHead, p2 = evenHead;
    while(p2 && p2->next) {
      p1->next = p2->next;
      p1 = p1->next;
      p2->next = p1->next;
      p2 = p2->next;
    }
    p1->next = evenHead;
    return oddHead;
  }
};
