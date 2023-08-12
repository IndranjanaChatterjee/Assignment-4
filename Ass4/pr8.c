#include<stdio.h>
#include<malloc.h>
	typedef struct node
	{
		int value;
		struct node *next;
	}node;
	int main()
	{
		node *ptr,*s;
		s=NULL;
		int n;
		printf("Enter the number of nodes:");
		scanf("%d",&n);
		int i,val;
		for(i=0;i<n;i++)
		{
			ptr=(node *)(malloc(sizeof(node)));
			printf("Enter the value:");
			scanf("%d",&val);
			ptr->value=val;
			ptr->next=NULL;
			if(s==NULL)
			{
				s=ptr;
			}
			else
			{
				ptr->next=s;
				s=ptr;
			}
		}
		ptr=s;
		printf("\nWithout Reversing:");
		while(ptr!=NULL)
		{
			printf("\n[%p]{%d %p}",ptr->next,ptr->value,ptr);
			ptr=ptr->next;
		}
		ptr=s;
		int swap;
		while(ptr!=NULL && ptr->next!=NULL)
		{
			swap=ptr->value;
			ptr->value=ptr->next->value;
			ptr->next->value=swap;
			ptr=ptr->next->next;
		}
		printf("\nAfter Swaping the list:");
		ptr=s;
		while(ptr!=NULL)
		{
			printf("\n[%p]{%d %p}",ptr->next,ptr->value,ptr);
			ptr=ptr->next;
		}
		
	}
