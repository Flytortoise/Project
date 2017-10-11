#include "main.h"

pNode Destroy(pNode head)
{
    assert(head != NULL);

    pNode temp = head->next;
	while(temp != NULL)
	{
	    head->next = temp->next;
	    free(temp);
		temp = head->next;
	}
    
	free(head);

	return NULL;

}


