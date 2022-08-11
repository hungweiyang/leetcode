#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;

void reverse(Node *last, Node *next)
{
    Node *prev = last->next;
    Node *curr = prev->next;
    
    while (curr != next) {
        prev->next = curr->next;
        curr->next = last->next;
        last->next = curr;
        curr = prev->next;
    }
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    
  
    Node *dummy = malloc(sizeof(Node));
    dummy->next = head;
    
    Node *prev = dummy, *next = dummy;
    
    for (int i = 0; i < left-1; i++)
        prev = prev->next;
    
    for (int i = 0; i < right+1; i++)
        next = next->next;
    
    reverse(prev, next);
    
    return dummy->next;
}
void InsertNode(struct ListNode **phead, int val) {
  struct ListNode **it = phead;
  while (*it)
    it = &((*it)->next);

  *it = malloc(sizeof(struct ListNode));
  (*it)->val = val;
  (*it)->next = NULL;
  return;
}

void Traverse(struct ListNode *head) {
  struct ListNode *it = head;
  while (it) {
    printf("%d\n", it->val);
    it = it->next;
  }
  return;
}

int main(int argc, char *argv[]) {
  struct ListNode *head = NULL;
  InsertNode(&head, 1);
  Traverse(head);

  head = reverseBetween(head, 1, 1);

  Traverse(head);
}