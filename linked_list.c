#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;

void InsertNode(struct ListNode **phead, int val) {
  struct ListNode **it = phead;
  while (*it)
    it = &((*it)->next);

  *it = malloc(sizeof(struct ListNode));
  (*it)->val = val;
  (*it)->next = NULL;
}

void Traverse(struct ListNode *head) {
  struct ListNode *it = head;
  while (it) {
    printf("%d\n", it->val);
    it = it->next;
  }
  return;
}

struct ListNode *BubbleSort(Node *curr) {
  Node *prev, *next;
  Node *dummy = malloc(sizeof(Node));
  dummy->next = curr;

  int len = 0;
  while (curr) {
    len++;
    curr = curr->next;
  }

  for (int i = 0; i < len; i++) {
    prev = dummy;

    for (int j = 0; j < len - i - 1; j++) {
      curr = prev->next;
      next = curr->next;
      if (curr->val > next->val) {
        curr->next = next->next;
        prev->next = next;
        next->next = curr;
      }
      prev = prev->next;
    }
  }

  return dummy->next;
}

struct ListNode *Reverse(Node *it) {
  Node *prev = NULL, *next;

  while (it) {
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
  }

  return prev;
}

int main(int argc, char *argv[]) {
  struct ListNode *head = NULL;

  InsertNode(&head, 5);
  InsertNode(&head, 4);
  InsertNode(&head, 3);
  InsertNode(&head, 2);
  InsertNode(&head, 1);
  Traverse(head);

  head = BubbleSort(head);
  Traverse(head);
}