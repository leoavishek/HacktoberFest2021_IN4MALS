#include<stdio.h>
#include<stdlib.h>
struct linked_list
{
    int num;
    struct linked_list *next;
};
typedef struct linked_list node;
void create(node *list)
{
    int num;
    scanf("%d",&num);
    if(num!=-999)
    {
        list->num=num;
        list->next=(node *)malloc(sizeof(node));
        create(list->next);
    }
    else 
    {
        list->next=NULL;
    }
}
void print(node *list)
{
    if(list->next != NULL)
    {
        printf("%d",list->num);
        if(list->next->next != NULL)
        printf("->");
        print(list->next);
    }
}
int main()
{
    node *l=(node *)malloc(sizeof(node)),*l2=(node *)malloc(sizeof(node));
    printf("First list\n");
    printf("Enter a number and to end give -999\n");
    create(l);
    printf("Second list\n");
    printf("Enter a number and to end give -999\n");
    create(l2);
    print(l);
    printf("\n");
    print(l2);
    printf("\n");
    node * temp=l;
    while(temp->next->next!=NULL)
    temp=temp->next;
    temp->next=l2;
    print(l);
    return 0;
}