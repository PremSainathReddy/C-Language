# include<stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node * RL,* LL;    
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
    node1->RL=NULL;
    node1->LL=NULL;
    
    if (header->RL==NULL)
     {
     header->RL=node1;
     node1->LL=header;
     header->LL=NULL;
     }
    else
    {
        ptr=header;
     while (ptr->RL!=NULL)
     {
        ptr=ptr->RL;
     }
     ptr->RL=node1;
     node1->LL=ptr;
    }
}


void display()
{
    struct  node * ptr;
   ptr=header->RL;
    if(ptr==NULL)
     printf("LIST IS EMPTY\n");

    else
    {
        while (ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->RL;
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

    ptr=header->RL;
    
    if (ptr==NULL)
    {
        printf("LIST IS EMPTY NO INSERTION IS POSSIBLE\n");
    }
    else
    {
        int data = createdata();
        
        node1->data=data;
        node1->RL=ptr;
        ptr->LL=node1;

        header->RL=node1;
    }

}

void insertatend()
{
    struct node *ptr,*node1;
    node1=(struct node*)malloc(sizeof(struct node));

    ptr=header->RL;
    
    if (ptr==NULL)
    {
        printf("LIST IS EMPTY NO INSERTION IS POSSIBLE\n");
    }
    else
    {
        int data = createdata();
        node1->data=data;
        node1->RL=NULL;
        node1->LL=NULL;
        
        while(ptr->RL!=NULL)
        {
            ptr=ptr->RL;
        }

        ptr->RL=node1;
        node1->LL=ptr;
    }
}

void insertatreq()
{
    struct node *ptr,*node1;
    ptr=header->RL;
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
        while (ptr!=NULL&&ptr->data!=key)
        {
            /* code */
            ptr=ptr->RL;
        }
        if(ptr==NULL)
        { printf("Enter valid key , The Key you enterd is not valid\n");}
        else
        {
                 node1=(struct node*)malloc(sizeof(struct node));
                 node1->data=data;
                 node1->RL=ptr->RL;
                 if(ptr->RL!=NULL)
                 {
                 ptr->RL->LL=node1;
                 }
                 node1->LL=ptr;
                 ptr->RL=node1;
                 
        }
        
    }
}
void delateatbeg()
{
    struct node *ptr,*ptr1;
    ptr = header->RL;
    if (ptr==NULL)
    {
        printf("LIST IS EMPTY SO DELETION IS NOT POSSIBLE\n");
    }
    else
    {
      ptr1=ptr->RL;
      header->RL=ptr1;
      ptr1->LL=header;
      free(ptr);
    }
}
void delateatend()
{
    struct node *ptr,*ptr1;
    ptr=header->RL;
    if (ptr==NULL)
     printf("LIST IS EMPTY SO DELETION IS NOT POSSIBLE\n");
    else{
        while (ptr->RL!=NULL)
        {
            /* code */
            ptr1=ptr;
            ptr=ptr->RL;
        }
        if(ptr==header->RL)
         header->RL=NULL;
        else
         ptr1->RL=NULL;
        free(ptr);
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
    ptr=header->RL;
    if (data==ptr->data)
    {
        /* code */
        delateatbeg();
        
    }
    else {
    while (ptr != NULL&&ptr->data!=data)
    {
        /* code */
        ptr1=ptr;
        ptr=ptr->RL;
    }
    if(ptr==NULL)
        printf("Enter valid key , The Key you enterd is not valid\n");
    else
    {
        ptr1->RL=ptr->RL;
        if(ptr->RL!=NULL)
         ptr->RL->LL=ptr1;
        free(ptr);
    }
  }
 }
}

void main()
{  
    int option;
    header = (struct node*)malloc(sizeof(struct node));
    header->RL = NULL;
    header->LL = NULL;
    while(1)
    {   
        printf("-----DOUBLE-LINKED-LIST-----\n");
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
