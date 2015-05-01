class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head, q = p;
        ListNode* nHead = new ListNode(0);
        nHead->next = head;
        auto pre = nHead;
        for(int i = 0; i < n - 1; i++) {
            p = p->next;
        }
        while(p->next) {
            pre = q;
            p = p->next;
            q = q->next;
        }
        
        pre->next = q->next;
        delete q;
        
        return nHead->next;
    }
};