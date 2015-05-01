#include "../TreeNode.h"
using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto p1 = l1, p2 = l2;
        
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        
        int carry = 0;
        while(p1 || p2) {
            int val1 = p1  ? p1->val : 0;
            int val2 = p2  ? p2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum >= 10 ? sum - 10 : sum;
            auto t = new ListNode(sum);
            p->next = t;
            p = t;
            p1 = p1 ? p1->next : nullptr;
            p2 = p2 ? p2->next : nullptr;
        }
        
        
        if(carry > 0) {
            p->next = new ListNode(carry);
        }
        
        return head->next;
    }
};
