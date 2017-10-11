#include "main.h"

int Reverse(pNode head)
{
	assert(head != NULL);

    pNode r;
    pNode p = head;
	pNode q = head->next;

	if(q != NULL)
	{
	    r = q->next;
		q->next = NULL;
		p = q;
		q = r;
	}
	else
	{
	    printf("Reverse Success !\n\n");
	    return SUCCESS;
	}
	
	while(q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;

	printf("Reverse Success !\n\n");
	return SUCCESS;
}

