/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    
    struct ListNode **p= &head;
    
    for (; *p;)
    {
        struct ListNode *first = *p;
        struct ListNode *second = (*p)->next;
        if (!second)
            break;
        struct ListNode *third = (*p)->next->next;
        
        *p = second;
        first->next = third;
        second->next = first;
        p = &first->next;
    }
    
    return head;

}