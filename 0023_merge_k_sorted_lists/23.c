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

/*
 * T(n) = T(n-1) + c1k = T(n-2) + c1k + c2k = ... = nk 
 */ 

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  if (listsSize == 0)
    return NULL;
  else if (listsSize == 1)
    return lists[0];
  else
    return mergeTwoLists(mergeKLists(lists, listsSize - 1),
                         lists[listsSize - 1]);
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

  // head = malloc(len * sizeof(struct ListNode *));
  // for (int i = 0; i < len; i++)
  //   head[i] = NULL;

  head = NULL;

  // InsertNode(&head[0], 1);
  // InsertNode(&head[0], 3);
  // InsertNode(&head[0], 5);
  // InsertNode(&head[0], 7);
  // InsertNode(&head[0], 9);
  // Traverse(head[0]);

  // InsertNode(&head[1], 2);
  // InsertNode(&head[1], 4);
  // InsertNode(&head[1], 6);
  // InsertNode(&head[1], 8);
  // InsertNode(&head[1], 10);
  // Traverse(head[1]);

  // InsertNode(&head[2], 5);
  // InsertNode(&head[2], 5);
  // InsertNode(&head[2], 5);
  // InsertNode(&head[2], 5);
  // InsertNode(&head[2], 5);
  // Traverse(head[2]);

  Traverse(mergeKLists(head, 0));

  // for (int i = 0; i < len; i++)
  //   free(head[i]);
  free(head);
}