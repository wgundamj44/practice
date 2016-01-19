#include "ListNode.h"
using namespace std;

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre, *last, *p = dummy;
    int i = 0;
    while(i <= n) {
      if (i == m - 1) {
	pre = p;
      }
      if (i == n) {
	last = p;
      }
      p = p->next;
      i++;
    }
    p = pre->next;
    while(p != last) {
      auto tmp = last->next;
      pre->next = p->next;
      last->next = p;
      p->next = tmp;
      p = pre->next;
    }
    pre->next = last;

    return dummy->next;
  }
};
