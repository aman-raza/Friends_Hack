
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

void addNodeAtTheEnd(int n) {
         struct node *c = createNode(n);
        struct node *ptr;
        for(ptr = head;ptr->next!=head; ptr = ptr->next);
        ptr->next = c;
        c->next = head;
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


void deleteAtEnd(){
    printf("\nNow last element will be deleted!\n");
    struct node *p;
    struct node *q;
    for(p = head,q =head;p->next!=head;q=p,p = p->next);
        q->next = head;
    free(p);
    }

void deleteAtBeginning(){
    printf("\nNow first element will be deleted!\n");
    struct node *q=head,*p=head;
    head= head->next;
    while(q->next!=p)
        q=q->next;
    q->next = head;
    free(p);
}

void deleteAtMid(){
    int pos;
    printf("\nEnter the position of element to be deleted after head!\n");
    scanf("%d",&pos);
    struct node *p=head;
    struct node *q;
    for(int i=0;i<pos;i++){
        q=p;
        p=p->next;
    }
    q->next = p->next;
    free(p);
}

int main(){
    int res;
    printf("Enter your number of nodes!\n");
    scanf("%d",&res);
    printf("Enter the values of your list!\n");
    int h;
    scanf("%d", &h);
    head = createNode(h);
    head->next = head;
    for(int i=1;i<res;i++){
        int num;
        scanf("%d",&num);
        addNodeAtTheEnd(num);
    }
    Print(head);
    int choice;
    char ch= 'y';
    while(ch == 'y'|| ch =='Y'){
    printf("\nEnter 1 to delete the first !!");
	printf("\nEnter 2 to delete the last !!");
	printf("\nEnter 3 to delete node with a index!");
	printf("\nEnter your choice!!\n");
    int flag=1;
    do{
        flag=1;
	scanf("%d",&choice);
        switch(choice){
            case 1: deleteAtBeginning();
                    Print(head);
                    break;
            case 2:  deleteAtEnd();
                    Print(head);
                    break;
            case 3 :deleteAtMid();
                    Print(head);
                    break;
            default: printf("\nEnter a valid choice!!\n");
                    flag=0;
                    break;
         }
    }while(flag==0);
    printf("\nDo you wish to delete more??\n");
    scanf(" %c",&ch);
    }
    return 0;
}