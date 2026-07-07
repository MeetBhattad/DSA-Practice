class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int x = (l1)? l1->val: 0;
            int y = (l2)? l2->val: 0;

            int sum = x + y + carry;
            carry = sum/10;
            int digit = sum % 10;

            temp->next = new ListNode(digit);
            temp = temp->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
