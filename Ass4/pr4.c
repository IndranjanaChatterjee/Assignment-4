#include<stdio.h>
#include<malloc.h>
	typedef struct node
	{
		int value;
		struct node *next;
	}node;
	void insert(int val,node **s)
	{
		node *ptr;		
		
			ptr=(node *)(malloc(sizeof(node)));
			
			ptr->value=val;
			ptr->next=NULL;
			if(*s==NULL)
			{
				*s=ptr;
			}
			else
			{
				ptr->next=*s;
				*s=ptr;
			}
			
		}
		void delete(int val,node **s)
		{
		    node *p;
		    while((*s)!=NULL && (*s)->next->value!=val)
		    {
		        (*s)=(*s)->next;
		    }
		    if((*s)!=NULL)
		    {
			
		    p=(*s)->next;
		    (*s)->next=p->next;
		    free(p);
		    }
		    else
		    {
		    	printf("Value not found");
			}
		    
		    
		}
		void display(node **s)
		{
		    while((*s)!=NULL)
		    {
		        printf("\n[%p]{%p %d}",(*s)->next,(*s),(*s)->value);
		        (*s)=(*s)->next;
		    }
		}
		int main()
		{
			node *s,*p;
			s=NULL;
			int n,c=0;
			do
			{
			    printf("\nEnter the value to be entered:");
			    scanf("%d",&n);
			    insert(n,&s);
			    printf("\nEnter 1 to terminate or 0 to continue:");
			    scanf("%d",&c);
			}while(c!=1);
			p=s;
			display(&p);
			p=s;
			do
			{
			    printf("\nEnter the value to be deleted:");
			    scanf("%d",&n);
			    delete(n,&s);
			    
			    printf("\nEnter 1 to terminate or 0 to continue:");
			    scanf("%d",&c);
			    s=p;//going to the starting position
			}while(c!=1);
			printf("\n");
			p=s;//assigning the starting index
			display(&p);
			
		    return 0;
		}
		
		
		
	
