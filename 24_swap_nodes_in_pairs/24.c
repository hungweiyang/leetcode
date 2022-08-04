/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode **p1 = &head;
    struct ListNode **p2 = malloc(sizeof(struct ListNode*) * 2); 

    for (; *p1;)
    {
        p2[0] = *p1;
        p2[1] = (*p1)->next;
        if (!p2[1])
            break;
        
        *p1 = p2[1];
        p2[0]->next = p2[1]->next;
        p2[1]->next = p2[0];
        p1 = &p2[0]->next;
    }
    
    return head;
}