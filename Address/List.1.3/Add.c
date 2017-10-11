#include "main.h"


int Add(pNode head)
{
	assert(head != NULL);

	char buff[1024];
	memset(buff, 0,sizeof(buff));

    pNode node = Create();
	printf("Please input name :");
	scanf("%s",buff);
	assert(strlen(buff) < NAME_LEN);
	strcpy(node->name,buff);

	getchar();
	printf("Please input Tel :");
	scanf("%s",buff);
	assert(strlen(buff) < TEL_LEN);
	strcpy(node->tel,buff);

	node->next = head->next;
	head->next = node;

	printf("Add Success !\n\n");
	return SUCCESS;
}
