#include "main.h"

int Display(pNode head)
{
    assert(head != NULL);
    pNode temp = head->next;
	while(temp != NULL)
	{
	    printf("Name : %s \nTel : %s\n\n",temp->name,temp->tel);
		temp = temp->next;
	}

	return SUCCESS;
}

