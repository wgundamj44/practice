#include "ListNode.h"
using namespace std;

// class Solution {
//   //check, quick sort
// public:
//   ListNode* sortList(ListNode* head) {
//     return sort(head, nullptr);
//   }

//   ListNode* sort(ListNode* head, ListNode* tail) {
//     if (head == tail || head->next == tail) return head;
//     ListNode dummy1(0), dummy2(0);
//     ListNode* p1 = &dummy1, *p2 = &dummy2;
//     ListNode* p = head->next;
//     while(p != tail) {
//       if (p->val <= head->val) {
//         p1->next = p;
//         p1 = p;
//       } else {
//         p2->next = p;
//         p2 = p;
//       }
//       p = p->next;
//     }
//     p1->next = head;
//     p2->next = tail;
//     auto left = sort(dummy1.next, head);
//     auto right = sort(dummy2.next, tail);
//     head->next = right;
//     return left;
//   }
// };

//check: merge sort
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p1 = head, *p2 = head;
    while(p2->next && p2->next->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }
    ListNode* p3 = p1->next;
    p1->next = nullptr;
    return mergeSort(sortList(head), sortList(p3));
  }

  ListNode* mergeSort(ListNode* h1, ListNode* h2) {
    ListNode* p1 = h1, *p2 = h2;
    ListNode dummy(0);
    ListNode* p = &dummy;
    while(p1 && p2) {
      if (p1->val <= p2->val) {
        p->next = p1;
        p = p->next;
        p1 = p1->next;
      } else {
        p->next = p2;
        p = p->next;
        p2 = p2->next;
      }
    }
    p->next = p1 ? p1 : p2;
    return dummy.next;
  }
};

int main() {
  Solution s;
  vector<int> t = {1, 1, 2, 2, 3, 3, 2, 2, 3, 3,1};
  ListNode* dummy = new ListNode(0);
  ListNode* pre = dummy;
  for(auto v: t) {
    ListNode* p1 = new ListNode(v);
    pre->next = p1;
    pre = pre->next;
  }
  auto p = s.sortList(dummy->next);
  while(p) {
    cout << p->val << endl;
    p = p->next;
  }
  
}
