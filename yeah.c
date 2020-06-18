#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Create an empty list*/
List* createList()
{
	List* temp;
	temp = malloc(sizeof(List));
	if (temp)
	{
		temp->head = NULL;
		temp->tail = NULL;
	}
	return temp;
}
void printList(List* p)
{

	if (p->head == NULL) {
		printf("List is empty\n");
	}
	else
	{
		printf("List is: ");
		while (p->head != NULL) {
			printf("%d --> ", p->head->data);
			p->head = p->head->next;
		}
		//printf("%d --> NULL\n",p->head->data); // could put this in the while loop, but then it won't be a nice format
	}

}

/*Free all memory*/
void freeList(List* p)
{
	Node* temp;
	//temp=p->head;
	while (temp != NULL)
	{
		temp = p->head->next;
		free(p->head);
		p->head = temp;
	}

}

/*Number of keys in the list*/
int getListLength(List* p)
{
	if (p->head == NULL)
	{
		printf("We have an empty list here\n");
		return -1;
	}
	else
	{
		int count = 0;
		while (p->head != NULL)
		{
			count = count + 1;
			p->head = p->head->next;
		}
		return count;
	}

}


/*Inserts a key at the head of the list.
Returns 0 if successful or 1 if it failed.*/
int insertAtHead(int k, List* p)
{
	if (p->head == NULL)
	{
		Node* temp;
		temp = malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("A) Failure at insert At Head .\n");
			return 1;
		}
		else
		{
			temp->data = k;
			temp->next = NULL;
			p->head = p->tail = temp;
			return 0;
		}
	}
	else
	{
		Node* temp;
		temp = malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("B)Failure at insert At Head .\n");
			return 1;
		}
		else
		{
			temp->data = k;
			temp->next = p->head;
			p->head = temp;
			return 0;
		}
	}
}

/*Inserts a key at the tail of the list*/
int insertAtTail(int k, List* p)
{
	if (p->tail == NULL)
	{
		Node* temp;
		temp = malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("A) Failure at insert At Tail .\n");
			return 1;
		}
		else
		{
			temp->data = k;
			temp->next = NULL;
			p->head = p->tail = temp;
			return 0;
		}
	}
	else
	{
		Node* temp;
		temp = malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("B) Failure at insert At Tail.\n");
			return 1;
		}
		else
		{
			temp->data = k;
			temp->next = NULL;
			p->tail->next = temp;
			p->tail = temp;
			return 0;
		}
	}

}

/*Returns a complete copy of a list*/
List* copyList(List* p)
{
	if (p->head == NULL)
	{
		printf("Empty List. Copy cannot be produced.\n");
		return NULL;
	}
	else
	{
		List* copy;
		copy = createList();
		if (p->head != NULL)
		{
			Node* temp;
			temp = malloc(sizeof(Node));
			if (temp == NULL)
			{
				printf("A) Failure at Copy List.\n");
				return NULL;
			}
			else
			{
				temp->data = p->head->data;
				temp->next = p->head->next;
				copy->head = copy->tail = temp;
				while (p->head != NULL)
				{
					Node* temp2;
					temp2 = malloc(sizeof(Node));
					if (temp2 == NULL)
					{
						printf("ERROR\n");
					}
					else
					{
						temp2->data = p->tail->data;
						temp2->next = p->tail->next;
						copy->tail = temp2;
					}
					p->head = p->head->next;
				}
			}
		}
		return copy;
	}
}


int main(void)
{
   int i,check ;
   List *trial;
   trial=createList();
   
   for(i=0;i<5;i++)
   {
	  check=insertAtHead(2*i,trial);
      if(check==1)
	  {
	     printf("Failed to insert..\n");
		 break;
	  }
   }
   
   printList(trial);
   
   for(i=0;i<5;i++)
   {
	   printList(trial);
      check=insertAtTail(-2*i,trial);
	  if(check==1)
	  {
	     printf("Failed to insert..\n");
		 break;
	  }
   }
   
   
  // List *num2;
   //num2=createList();
  // num2=copyList(trial);
   
  // printf("The space begins %d\n",getListLength(trial));
   
   
  // printList(num2);
   freeList(trial);
   //freeList(num2);
}