#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _Node
{
	struct _Node *next;
	struct _Node *prev;
	char  *data;
	int   flag;
}Node;


typedef struct _List
{
	Node *head;
	Node *tail;

}List;
