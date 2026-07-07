class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 0; i<=n; i++){
            fast = fast->next;
        }

        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};
