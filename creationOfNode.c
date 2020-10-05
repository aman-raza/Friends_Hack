
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

struct node *createNode(int a){
    struct node *p= (struct node *)malloc(sizeof(struct node));
    p->data=a;
    p->next=NULL;
    return p;
}

int res;

void addNodeAtTheBeginning() {
    printf("Enter your number of nodes!\n");
    scanf("%d",&res);
    printf("Enter the values of your list!\n");
    for(int i=0;i<res;i++){
        int num;
        scanf("%d",&num);
        struct node *q = head;                                                                                                        
        struct node *c = createNode(num);
        c->next=head;
        while(q->next!=head)
            q=q->next;
        q->next = c;
        head = c;
    }
}

void addNodeAtTheEnd() {
    printf("Enter your number of nodes!\n");
    scanf("%d",&res);
    printf("Enter the values of your list!\n");
    int num;
    for(int i=0;i<res;i++){
       
        scanf("%d",&num);
        struct node *c = createNode(num);
        struct node *ptr;
        for(ptr = head;ptr->next!=head; ptr = ptr->next);
        ptr->next = c;
        c->next = head;
    }
   
}

void addNodeAtTheMid(){
    int val,pos;
    struct node *ptr = head;
    if(ptr->next==head){
        printf("\nThe list is empty first enter some data!\n");
        exit(0);
    }
    printf("\nEnter the value and position to be entered after the head!\n");
    scanf("%d%d",&val,&pos);
    struct node *c = createNode(val);
    for(int i=0;i<pos-1;i++){
        ptr = ptr->next;
    }
    c->next = ptr->next;
    ptr->next = c;
}

void Print(struct node *p){
    if(p->next==head){
        printf("You have only one element %d",p->data);
        exit(0);
    }
    printf("%d\t",p->data);
    while (p->next!=head)
    {
        p=p->next;
        printf("%d\t",p->data);
    }
}



int main(){
    printf("Enter your number of nodes!\n");
    scanf("%d",&res);
    printf("Enter the values of your list!\n");
    int h;
    scanf("%d", &h);
    head = createNode(h);
    head->next= head;
    int num;
    for(int i=1;i<res;i++){
       
        scanf("%d",&num);
        struct node *c = createNode(num);
        struct node *ptr;
        for(ptr = head;ptr->next!=head; ptr = ptr->next);
        ptr->next = c;
        c->next = head;
    }
   
    int choice;
    char ch= 'y';
    while(ch == 'y'|| ch =='Y'){
        printf("\nEnter 1 to enter in the begining !!");
        printf("\nEnter 2 to enter in the end  !!");
        printf("\nEnter 3 to enter at any specific position !!");
        printf("\nEnter your choice!!\n");
        int flag=1;
        do{
            flag=1;
            scanf("%d",&choice);
            switch(choice){
                case 1:  addNodeAtTheBeginning();
                        Print(head);
                        break;
                case 2: addNodeAtTheEnd();
                        Print(head);
                        break;
                case 3 :addNodeAtTheMid();
                        Print(head);
                        break;
                default: printf("\nEnter a valid choice!!\n");
                        flag=0;
                        break;
            }
        }while(flag==0);
        printf("\nDo you wish to add more??\n");
        scanf(" %c",&ch);
    }
    return 0;
}