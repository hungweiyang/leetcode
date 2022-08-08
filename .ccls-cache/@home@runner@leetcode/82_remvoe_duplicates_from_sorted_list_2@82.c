#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;
struct ListNode *deleteDuplicates(struct ListNode *head) {
  Node *dummy = malloc(sizeof(Node));
  dummy->val = 0;
  dummy->next = head;

  Node *prev = dummy;
  Node *curr = prev->next;

  while (prev->next) {
    curr = prev->next;
    
    while (curr->next && curr->val == curr->next->val)
      curr = curr->next;

    if (prev->next != curr)
      prev->next = curr->next;
    else
      prev = curr;
  }

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

  head = deleteDuplicates(head);

  Traverse(head);
}