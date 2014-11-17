#include "head.h"
#include "func.c"

int main()
{
	int LoopSize, ListSize;
	List *cList = NULL;
	
	printf("Please input the Loop size:\n");
	scanf("%d", &LoopSize);
	printf("Please input the List size:\n");
	scanf("%d", &ListSize);
	
	while(1)
	{
		cList = CreatList(ListSize);
		ProcessList(cList, LoopSize);

		free(cList);
		printf("Please input the Loop size:\n");
		scanf("%d", &LoopSize);
		printf("Please input the List size:\n");
		scanf("%d", &ListSize);
	}
	
}
