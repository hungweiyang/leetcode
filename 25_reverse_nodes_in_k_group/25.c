#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k) {

  struct ListNode **p1 = &head;
  struct ListNode **p2 = malloc(sizeof(struct ListNode *) * k);

  for (; *p1;) {
    int i;
    struct ListNode *it = *p1;
    for (i = 0; i < k && it; i++) {
      p2[i] = it;
      it = it->next;
    }

    if (i < k)
      break;

    *p1 = p2[k - 1];
    p2[0]->next = p2[k - 1]->next;
    for (i = k - 1; i >= 1; i--) {
      p2[i]->next = p2[i - 1];
    }
    p1 = &p2[0]->next;
  }

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
  InsertNode(&head, 4);
  InsertNode(&head, 5);

  Traverse(head);

  head = reverseKGroup(head, 5);

  Traverse(head);
}