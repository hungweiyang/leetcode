#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *ReverseOneGroup(Node *prev, Node *next) {
  struct ListNode *last = prev->next, *curr = last->next;
  while (curr != next) {
    last->next = curr->next;
    curr->next = prev->next;
    prev->next = curr;
    curr = last->next;
  }

  return last;
}

struct ListNode *reverseKGroup(struct ListNode *curr, int k) {
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  dummy->next = curr;
  dummy->val = -1;

  struct ListNode *prev = dummy;

  for (int i = 1; curr; i++) {
    if ((i % k) == 0) {
      prev = ReverseOneGroup(prev, curr->next);
      curr = prev->next;
    } else {
      curr = curr->next;
    }
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
  // InsertNode(&head, 1);
  // InsertNode(&head, 2);
  // InsertNode(&head, 3);
  // InsertNode(&head, 4);
  // InsertNode(&head, 5);

  Traverse(head);

  head = reverseKGroup(head, 5);

  Traverse(head);
}