#include "ListNode.h"
using namespace std;

// class Solution {
// public:
//   ListNode* partition(ListNode* head, int x) {
//     ListNode* dummy = new ListNode(0);
//     ListNode* p = head, *p1 = dummy, *pre = dummy;
//     dummy->next = head;
//     while(p) {
//       if (p->val >= x) {
// 	p = p->next;
// 	pre = pre->next;
//       } else {
// 	if (p == p1->next) {
// 	  pre = pre->next;
// 	  p = p->next;
// 	  p1 = p1->next;
// 	} else {
// 	  pre->next = p->next;
// 	  auto tmp = p1->next;
// 	  p1->next = p;
// 	  p->next = tmp;
// 	  p = pre->next;
// 	  p1 = p1->next;
// 	}
//       }
//     }
//     return dummy->next;
//   }
// };


class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode lHead(0), rHead(0);
    ListNode* p = head, *p1 = &lHead, *p2 = &rHead;
    while(p) {
      if (p->val < x) {
        p1->next = p;
        p1 = p1->next;
      } else {
        p2->next = p;
        p2 = p2->next;
      }
      p = p->next;
    }
    p2->next = nullptr;
    p1->next = rHead.next;
    return lHead.next;
  }
};
