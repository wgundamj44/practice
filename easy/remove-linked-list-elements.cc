class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tHead = new ListNode(0);
        tHead->next = head;
        auto p = tHead, q = tHead->next;
        while(q != NULL) {
            if (q->val == val) {
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = p->next;
                q = q->next;
            }
            
        }
        return tHead->next;
    }
};