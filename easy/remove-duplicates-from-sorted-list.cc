#include "../ListNode.h"
using namespace std;

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) return NULL;
    
    auto dummy = new ListNode(-1);
    dummy->next = head;
    auto p = head;
    while(p) {
      auto p1 = p->next;
      while(p1 && p1->val == p->val) {
	auto tmp = p1;
	p1 = p1->next;
	p->next = p1;
	delete tmp;
      }
      p = p1;
    }

    auto ret = dummy->next;
    delete dummy;
    return ret;
  }
};
