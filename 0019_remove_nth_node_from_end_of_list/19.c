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
  return;
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  dummy->next = head;
  struct ListNode *slow = dummy, *fast = dummy;
  for (int i = 0; i < n; i++)
    fast = fast->next;

  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
  }

  slow->next = slow->next->next;
  return dummy->next;
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

  head = removeNthFromEnd(head, 5);

  Traverse(head);
}