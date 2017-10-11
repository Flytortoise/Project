

#include "main.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
	    printf("Please input success Data !\n");
	    exit(-1);
	}
    pNode head = Create();

	FileOpen(head,argv[1]);
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
				FileClose(head, argv[1]);
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
