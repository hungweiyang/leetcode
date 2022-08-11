#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *partition(struct ListNode *head, int x) {
  Node *dummy = malloc(sizeof(Node));
  dummy->next = head;
  dummy->val = -200;

  Node *prev = dummy;
  Node *curr = head;

  while (curr && curr->val < x) {
    prev = curr;
    curr = curr->next;
  }

  while (curr && curr->next) {
    Node *next = curr->next;
    if (next->val < x) {
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
      prev = next;
    } else {
      curr = curr->next;
    }

    next = curr->next;
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
  InsertNode(&head, 1);
  Traverse(head);

  head = partition(head, 3);

  Traverse(head);
}