# include<stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node * link;    
};

struct node *header;

void create()
{
    int data;
    struct node *node1;
    struct node *ptr;
    
    printf("Enter Data: ");
    scanf("%d",&data);
    node1=(struct node*)malloc(sizeof(struct node));

    node1->data=data;
    node1->link=NULL;
    
    if (header==NULL)
     header=node1;
    else
    {
        ptr=header;
     while (ptr->link!=NULL)
     {
        ptr=ptr->link;
     }
     ptr->link=node1;
    }
}


void display()
{
    struct  node * ptr;
   ptr=header;
    if(ptr==NULL)
     printf("LIST IS EMPTY\n");

    else
    {
        while (ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
        
    }
}
int createdata()
{
    int data;
    printf("Enter Data: ");
    scanf("%d",&data);
    return data;
}
void insertatbegin()
{
    struct node *ptr,*node1;
    node1=(struct node*)malloc(sizeof(struct node));

    ptr=header;
    
    if (ptr==NULL)
    {
        printf("LIST IS EMPTY NO INSERTION IS POSSIBLE\n");
    }
    else
    {
        int data = createdata();
        
        node1->data=data;
        node1->link=ptr;

        header=node1;
    }

}

void insertatend()
{
    struct node *ptr,*node1;
    node1=(struct node*)malloc(sizeof(struct node));

    ptr=header;
    
    if (ptr==NULL)
    {
        printf("LIST IS EMPTY NO INSERTION IS POSSIBLE\n");
    }
    else
    {
        int data = createdata();
        node1->data=data;
        node1->link=NULL;
        
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }

        ptr->link=node1;
    }
}

void insertatreq()
{
    struct node *ptr,*node1;
    ptr=header;
    if(header==NULL)
    {
        printf("LIST IS EMPTY SO INSERTION IS NOT POSSIBLE\n");
    }
    else
    {
        int data=createdata();
        int key;
        printf("Enter Data to place a Node after that: ");
        scanf("%d",&key);
        while (ptr->data!=key)
        {
            /* code */
            ptr=ptr->link;
        }
        if(ptr==NULL)
        printf("Enter valid key , The Key you enterd is not valid\n");
        else
        {
                 node1=(struct node*)malloc(sizeof(struct node));
                 node1->data=data;
                 node1->link=ptr->link;
                 ptr->link=node1;
                 
        }
        
    }
}
void delateatbeg()
{
    struct node *ptr,*ptr1;
    ptr = header;
    if (ptr==NULL)
    {
        printf("LIST IS EMPTY SO DELETION IS NOT POSSIBLE\n");
    }
    else
    {
      ptr1=ptr->link;
      header=ptr1;
      free(ptr);
    }
}
void delateatend()
{
    struct node *ptr,*ptr1;
    ptr=header;
    if (ptr==NULL)
     printf("LIST IS EMPTY SO DELETION IS NOT POSSIBLE\n");
    else{
        while (ptr->link!=NULL)
        {
            /* code */
            ptr1=ptr;
            ptr=ptr->link;
        }
        if(header==ptr)
         header=NULL;
        else{
         ptr1->link=NULL;
        free(ptr);
        }
    }
}
void delateatreq()
{
    struct node *ptr,*ptr1;
    int data;
    if (header==NULL)
    {
        printf("LIST IS EMPTY SO DELETION IS NOT POSSIBLE\n");
    }
    else
    {
    printf("Enter Data which you want to Delete: ");
    scanf("%d",&data);
    if (data==ptr->data)
    {
        /* code */
        delateatbeg();
        
    }
    else {
     ptr=header->link;//asaign second node
     ptr1=header;

    while (ptr!=NULL)
    {
      if(ptr->data==data)
      {
        ptr1->link=ptr->link;
        free(ptr);
        return;
      }

      ptr1=ptr;
      ptr=ptr->link;
    }

        printf("Enter valid key , The Key you enterd is not valid\n");
  }
 }
}

void main()
{  
    int option;
    while(1)
    {
        printf("-----SINGLE-LINKED-LIST-----\n");
        printf("1)CREATE NODE (OR) ADD DATA\n2)INSERTION AT BEGINING\n3)INSERTION AT END\n4)INSERTION AT REQUIRED POSITION\n5)DELETION AT BEGIN\n6)DELETION AT END\n7)dELETION AT REQUIRED POSITION\n8)DISPLAY\n9)EXIT\n");
        printf("Choose any option: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            insertatbegin();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            insertatreq();
            break;
        case 5:
            delateatbeg();
            break;
        case 6:
            delateatend();
            break;
        case 7:
            delateatreq();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(1);
            break;
        default:
        printf("Invalid Option Chosee Correct Option\n");
            break;
        }
    }
    
}
