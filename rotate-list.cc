class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p = head;
        if (!head || k == 0) return head;
        int j = 0;
        ListNode* pre = head;
        for(int i = 0; i < k; i++) {
            p = p->next;
            j++;
            if (!p) break;
        }
        if (!p) {
            int len = j;
            k = k % len;
            if (k == 0) return head;
            p = head;
            for(int i = 0; i < k; i++) {
                p = p->next;
            }
        }
        while(p->next) {
            p = p->next;
            pre = pre->next;
        }
        p->next = head;
        ListNode* newHead = pre->next;
        pre->next = nullptr;
        return newHead;
    }
};
