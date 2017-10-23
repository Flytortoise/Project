#ifndef DATA_H_
#define DATA_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define TEL_LEN 12
#define MAX_LEN 100
#define SUCCESS 0
#define FAIL 1

class Node
{
public :
	Node();
	char name[NAME_LEN];
	char tel[TEL_LEN];
	Node *next;
};

typedef Node * pNode;

#endif 
