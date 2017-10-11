#include "main.h"

int Search(pNode head)
{
	assert(head != NULL);
    char buff[NAME_LEN];
	printf("Please input name : ");
	scanf("%s",buff);
	pNode node = Find(head, buff);

	if(node == NULL)
	{
	    return FAIL;
	}
	else
	{
	    printf("Name : %s \nTel : %s\n\n",node->name,node->tel);
		return SUCCESS;
	}


}

