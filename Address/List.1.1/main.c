#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define TEL_LEN 12
#define MAX_LEN 100
#define SUCCESS 0
#define FAIL 1

typedef struct node
{
    char name[NAME_LEN];
	char tel[TEL_LEN];
	struct node *next;
}Node, *pNode;

int Add(pNode head);
int Delete(pNode head);
int Change(pNode head);
int Search(pNode head);
pNode Find(pNode head, char *str);
int Display(pNode head);
int Sort(pNode head);
int Reverse(pNode head);
pNode Destroy(pNode head);

void swap(pNode node1, pNode node2);
void Interface();
pNode Create();

int main()
{
    pNode head = Create();
	int flag = 1;
	while(flag)
	{
	    Interface();
		scanf("%d",&flag);
		switch(flag)
		{
		    case 1:
				Add(head);
				break;
		    case 2:
				Delete(head);
				break;
		    case 3:
				Change(head);
				break;
		    case 4:
				Search(head);
				break;
		    case 5:
				Display(head);
				break;
		    case 6:
				Sort(head);
				break;
		    case 7:
				Reverse(head);
				break;
		    case 8:
				head = Destroy(head);
				flag = 0;
				printf("Exit Success !\n");
				break;
			default :
				flag = 1;
				printf("Please input success number !\n");
				break;
		}

	}


    return 0;
}

pNode Create()
{
    pNode node = (pNode)malloc(sizeof(Node));
	assert(node != NULL);
	bzero(node,sizeof(Node));
	node->next = NULL;
    return node;
}


void Interface()
{
    printf("+-----------------------------+\n");
	printf("|       Address     List      |\n");
	printf("+-----------------------------+\n");
	printf("| 1. Add        | 2. Delete   |\n");
	printf("| 3. Change     | 4. Search   |\n");
	printf("| 5. Display    | 6. Sort     |\n");
	printf("| 7. Reverse    | 8. Exit     |\n");
	printf("+-----------------------------+\n");
	printf("Please input number :");
}

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

pNode Find(pNode head, char *str)
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

void swap(pNode node1, pNode node2)
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
