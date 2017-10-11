#include "main.h"


pNode Create()
{
    pNode node = (pNode)malloc(sizeof(Node));
	assert(node != NULL);
	bzero(node,sizeof(Node));
	node->next = NULL;
    return node;
}

