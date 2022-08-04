#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

void InsertNode(struct ListNode **phead, int val)
{
	struct ListNode **it = phead;
	while (*it)
		it = &((*it)->next);

	*it = malloc(sizeof(struct ListNode));
	(*it)->val = val;
	(*it)->next = NULL;

}

void Traverse(struct ListNode *head)
{
	struct ListNode *it = head;
	while (it)
	{
		printf("%d\n", it->val);
		it = it->next;
	}
	return;
}

struct ListNode *Reverse(struct ListNode *head)
{
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *curr = head;
    
    while (curr)
    {
        curr->next;
    }
}

int main(int argc, char *argv[])
{
	struct ListNode *head = NULL;

	InsertNode(&head, 1);
	InsertNode(&head, 2);
	InsertNode(&head, 3);
	InsertNode(&head, 4);
	InsertNode(&head, 5);
	Traverse(head);

	head = Reverse(head);
	Traverse(head);
}