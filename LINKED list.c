#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
struct linked_list
{
    int data;
    struct linked_list *next;
};
typedef struct linked_list* ll;
ll first;
ll temp;
void insert_at_start(int value);
void insert_at_last(int value);
void delete_at_start();
void delete_at_last();
void display();
void search(int value);
void count();
void insert_before_node(int cnt,int value);

int main()
{
    int ch;
    int *val,*a;
    printf("This is a linked list program allowing all linked list function:");
    Sleep(2500);
    system("cls");
    do 
    {
        printf("\n\t\t\tWelcome to dynamically allocation based linked list program:");
        printf("\n1.Press 1 for Insert at first ");
        printf("\n2.Press 2 for Insert at last ");
        printf("\n3.Press 3 for Delete at first");
        printf("\n4.Press 4 for Delete at last");
        printf("\n5.Press 5 for Displaying all values of linked list");
        printf("\n6.Press 6 to Search for a value in linked list");
        printf("\n7.Press 7 to count total number of items");
        printf("\n8.Press 8 for insert before a given node");
        printf("\n9.Press 9 for exit");
        printf("\nPlease enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                val=(int*) malloc(sizeof(int));
                printf("\nEnter a number  to add to linked list at start:");
                scanf("%d",val);
                insert_at_start(*val);
                free(val);
                Sleep(2500);
                system("cls");
                break;
            case 2:
                val=(int*) malloc(sizeof(int));
                printf("\nEnter a number to add to linked list at end :");
                scanf("%d",val);
                insert_at_last(*val);
                printf("\nValue was succesfully added!");
                free(val);
                Sleep(2500);
                system("cls");
                break;
            case 3:
                printf("\nA value will be deleted from start!");
                delete_at_start();
                Sleep(2500);
                system("cls");
                break;
            case 4:
                printf("\nA value will be deleted from last!");
                delete_at_last();
                Sleep(2500);
                system("cls");
                break;
            case 5:
                printf("Displaying all values of linked list:");
                display();
                Sleep(2500);
                system("cls");
                break;
            case 6:
                a=(int*) malloc(sizeof(int));
                printf("Please enter value you want to search :");
                scanf("%d",a);
                search(*a);
                Sleep(2500);
                system("cls");
                free(a);
                break;

            case 7:
                count();
                Sleep(3500);
                system("cls");
                break;
            case 8:
                a=(int*) malloc(sizeof(int));
                val=(int*) malloc(sizeof(int));
                printf("Enter number you want to add to linked list:");
                scanf("%d",val);
                printf("\nEnter node before which you want to add the value:");
                scanf("%d",a);
                insert_before_node(*a,*val);
                free(a);
                free(val);
                Sleep(2500);
                system("cls");
                break;
            case 9:
                printf("\nProgram will now exit!");
                Sleep(2550);
                system("cls");
                break;
            default:
                printf("\nWrong choice try again !!!!");
                Sleep(2500);
                system("cls");
                break;
        }
    }while(ch!=9);
    return 0;
} 
void insert_at_start(int value)
{
    temp=(struct linked_list*) malloc(sizeof(struct linked_list));
    temp->data=value;
    temp->next=0;
    if(first==NULL)
    {
        first=temp;
    } 
    else
    {
        temp->next=first;
        first=temp;
    }
    temp=NULL;

}
void insert_at_last(int value)
{
    temp=(struct linked_list*) malloc(sizeof(struct linked_list));
    temp->data=value;
    temp->next=NULL;
    if (first==NULL)
    {
        first=temp;
    }
    else if (first->next==NULL)
    {
        first->next=temp;
    }
    else
    {
        ll temp2=(struct linked_list*) malloc(sizeof(struct linked_list));
        temp2=first;
        do
        {
            temp2=temp2->next;
        } while (temp2->next!=NULL);
        temp2->next=temp;
        temp2=NULL;
    }
    printf("\nValue that was added is %d",temp->data);
    temp=NULL;
}
void delete_at_start()
{
    if (first==NULL)
    {
        printf("Empty linked list");
    }
    else 
    {
        temp=(struct linked_list*) malloc(sizeof(struct linked_list));
        temp=first;
        first=first->next;
        temp=NULL;
    }
    printf("Value was deleted successfully");
}
void delete_at_last()
{
    printf("hello from 1");
    if (first==NULL)
    {
        printf("Empty linked list");
    }
    else if(first->next==NULL)
    {
        first=NULL;
    } 
    else
    {
        ll temp2=(struct linked_list*) malloc(sizeof(struct linked_list));
        ll temp3=(struct linked_list*) malloc(sizeof(struct linked_list));

        temp2=first;
        do
        {
            temp3=temp2;
            temp2=temp2->next;
        } while (temp2->next!=NULL);
        temp3->next=NULL;
        temp2=NULL;
        temp2=NULL;
    }    
}
void display()
{
    temp=(struct linked_list*) malloc(sizeof(struct linked_list));
    temp=first;
    do
    {
        printf("\nValue is :%d",temp->data);
        temp=temp->next;
        Sleep(890);
    }    while(temp!=NULL);
    free(temp);
    printf("\nAll values have been printed!!");
    Sleep(4000);
}
void search(int value)
{
    temp=(ll) malloc(sizeof(struct linked_list));
    temp=first;
    int *cnt=(int*) malloc(sizeof(int));
    int *check=(int*) malloc(sizeof(int));
    cnt =check=0;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            printf("Value was found at point (%d)",*cnt+1);
            Sleep(1250);
            *check=1;
            break;
        }
        cnt++;
        temp=temp->next;
    }
    if (check==0)
    {
        printf("Value was not founded in the linked list !!");
        Sleep(2000);
    }
    free(cnt);
    free(check);
    free(temp);
}
void count()
{
    int cnt = 1;
    ll temp=(ll) malloc(sizeof(struct linked_list));
    temp=first;
    while (temp->next!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    printf("Total number of nodes in given Linked list is %d",cnt);
    temp=NULL;

}
void insert_before_node(int pos,int value)
{
    int cnt=1;
    temp=(ll) malloc(sizeof(struct linked_list));
    ll p=(ll) malloc(sizeof(struct linked_list));
    temp->data=value;
    temp->next=NULL;
    if (first==NULL||pos<1)
    {
       printf("hello from 1.1");
        temp->next=first;
        first=temp;
    }
    else
    {
        while((cnt<=(pos-1))&&(p->next!=NULL))
        {
            cnt++;
            p=p->next;
            printf("hello from while loop:%d",cnt);
        }
        if(cnt<pos&&p->next==NULL)
        {
           printf("hello from 2.1");
           p->next=temp;
        }
        else
        {
            printf("hello from 2.2");
            temp->next=p->next;
            p->next=temp;
        }
        p=NULL;
        temp=NULL;
    }
}