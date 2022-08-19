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

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  dummy->next = 0;
  struct ListNode *curr = dummy;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      curr->next = list1;
      list1 = list1->next;
    } else {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }

  curr->next = (list1) ? list1 : list2;
  curr = dummy->next;
  free(dummy);
  return curr;
}

struct ListNode *helper(struct ListNode **lists, int l, int r) {
  if (l == r)
    return lists[l];

  int m = l + (r - l) / 2;

  return mergeTwoLists(helper(lists, l, m),
                       helper(lists, m + 1, r));
}

/*
 * T(n) = 2*T(n/2) + c1k = 4*T(n/4) + c1k + c2k = ... = (logn)*k 
 */ 

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  if (listsSize == 0) return NULL;
  return helper(lists, 0, listsSize - 1);
}

void Traverse(struct ListNode *head) {
  struct ListNode *it = head;
  while (it) {
    printf("%d\n", it->val);
    it = it->next;
  }
  printf("\n");
  return;
}

int main(int argc, char *argv[]) {
  const int len = 3;
  struct ListNode **head;

  head = malloc(len * sizeof(struct ListNode *));
  for (int i = 0; i < len; i++)
    head[i] = NULL;

  InsertNode(&head[0], 1);
  InsertNode(&head[0], 3);
  InsertNode(&head[0], 5);
  InsertNode(&head[0], 7);
  InsertNode(&head[0], 9);
  Traverse(head[0]);

  InsertNode(&head[1], 2);
  InsertNode(&head[1], 4);
  InsertNode(&head[1], 6);
  InsertNode(&head[1], 8);
  InsertNode(&head[1], 10);
  Traverse(head[1]);

  InsertNode(&head[2], 5);
  InsertNode(&head[2], 5);
  InsertNode(&head[2], 5);
  InsertNode(&head[2], 5);
  InsertNode(&head[2], 5);
  Traverse(head[2]);

  Traverse(mergeKLists(head, 3));

  for (int i = 0; i < len; i++)
    free(head[i]);
  free(head);
}