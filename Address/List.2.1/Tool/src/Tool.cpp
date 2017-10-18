#include "Tool.h"

void Tool::swap(pNode node1, pNode node2)
{
    assert(node1 != NULL);
	assert(node2 != NULL);

    char buff[MAX_LEN];
	memset(buff,0,sizeof(buff));
	strcpy(buff, node2->name);
	strcpy(node2->name,node1->name);
	strcpy(node1->name,buff);
	
	strcpy(buff, node2->tel);
	strcpy(node2->tel,node1->tel);
	strcpy(node1->tel,buff);
}


pNode Tool::Find(pNode head, char *str)
{
    assert(head != NULL);
	pNode temp = head->next;
	while(temp != NULL)
	{
	    if(strcmp(temp->name,str) == 0)
		{
		    return temp;
		}
	    temp = temp->next;
	}
	printf("No Find!\n\n");
	return NULL;
}


