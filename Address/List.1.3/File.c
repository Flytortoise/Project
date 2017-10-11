#include "main.h"


void FileOpen(pNode head, char *filename)
{
	FILE *fp = fopen(filename,"a+");
	assert(fp != NULL);

	pNode node = NULL;
	char c;
	int flag = 0;
	int i = 0;
	int len = 0;
	char buff[1024];
	while((c = fgetc(fp)) != EOF)
	{
	     buff[i] = c;
	     if(c == '\n')
		 {
		 	 if(flag == 0)
			 {
			     len = i;
			 }

		     flag++;
			 buff[i] = '\0';
		 }

		 if(flag == 2)
		 {
		     flag = 0;
			 node = Create();
			 strcpy(node->name,buff);
			 strcpy(node->tel, buff + len + 1);
			 node->next = head->next;
			 head->next = node;
			 i = 0;			 
		 }
		 else
		 {
		     i++;
		 }

	}

	fclose(fp);

	printf("File Open Success !\n");
}

void FileClose(pNode head, char *filename)
{
	FILE *fp = fopen(filename,"w+");
	assert(fp != NULL);

	pNode temp = head->next;
	int i = 0;
	while(temp != NULL)
	{
	    i = fputs(temp->name,fp);
		fputc('\n',fp);
		fputs(temp->tel,fp);
		fputc('\n',fp);
	    temp = temp->next;
	}

	fclose(fp);
	printf("File Close Success !\n");
}

