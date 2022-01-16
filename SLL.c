#include <stdio.h>
#include <stdlib.h>

struct Node   
{  
  int data;  
  struct Node *next;   
}*head = NULL;

void create();  
void insert_begin();   
void insert_last();  
void insert_loc();  
void delete_begin();  
void delete_last();  
void delete_loc();
void maxNode();
void minNode();  
int Length();
void sort();
void print();

int main ()  
{  
  int ch=0;  
  while(ch!=13)   
  {    
    printf("\n\nEnter the operation to be performed\n");    
    printf("\n1.Create a node list\n2.Insert in the begining\n3.Insert at the last\n4.Insert at any specified position\n5.Delete from Beginning\n6.Delete from last\n7.Delete node after specified location\n8.Maximum value of node\n9.Minimum value of node\n10.Total length of nodes\n11.Sort the list in ascending order\n12.Show\n13.Exit\n");              
    scanf("\n%d",&ch);  
    switch(ch)  
    {
      case 1:
            create();
            break;
      case 2:  
            insert_begin();       
            break;  
      case 3:  
            insert_last();         
            break;  
      case 4:  
            insert_loc();       
            break;  
      case 5:  
            delete_begin();       
            break;  
      case 6:  
            delete_last();        
            break;  
      case 7:  
            delete_loc();           
            break;
      case 8:
            maxNode();
            break; 
      case 9:
            minNode();
            break;
      case 10:
            Length();
            break;
      case 11:
            sort();
            break;
      case 12:  
            print();        
            break;  
      case 13:  
            exit(0);  
            break;  
      default:  
            printf("Enter valid option");  
    }  
  }  
}   


void create(int n)
{
  int data,i;
  printf("Input the number of nodes : ");
  scanf("%d", &n);

  struct Node *p,*temp;
  head = (struct Node *)malloc(sizeof(struct Node));

  if(head == NULL)
  {
    printf("Unable to allocate memory");
    exit(0);
  }
  printf("Enter the data for node 1: ");
  scanf("%d",&data);

  head->data = data;
  head->next = NULL;

  temp = head;
  for(i=2;i<=n;i++)
  {
    p = (struct Node *)malloc(sizeof(struct Node));

    if(p == NULL)
    {
      printf("Unable to allocate memory");
      break;
    }
    printf("Enter the data for node %d: ",i);
    scanf("%d",&data);

    p->data = data;
    p->next = NULL;

    temp->next = p;
    temp = temp->next;
  }
  
}

void insert_begin()                  
{  
    struct Node *p;  
    int value;  
    p =(struct Node *) malloc(sizeof(struct Node *));  
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\n");    
        scanf("%d",&value);    
        p->data=value;  
        p->next=head;  
        head=p;  
    }  
}

void insert_last()                
{  
    struct Node *p,*temp;  
    int value;     
    p=(struct Node*)malloc(sizeof(struct Node));      
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value\n");  
        scanf("%d",&value);  
        p->data=value;  
        if(head == NULL)  
        {  
            p->next=NULL;  
            head=p;  
        }  
        else  
        {  
            temp=head;  
            while(temp->next!=NULL)  
            {  
                temp=temp->next;  
            }  
            temp->next=p;  
            p->next=NULL;  
        }  
    }  
}  

void insert_loc()               
{  
    int i,loc,value;   
    struct Node *p, *temp;  
    p=(struct Node *)malloc(sizeof(struct Node));  
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value:");  
        scanf("%d",&value);  
        p->data=value;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp=temp->next;  
            if(temp==NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
        }  
        p->next=temp->next;   
        temp->next=p; 
    }  
}  

void delete_begin()          
{  
    struct Node *p;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        p=head;  
        head=p->next;  
        free(p);  
    }  
}  

void delete_last()       
{  
    struct Node *p,*p1;  
    if(head==NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head->next==NULL)  
    {  
        head=NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
    else  
    {  
        p=head;   
        while(p->next!=NULL)  
        {  
            p1=p;  
            p=p->next;  
        }  
        p1->next=NULL;  
        free(p);  
    }     
}  

void delete_loc()    
{  
    struct Node *p,*p1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    p=head;  
    for(i=0;i<loc;i++)  
    {  
        p1=p;       
        p=p->next;  
           
        if(p==NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    p1->next=p->next;  
    free(p);  
    printf("\nDeleted node %d ",loc+1);  
}  

void maxNode() 
{  
  struct Node *p = head;  
  int max;  
      
  if(head == NULL) 
  {  
    printf("List is empty \n");  
  }  
  else 
  {  
    max = head->data;  
          
    while(p != NULL)
    {   
      if(max < p->data) 
      {  
        max = p->data;  
      }  
      p = p->next;  
    }               
    printf("Maximum value node in the list: %d\n", max);  
  }  
}  

void minNode() 
{  
  struct Node * p=head;  
  
  int min;  
      
  if(head == NULL) 
  {  
    printf("List is empty \n");  
  }  
  else 
  {   
    min = head->data;  
          
    while(p != NULL)
    {  
      if(min > p->data) 
      {  
        min = p->data;  
      }  
      p = p->next;  
    }          
    printf("Minimum value node in the list: %d\n", min);  
  }  
}  

int Length(struct Node *head)
{
    int length =0;
    while(head != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}

void sort()
{
  struct Node *p,*q;
  int data;
  q=head;
  while(q!=NULL)
  {
    p=q->next;
    while(p!=NULL)
    {
      if(q->data>p->data)
      {
        data=q->data;
        q->data=p->data;
        p->data=data;
      }
      p=p->next;
    }
    q=q->next;
  }
}

void print()    
{  
    struct Node *p;  
    p=head;   
    if(p==NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nPrinting values:");   
        while (p!=NULL)  
        {  
            printf("%d ",p->data);  
            p=p->next;  
        }  
    }  
} 

