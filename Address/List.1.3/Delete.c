#include "main.h"

int Delete(pNode head)
{
	assert(head != NULL);

    char buff[NAME_LEN];
    printf("Please input Delete name : ");
	scanf("%s",buff);
	getchar();

	pNode temp = head->next;
	pNode p = head;
	while(temp != NULL)
	{
	    
	    if(strcmp(buff,temp->name) == 0)
		{
		    p->next = temp->next;
			free(temp);
			printf("Delete Success !\n\n");
			return SUCCESS;
		}
		
		p = temp;
		temp = temp->next;
	}

	printf("No Person !\n\n");
	return FAIL;
}

