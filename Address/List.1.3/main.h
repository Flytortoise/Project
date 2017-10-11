#ifndef MAIN_H_
#define MAIN_H_

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

void FileOpen(pNode head, char *filename);
void FileClose(pNode head, char *filename);

#endif

