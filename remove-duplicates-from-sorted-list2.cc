#include "ListNode.h"
using namespace std;

// class Solution {
// public:
//   ListNode* deleteDuplicates(ListNode* head) {
//     if (head == NULL) return head;
//     auto dummy = new ListNode(-1);
//     dummy->next = head;
//     auto p = head, pre = dummy;

//     while(p) {
//       bool dup = false;
//       auto p1 = p->next;
//       while(p1 && p1->val == p->val) {
// 	auto tmp = p1;
// 	p1 = p1->next;
// 	p->next = p1;
// 	delete tmp;
// 	dup = true;
//       }
//       if (dup) {
// 	pre->next = p1;
// 	delete p;
// 	p = p1;
//       } else {
// 	pre = p;
// 	p = p->next;
//       }
//     }
//     auto ret = dummy->next;
//     delete dummy;
//     return ret;
//   }
// };

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre = &dummy, *p = head;
    while(p) {
      ListNode* p1=  p->next;
      for(; p1; p1 = p1->next) {
        if (p1->val != p->val) break;
      }
      if (p1 != p->next) {
        while(p != p1) {
          ListNode* next = p->next;
          delete p;
          p = next;
        }
        pre->next = p;
      } else {
        pre = pre->next;
        p = p->next;
      }
    }
    return dummy.next;
  }
};
