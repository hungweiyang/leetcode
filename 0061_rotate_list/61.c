#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode Node;
struct ListNode *rotateRight(struct ListNode *head, int k) {
  if (!head)
    return head;

  Node *fast = head, *slow = head;

  int n = 0;
  while (fast) {
    n++;
    fast = fast->next;
  }

  k %= n;
  fast = head;

  for (int i = 0; i < k; i++) {
    fast = fast->next;
  }

  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }

  fast->next = head;
  fast = slow->next;
  slow->next = NULL;

  return fast;
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