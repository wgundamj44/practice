class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        
        auto nHead = new ListNode(0);
        nHead->next = head;
        auto p = head, q = p->next, pre = nHead;
        
        while (q != nullptr) {
            auto tmp = q->next;
            pre->next = q;
            q->next = p;
            pre = p;
            p = tmp;
            if (p == nullptr) {
                break;
            }
            q = p->next;
        }
        pre->next = p;
        
        return nHead->next;
    }
};