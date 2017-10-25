#include "Function.h"
#include "Tool.h"
#include "File.h"
#include "DynBase.h"
#include <iostream>
extern char buff[100];
extern int flag;
REGISTER_CLASS(add);
REGISTER_CLASS(change);
REGISTER_CLASS(del);
REGISTER_CLASS(destroy);
REGISTER_CLASS(rev);
REGISTER_CLASS(se);
REGISTER_CLASS(so);
REGISTER_CLASS(display);

ABFactory::~ABFactory(){}

Function *add::CreateFunction()
{
	return new Add;
}

Function *change::CreateFunction()
{
	return new Change;
}

Function *del::CreateFunction()
{
	return new Delete;
}

Function *destroy::CreateFunction()
{
	return new Destroy;
}

Function *rev::CreateFunction()
{
	return new Reverse;
}

Function *se::CreateFunction()
{
	return new Search;
}

Function *so::CreateFunction()
{
	return new Sort;
}

Function *display::CreateFunction()
{
	return new Display;
}


Function::~Function(){}

int Add::work(pNode head)
{
	assert(head != NULL);

	char buff[1024];
	memset(buff, 0,sizeof(buff));

    pNode node = new Node;
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


int Change::work(pNode head)
{
	assert(head != NULL);

    char buff[NAME_LEN];
	printf("Please input name : ");
	scanf("%s",buff);
	pNode node = Tool::Find(head, buff);

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


int Delete::work(pNode head)
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
			delete temp;
			printf("Delete Success !\n\n");
			return SUCCESS;
		}
		
		p = temp;
		temp = temp->next;
	}

	printf("No Person !\n\n");
	return FAIL;
}

int Destroy::work(pNode head)
{
    assert(head != NULL);
    File::FileClose(head, buff);
    pNode temp = head->next;
	while(temp != NULL)
	{
	    head->next = temp->next;
	   	delete temp;
		temp = head->next;
	}
    flag = 0;

	return 0;

}

int Reverse::work(pNode head)
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


int Search::work(pNode head)
{
	assert(head != NULL);
    char buff[NAME_LEN];
	printf("Please input name : ");
	scanf("%s",buff);
	pNode node = Tool::Find(head, buff);

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

int Sort::work(pNode head)
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
		Tool::swap(p,temp);
		p = p->next;
	}

	printf("Sort Success !\n\n");

}

int Display::work(pNode head)
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



