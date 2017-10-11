#include "main.h"

int Change(pNode head)
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
	    printf("Please input new name : ");
		scanf("%s",node->name);
		getchar();
		printf("Please input new tel : ");
		scanf("%s",node->tel);
		getchar();
		printf("Change Success !\n\n");
		return SUCCESS;
	}


}

