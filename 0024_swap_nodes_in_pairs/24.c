
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *it) {
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  struct ListNode *prev = dummy;
  struct ListNode *next;

  while (it) {
    next = it->next;

    if (!next)
      break;

    it->next = next->next;
    next->next = it;
    prev->next = next;
    prev = it;
    it = it->next;
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
  InsertNode(&head, 2);
  InsertNode(&head, 3);
  InsertNode(&head, 4);
  InsertNode(&head, 5);
  Traverse(head);

  printf("----\n");
  head = swapPairs(head);
  Traverse(head);
}