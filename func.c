
List *CreatList(int n)
{
	int i = 0;
	Node *p = (Node *)malloc(sizeof(Node) * n);
	List *cList = malloc(sizeof(List));

	if((cList == NULL) || (p == NULL))
	{
		printf("Allocate list add error\n");
		return NULL;
	}

	cList->head = (Node *)&p[0];
	cList->tail = (Node *)&p[n-1];

	cList->head->next = (Node *)&p[1];
	cList->head->prev = cList->tail;
	cList->head->data = NULL;
	cList->head->flag = 1;

	cList->tail->next = cList->head;
	cList->tail->prev = (Node *)&p[n - 2];
	cList->tail->data = NULL;
	
	Node *temp = cList->head->next;
	for(i = 1; i < n - 1; i++)
	{
		temp->prev = (Node *)&p[i - 1];
		temp->next = (Node *)&p[i + 1];
		temp->data = NULL;
		temp->flag = i + 1;
		temp = temp->next;
	}
	
	cList->tail->flag = n;
	return cList;
}

int LengthOfList(List *cList)
{
	Node *p = NULL;
	int len = 0;

	p = cList->head;
	
	if(p == NULL)
	{
		return 0;
	}
	else if(p->next == NULL)
	{
		return 1;
	}

	while( (p != NULL) && (p->next != cList->tail) )
	{
		p = p->next;
		len ++;
	}

	return (len + 2);

}

int DestroyNodeByIndex(List *cList, int DestroyNodeIndex)
{
	Node *temp = NULL;
	 
	temp = cList->head;

	((Node *)&temp[DestroyNodeIndex - 1])->next = ((Node *)&temp[DestroyNodeIndex + 1]);
	((Node *)&temp[DestroyNodeIndex + 1])->prev = ((Node *)&temp[DestroyNodeIndex - 1]);
	
	free(&temp[DestroyNodeIndex]);
	return 1;
}

int ReArrangeList(List *cList, Node *Des)
{
	Node *temp = NULL;
	int  times = 0;
	
	if(Des == cList->head)
	{
		cList->head = Des->next;
		cList->head->prev = Des->prev;
		Des->prev->next   = cList->head;

		Des->next = NULL;
		Des->prev = NULL;

		return 1;
	}
	else if(Des == cList->tail)
	{
		cList->tail = Des->prev;
		cList->tail->next = Des->next;
		Des->next->prev   = cList->tail;

		Des->next = NULL;
		Des->prev = NULL;

		return 1;
	}

	temp = cList->head;
	while(temp != Des)
	{
		temp = temp->next;
		times ++;
		if(times >= LengthOfList(cList))
		{
			printf("No this Node int the list\n");
			return 0;
		}
	}


	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	temp->next = NULL;
	temp->prev = NULL;

	//free(Des);
	return 1;
}

int ProcessList(List *cList, int LengthOfLoop)
{
	int NumTimer = 1;
	int ListLength = LengthOfList(cList);
	Node *temp = NULL;
	printf("List length:%d\n", ListLength);
	temp = cList->head;

	if(ListLength == 1)
	{
		printf("The node is head:%d\n", cList->head->flag);
		return 1;
	}

	while(ListLength > 1)
	{
		if(NumTimer == LengthOfLoop)
		{
			NumTimer = 1;
			Node *tempT = temp->next;
			printf("Del:%d\n", temp->flag);
			ReArrangeList(cList, temp);
			temp = tempT;
			ListLength --;
		}
		else
		{
			NumTimer ++;
			temp = temp->next;
			continue;
		}
	}

	printf("The last node is %d\n", temp->flag);
}
