class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(!list1 || !list2) return list1? list1 : list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        
        while(list1 && list2){
        if(list2->val <= list1->val){
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
        else{
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        }
        tail->next = list1? list1 : list2;
        return dummy->next;
    }
};
