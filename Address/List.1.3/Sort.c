#include "main.h"

int Sort(pNode head)
{
    assert(head != NULL);

	pNode temp = NULL;
	pNode q = NULL;
    pNode p = head->next;
    while(p != NULL)
	{
		temp = p;
		for(q = p->next; q != NULL; q = q->next)
		{ 
		    if(strcmp(temp->name, q->name) > 0)
			{
				temp = q;
			}
		}
		swap(p,temp);
		p = p->next;
	}

	printf("Sort Success !\n\n");

}

