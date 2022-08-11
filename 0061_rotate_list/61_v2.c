#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;
struct ListNode *rotateRight(struct ListNode *head, int k) {
  if (!head) return head;
  
  Node *p = head;
  int n = 1;
  while (p->next) {
    p = p->next;
    n++;
  }

  p->next = head;

  n = n - (k % n);

  for (int i = 0; i < n; i++) {
    p = p->next;
  }

  head = p->next;
  p->next = NULL;

  return head;
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
  InsertNode(&head, 2);
  InsertNode(&head, 3);

  Traverse(head);

  head = rotateRight(head, 4);

  Traverse(head);
}