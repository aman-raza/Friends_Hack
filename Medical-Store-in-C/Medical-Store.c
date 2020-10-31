# include <stdio.h>
# include <malloc.h>
#include<string.h>
#include<conio.h>

struct node
{
	int id,quantity,dd,mm,yy,dd1,mm1,yy1;
    float price;
    char medicine_name[30],company[30],info[100];
    char patient_name[30],doctor_name[30];
    long long int contact_no;
	struct node *lchild;
	struct node *rchild;
}*root;

typedef struct node1
{
	int id,quantity,dd,mm,yy,dd1,mm1,yy1;
    float price;
    char medicine_name[30],company[30],info[100];
    char patient_name[30],doctor_name[30],mfg_date[20],exp_date[20];
    long long int contact_no;
	struct node1 *next;
}node1;


void login();
void find(int item,struct node **par,struct node **loc);
void insert(int item);
void case_a(struct node *par,struct node *loc );
void case_b(struct node *par,struct node *loc);
void case_c(struct node *par,struct node *loc);
int del(int item);
int preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void display(struct node *ptr,int level);
void search(int item);
void modify(struct node *ptr);

node1 *insert_loc(node1*,node1*);
void create_queue();
void del_queue();
void display_queue(node1 *front);
node1 *rear=NULL;
node1 *front=NULL;
node1 *p,*head;


char username[20]="medical";
char password[5]="g@10";
char pass[4];
char name[20];
int i,n,x,j,ch,l;
int dd,mm,yy,dd1,mm1,yy1;


int main()
{
	login();
	int choice,num;
	struct node *tmp,*parent,*location;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Preorder Traversal\n");
		printf("5.Postorder Traversal\n");
		printf("6.Display\n");
		printf("7.Search\n");
		printf("8.Modify\n");
		printf("9.Create using queue\n");
		printf("10.Display using queue\n");
		printf("11.Insert using queue\n");
		printf("12.Delete using queue\n");
		printf("13.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
				printf("Enter the medicine id to be inserted : ");
				scanf("%d",&num);
				insert(num);
				break;
		 case 2:
				printf("Enter the  medicine id to be deleted : ");
				scanf("%d",&num);
				del(num);
				break;
		 case 3:
				printf("\n*****************************************");
				printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				inorder(root);
				break;
		 case 4:

				printf("\n*****************************************");
				printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				preorder(root);
				break;
		 case 5:

				printf("\n*****************************************");
				printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				postorder(root);
				break;
		 case 6:
				display(root,1);
				break;
		 case 7:
				printf("Enter the medicine id to be searched : ");
				scanf("%d",&num);
				find(num,&parent,&location);
				if(location!=NULL)
				{
					search(num);
				}
				else
				{
					printf("\nmedicine not found");
				}
				break;
		case 8:
				modify(root);
				break;
		case 9:
				printf("Enter no. of medicines:");
				scanf("%d",&n);
				create_queue(n);
				break;
		case 10:
				display_queue(front);
				break;
		case 11:
				front= insert_loc(front,rear);
				rear=rear->next;
				n=n+1;
				break;
		case 12:
				del_queue();
				display_queue(front);
				break;
		case 13:
				exit(0);
				break;
				default:
				printf("Wrong choice\n");
		}
	}
}


void login()
{
  printf("\t\tEnter username:");
  scanf("%s",name);
    printf("\t\tEnter the password:");
    //scanf("%s",pass);
    i=0;
    while(ch!=13)
    {
     //
	 ch=getch();
     pass[i]=ch;
     i++;
     printf("*");

    }
    pass[i-1]='\0';


        if(strcmp(password,pass)==0 && strcmp(username,name)==0)
        {
            printf("\n\n\t\t WELCOME .......\n\n\n");

         }
        else
        {
          printf("\nYour system has been locked");
          exit (0);
        }
}


void find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL)  /*tree empty*/
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->id) /*item is at root*/
	{
		*loc=root;
		*par=NULL;
		return;
	}
	/*Initialize ptr and ptrsave*/
	if(item<root->id)
		ptr=root->lchild;
	else
		ptr=root->rchild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->id)
		{       *loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->id)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }/*End of while */
	 *loc=NULL;   /*item not found*/
	 *par=ptrsave;
}/*End of find()*/

void insert(int item)
{   struct node *tmp,*parent,*location;
int loop=0,loop1=0,loop2=0;
	find(item,&parent,&location);

	if(location!=NULL)
	{
		printf("Item already present");
		return;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->id=item;


						printf("\nenter quantity:");
						scanf("%d",&(tmp->quantity));
						printf("\nenter price:");
						scanf("%f",&(tmp->price));
						printf("\nenter medicine name:");
						scanf("%s",(tmp->medicine_name));
						printf("\nenter company:");
						scanf("%s",(tmp->company));
						printf("\nenter info of medicine:");
						scanf("%s",(tmp->info));
						printf("\nenter patient name:");
						scanf("%s",(tmp->patient_name));
						printf("\nenter doctors name:");
						scanf("%s",(tmp->doctor_name));

                        while(loop==0)
                        {
                        printf("\n enter the mfg date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(tmp->dd),&(tmp->mm),&(tmp->yy));
                        if(tmp->dd<=31 && tmp->mm<=12 && tmp->yy>2010 && tmp->yy<=2019)
                            {
                             loop=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop=0;
                        }
                        }

                         while(loop1==0)
                        {
                        printf("\n enter the exp date(DD/MM/YY ):-");
                        scanf("%d/%d/%d",&(tmp->dd1),&(tmp->mm1),&(tmp->yy1));
                        if(tmp->dd1<=31 && tmp->mm1<=12 && tmp->yy1>2015 && tmp->yy1<=2025)
                            {
                             loop1=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop1=0;
                        }
                        }


                        while(loop2==0)
                            {
                                printf("\n enter patient's contact number:-");
                                scanf("%lld",&(tmp->contact_no));
                                    if((tmp->contact_no)>7000000000 && (tmp->contact_no)<=9999999999)
                                      {
                                         loop2=1;
                                      }
                                     else
                                      {
                                          printf("please enter valid contact no.");
                                          loop2=0;
                                      }
                                        }
                tmp->lchild=NULL;
                tmp->rchild=NULL;

                if(parent==NULL)
                    root=tmp;
                else
                    if(item<parent->id)
                        parent->lchild=tmp;
                    else
                        parent->rchild=tmp;
}/*End of insert()*/


void case_a(struct node *par,struct node *loc )
{
	if(par==NULL) /*item to be deleted is root node*/
		root=NULL;
	else
		if(loc==par->lchild)
			par->lchild=NULL;
		else
			par->rchild=NULL;
}/*End of case_a()*/

void case_b(struct node *par,struct node *loc)
{
	struct node *child;

	/*Initialize child*/
	if(loc->lchild!=NULL) /*item to be deleted has lchild */
		child=loc->lchild;
	else                /*item to be deleted has rchild */
		child=loc->rchild;

	if(par==NULL )   /*Item to be deleted is root node*/
		root=child;
	else
		if( loc==par->lchild)   /*item is lchild of its parent*/
			par->lchild=child;
		else                  /*item is rchild of its parent*/
			par->rchild=child;
}/*End of case_b()*/

void case_c(struct node *par,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*parsuc;

	/*Find inorder successor and its parent*/
	ptrsave=loc;
	ptr=loc->rchild;
	while(ptr->lchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->lchild==NULL && suc->rchild==NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);

	if(par==NULL) /*if item to be deleted is root node */
		root=suc;
	else
		if(loc==par->lchild)
			par->lchild=suc;
		else
			par->rchild=suc;

	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}/*End of case_c()*/
int del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	find(item,&parent,&location);
	if(location==NULL)
	{
		printf("Item not present in tree");
		return 0;
	}

	if(location->lchild==NULL && location->rchild==NULL)
		case_a(parent,location);
	if(location->lchild!=NULL && location->rchild==NULL)
		case_b(parent,location);
	if(location->lchild==NULL && location->rchild!=NULL)
		case_b(parent,location);
	if(location->lchild!=NULL && location->rchild!=NULL)
		case_c(parent,location);
	free(location);
}/*End of del()*/

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}

	if(ptr!=NULL)
	{



				printf("\n%d",(ptr->id));
                printf("\t%d",(ptr->quantity));
                printf("\t\t%.2f",(ptr->price));
                printf("\t\t%s",(ptr->medicine_name));
                printf("\t%s",(ptr->company));
                printf("\t%s",(ptr->info));
                printf("\t%s",(ptr->patient_name));
                printf("\t\t%s",(ptr->doctor_name));
                printf("\t\t%d/%d/%d",(ptr->dd),(ptr->mm),(ptr->yy));
                printf("\t%d/%d/%d",(ptr->dd1),(ptr->mm1),(ptr->yy1));
                printf("\t%lld",(ptr->contact_no));

		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}/*End of preorder()*/

void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}

	if(ptr!=NULL)
	{
		inorder(ptr->lchild);



				printf("\n%d",(ptr->id));
                printf("\t%d",(ptr->quantity));
                printf("\t\t%.2f",(ptr->price));
                printf("\t\t%s",(ptr->medicine_name));
                printf("\t%s",(ptr->company));
                printf("\t%s",(ptr->info));
                printf("\t%s",(ptr->patient_name));
                printf("\t\t%s",(ptr->doctor_name));
               printf("\t\t%d/%d/%d",(ptr->dd),(ptr->mm),(ptr->yy));
                printf("\t%d/%d/%d",(ptr->dd1),(ptr->mm1),(ptr->yy1));
                printf("\t%lld",(ptr->contact_no));


		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}

	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);


				printf("\n%d",(ptr->id));
                printf("\t%d",(ptr->quantity));
                printf("\t\t%.2f",(ptr->price));
                printf("\t\t%s",(ptr->medicine_name));
                printf("\t%s",(ptr->company));
                printf("\t%s",(ptr->info));
                printf("\t%s",(ptr->patient_name));
                printf("\t\t%s",(ptr->doctor_name));
                printf("\t\t%d/%d/%d",(ptr->dd),(ptr->mm),(ptr->yy));
                printf("\t%d/%d/%d",(ptr->dd1),(ptr->mm1),(ptr->yy1));
                printf("\t%lld",(ptr->contact_no));






	}
}/*End of postorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n\n");
		for (i = 0; i < level; i++)
			printf("    ");

	printf("%d,%s", ptr->id,ptr->medicine_name);

		display(ptr->lchild, level+1);
	}/*End of if*/
}/*End of display()*/

void search(int item)
{
	struct node *ptr;

	if(root==NULL)  /*tree empty*/
	{
		printf("\n medicine not found");
		return;
	}
	if(item==root->id) /*item is at root*/
	{

				printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				printf("\n%d",(root->id));
                printf("\t%d",(root->quantity));
                printf("\t\t%.2f",(root->price));
                printf("\t\t%s",(root->medicine_name));
                printf("\t%s",(root->company));
                printf("\t%s",(root->info));
                printf("\t%s",(root->patient_name));
                printf("\t\t%s",(root->doctor_name));
             	printf("\t\t%d/%d/%d",(root->dd),(root->mm),(root->yy));
                printf("\t%d/%d/%d",(root->dd1),(root->mm1),(root->yy1));
                printf("\t%lld",(root->contact_no));
				return;
	}
	if(item<root->id)
		ptr=root->lchild;
	else
		ptr=root->rchild;

	while(ptr!=NULL)
	{
		if(item==ptr->id)
		{       printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				printf("\n%d",(ptr->id));
                printf("\t%d",(ptr->quantity));
                printf("\t\t%.2f",(ptr->price));
                printf("\t\t%s",(ptr->medicine_name));
                printf("\t%s",(ptr->company));
                printf("\t%s",(ptr->info));
                printf("\t%s",(ptr->patient_name));
                printf("\t\t%s",(ptr->doctor_name));
                printf("\t\t%d/%d/%d",(ptr->dd),(ptr->mm),(ptr->yy));
                printf("\t%d/%d/%d",(ptr->dd1),(ptr->mm1),(ptr->yy1));
                printf("\tlld",(ptr->contact_no));

			return;
		}
		if(item<ptr->id)
		{
			ptr=ptr->lchild;
			printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				printf("\n%d",(ptr->id));
                printf("\t%d",(ptr->quantity));
                printf("\t\t%.2f",(ptr->price));
                printf("\t\t%s",(ptr->medicine_name));
                printf("\t%s",(ptr->company));
                printf("\t%s",(ptr->info));
                printf("\t%s",(ptr->patient_name));
                printf("\t\t%s",(ptr->doctor_name));
				printf("\t\t%d/%d/%d",(ptr->dd),(ptr->mm),(ptr->yy));
                printf("\t%d/%d/%d",(ptr->dd1),(ptr->mm1),(ptr->yy1));
                printf("\tlld",(ptr->contact_no));
		}
		else
		{		ptr=ptr->rchild;
				printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
				printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
				printf("\n%d",(ptr->id));
                printf("\t%d",(ptr->quantity));
                printf("\t\t%.2f",(ptr->price));
                printf("\t\t%s",(ptr->medicine_name));
                printf("\t%s",(ptr->company));
                printf("\t%s",(ptr->info));
                printf("\t%s",(ptr->patient_name));
                printf("\t\t%s",(ptr->doctor_name));
                printf("\t\t%d/%d/%d",(ptr->dd),(ptr->mm),(ptr->yy));
                printf("\t%d/%d/%d",(ptr->dd1),(ptr->mm1),(ptr->yy1));
                printf("\tlld",(ptr->contact_no));


		}

		//printf("\n medicine not found");
	}
}
void modify(struct node *ptr)
{
	int item,m;
	int loop3=0,loop4=0,loop5=0,loop6=0,loop7=0,loop8=0,loop9=0,loop10=0,loop11=0,loop12=0,loop13=0,loop14=0;
	printf("\nEnter the medicine id to be modified-");
	scanf("%d",&item);

	if(root==NULL)  /*tree empty*/
	{
		printf("\n tree is empty");
		return;
	}
	if(item==root->id)
	{

			do
			{
					printf("\n 1].id :");
					printf("\n 2].quantity :");
					printf("\n 3].price :");
					printf("\n 4].medicine_name :");
					printf("\n 5].company:");
					printf("\n 6].info :");
					printf("\n 7].patient_name:");
					printf("\n 8].doctor_name:");
					printf("\n 9].mfg_date:");
					printf("\n 10].exp_date:");
					printf("\n 11].contact_no :");
					printf("\n 12].Exit :");
					printf("\n Enter Choice That u want to Modity :");
					scanf("%d",&m);
				switch(m)
				{
						case 1:
								printf("\nenter id of medicine:");
								scanf("%d",&(root->id));
								break;

						case 2:
								printf("\nenter quantity:");
								scanf("%d",&(root->quantity));
								break;

						case 3:
								printf("\nenter price:");
								scanf("%f",&(root->price));
								break;
						case 4:
								printf("\nenter medicine name:");
								scanf("%s",(root->medicine_name));
								break;
						case 5:
								printf("\nenter company:");
								scanf("%s",(root->company));
								break;
						case 6:
								printf("\nenter info of medicine:");
								scanf("%s",(root->info));
								break;
						case 7:
								printf("\nenter patient name:");
								scanf("%s",(root->patient_name));
								break;
						case 8:
								printf("\nenter doctors name:");
								scanf("%s",(root->doctor_name));
								break;
						case 9:

								 while(loop7==0)
                        {
                        printf("\n enter the mfg date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd),&(root->mm),&(root->yy));
                        if(root->dd<=31 && root->mm<=12 && root->yy>2010 && root->yy<=2019)
                            {
                             loop7=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop7=0;
                        }
                        }


											break;
						case 10:
								  while(loop8==0)
                        {
                        printf("\n enter the exp date(DD/MM/YY ):-");
                        scanf("%d/%d/%d",&(root->dd1),&(root->mm1),&(root->yy1));
                        if(root->dd1<=31 && root->mm1<=12 && root->yy1>2015 && root->yy1<=2025)
                            {
                             loop8=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop8=0;
                        }
                        }
								break;
						case 11:
                                while(loop3==0)
                            {
                                printf("\n enter patient's contact number:-");
                                scanf("%lld",&(root->contact_no));
                                    if((root->contact_no)>7000000000 && (root->contact_no)<=9999999999)
                                      {
                                         loop3=1;
                                      }
                                     else
                                      {
                                          printf("please enter valid contact no.");
                                          loop3=0;
                                      }
                            }
                            break;



						case 12:
								return;



				}
			}
			while(m!=13);

	}

	if(item<root->id)
		ptr=root->lchild;
	else
		ptr=root->rchild;

	while(ptr!=NULL)
	{
		if(item==ptr->id)
		{
			do
			{
					printf("\n 1].id :");
					printf("\n 2].quantity :");
					printf("\n 3].price :");
					printf("\n 4].medicine_name :");
					printf("\n 5].company:");
					printf("\n 6].info :");
					printf("\n 7].patient_name:");
					printf("\n 8].doctor_name:");
					printf("\n 9].mfg_date:");
					printf("\n 10].exp_date:");
					printf("\n 11].contact_no :");
					printf("\n 12].Exit :");
					printf("\n Enter Choice That u want to Modity :");
					scanf("%d",&m);
				switch(m)
				{
						case 1:
								printf("\nenter id of medicine:");
								scanf("%d",&(ptr->id));
								break;

						case 2:
								printf("\nenter quantity:");
								scanf("%d",&(ptr->quantity));
								break;

						case 3:
								printf("\nenter price:");
								scanf("%f",&(ptr->price));
								break;
						case 4:
								printf("\nenter medicine name:");
								scanf("%s",(ptr->medicine_name));
								break;
						case 5:
								printf("\nenter company:");
								scanf("%s",(ptr->company));
								break;
						case 6:
								printf("\nenter info of medicine:");
								scanf("%s",(ptr->info));
								break;
						case 7:
								printf("\nenter patient name:");
								scanf("%s",(ptr->patient_name));
								break;
						case 8:
								printf("\nenter doctors name:");
								scanf("%s",(ptr->doctor_name));
								break;
						case 9:

								 while(loop9==0)
                        {
                        printf("\n enter the mfg date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd),&(root->mm),&(root->yy));
                        if(root->dd<=31 && root->mm<=12 && root->yy>2010 && root->yy<=2019)
                            {
                             loop9=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop9=0;
                        }
                        }
								break;
						case 10:

								 while(loop10==0)
                        {
                        printf("\n enter the exp date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd1),&(root->mm1),&(root->yy1));
                        if(root->dd1<=31 && root->mm1<=12 && root->yy1>2010 && root->yy1<=2019)
                            {
                             loop10=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop10=0;
                        }
                        }
								break;
						case 11:
						   while(loop4==0)
                            {
                                printf("\n enter patient's contact number:-");
                                scanf("%lld",&(root->contact_no));
                                    if((root->contact_no)>7000000000 && (root->contact_no)<=9999999999)
                                      {
                                         loop4=1;
                                      }
                                     else
                                      {
                                          printf("please enter valid contact no.");
                                          loop4=0;
                                      }
                            }
                            break;


						case 12:
								return;

				}
			}
			while(m!=13);

		}
		if(item<ptr->id)
		{
			/*ptr=ptr->lchild;*/
			do
			{
					printf("\n 1].id :");
					printf("\n 2].quantity :");
					printf("\n 3].price :");
					printf("\n 4].medicine_name :");
					printf("\n 5].company:");
					printf("\n 6].info :");
					printf("\n 7].patient_name:");
					printf("\n 8].doctor_name:");
					printf("\n 9].mfg_date:");
					printf("\n 10].exp_date:");
					printf("\n 11].contact_no :");
					printf("\n 12].Exit :");
					printf("\n Enter Choice That u want to Modity :");
					scanf("%d",&m);
				switch(m)
				{
						case 1:
								printf("\nenter id of medicine:");
								scanf("%d",&(ptr->id));
								break;

						case 2:
								printf("\nenter quantity:");
								scanf("%d",&(ptr->quantity));
								break;

						case 3:
								printf("\nenter price:");
								scanf("%f",&(ptr->price));
								break;
						case 4:
								printf("\nenter medicine name:");
								scanf("%s",(ptr->medicine_name));
								break;
						case 5:
								printf("\nenter company:");
								scanf("%s",(ptr->company));
								break;
						case 6:
								printf("\nenter info of medicine:");
								scanf("%s",(ptr->info));
								break;
						case 7:
								printf("\nenter patient name:");
								scanf("%s",(ptr->patient_name));
								break;
						case 8:
								printf("\nenter doctors name:");
								scanf("%s",(ptr->doctor_name));
								break;
						case 9:


								 while(loop11==0)
                        {
                        printf("\n enter the mfg date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd),&(root->mm),&(root->yy));
                        if(root->dd<=31 && root->mm<=12 && root->yy>2010 && root->yy<=2019)
                            {
                             loop11=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop11=0;
                        }
                        }

								break;
						case 10:

								 while(loop12==0)
                        {
                        printf("\n enter the exp date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd1),&(root->mm1),&(root->yy1));
                        if(root->dd1<=31 && root->mm1<=12 && root->yy1>2010 && root->yy1<=2019)
                            {
                             loop12=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop12=0;
                        }
                        }
								break;
						case 11:
								   while(loop5==0)
                            {
                                printf("\n enter patient's contact number:-");
                                scanf("%lld",&(root->contact_no));
                                    if((root->contact_no)>7000000000 && (root->contact_no)<=9999999999)
                                      {
                                         loop5=1;
                                      }
                                     else
                                      {
                                          printf("please enter valid contact no.");
                                          loop5=0;
                                      }
                            }
                            break;


						case 12:
								return;

				}
			}
			while(m!=13);
		}
		else
		{
			//ptr=ptr->rchild;
			do
			{
					printf("\n 1].id :");
					printf("\n 2].quantity :");
					printf("\n 3].price :");
					printf("\n 4].medicine_name :");
					printf("\n 5].company:");
					printf("\n 6].info :");
					printf("\n 7].patient_name:");
					printf("\n 8].doctor_name:");
					printf("\n 9].mfg_date:");
					printf("\n 10].exp_date:");
					printf("\n 11].contact_no :");
					printf("\n 12].Exit :");
					printf("\n Enter Choice That u want to Modity :");
					scanf("%d",&m);
				switch(m)
				{
						case 1:
								printf("\nenter id of medicine:");
								scanf("%d",&(ptr->id));
								break;

						case 2:
								printf("\nenter quantity:");
								scanf("%d",&(ptr->quantity));
								break;

						case 3:
								printf("\nenter price:");
								scanf("%f",&(ptr->price));
								break;
						case 4:
								printf("\nenter medicine name:");
								scanf("%s",(ptr->medicine_name));
								break;
						case 5:
								printf("\nenter company:");
								scanf("%s",(ptr->company));
								break;
						case 6:
								printf("\nenter info of medicine:");
								scanf("%s",(ptr->info));
								break;
						case 7:
								printf("\nenter patient name:");
								scanf("%s",(ptr->patient_name));
								break;
						case 8:
								printf("\nenter doctors name:");
								scanf("%s",(ptr->doctor_name));
								break;
						case 9:

								 while(loop13==0)
                        {
                        printf("\n enter the mfg date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd),&(root->mm),&(root->yy));
                        if(root->dd<=31 && root->mm<=12 && root->yy>2010 && root->yy<=2019)
                            {
                             loop13=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop13=0;
                        }
                        }
								break;
						case 10:


								 while(loop14==0)
                        {
                        printf("\n enter the exp date(DD MM YY ):-");
                        scanf("%d/%d/%d",&(root->dd1),&(root->mm1),&(root->yy1));
                        if(root->dd1<=31 && root->mm1<=12 && root->yy1>2010 && root->yy1<=2019)
                            {
                             loop14=1;
                            }
                            else
                        {
                            printf("please enter valid date");
                               loop14=0;
                        }
                        }
								break;
						case 11:
							   while(loop6==0)
                            {
                                printf("\n enter patient's contact number:-");
                                scanf("%lld",&(root->contact_no));
                                    if((root->contact_no)>7000000000 && (root->contact_no)<=9999999999)
                                      {
                                         loop6=1;
                                      }
                                     else
                                      {
                                          printf("please enter valid contact no.");
                                          loop6=0;
                                      }
                            }
                            break;


						case 12:
								return;


				}
			}
			while(m!=13);
		}
	}
}


node1 *insert_loc(node1 *front,node1 *rear)
{
	node1 *p,*q;
	int i;
	p=(node1*)malloc(sizeof(node1));
	printf("\n******************************");
    printf("\nenter id of medicine:");
    scanf("%d",&p->id);
    printf("\nenter quantity:");
    scanf("%d",&p->quantity);
    printf("\nenter price:");
    scanf("%f",&p->price);
	printf("\nenter medicine name:");
	scanf("%s",p->medicine_name);
    printf("\nenter company:");
    scanf("%s",p->company);
    printf("\nenter info of medicine:");
    scanf("%s",p->info);
    printf("\nenter patient name:");
	scanf("%s",p->patient_name);
    printf("\nenter doctors name:");
    scanf("%s",p->doctor_name);
    printf("\nenter mfg date:");
	scanf("%d/%d/%d",&(p->dd),&(p->mm),&(p->yy));
    printf("\nenter exp date:");
	scanf("%d/%d/%d",&(p->dd1),&(p->mm1),&(p->yy1));
    printf("\nenter patient's contact number:");
    scanf("%lld",&p->contact_no);
	printf("\n******************************");
	p->next=NULL;
	p->next=rear->next;
	rear->next=p;
	return(front);
}

void create_queue()
{
     node1 *temp,*p;
     int i;
     for(i=0;i<n;i++)
    {
		if (rear==NULL)
		{
				rear=(struct node1*)malloc(sizeof(node1)*100);
				rear->next=NULL;
				printf("\n******************************");
				printf("\nenter id of medicine:");
                scanf("%d",&rear->id);
                printf("\nenter quantity:");
                scanf("%d",&rear->quantity);
                printf("\nenter price:");
                scanf("%f",&rear->price);
                printf("\nenter medicine name:");
                scanf("%s",rear->medicine_name);
                printf("\nenter company:");
                scanf("%s",rear->company);
                printf("\nenter info of medicine:");
                scanf("%s",rear->info);
                printf("\nenter patient name:");
                scanf("%s",rear->patient_name);
                printf("\nenter doctors name:");
                scanf("%s",rear->doctor_name);

				printf("\nenter mfg date:");
				scanf("%d/%d/%d",&(rear->dd),&(rear->mm),&(rear->yy));
				printf("\nenter exp date:");
				scanf("%d/%d/%d",&(rear->dd1),&(rear->mm1),&(rear->yy1));
                printf("\nenter patient's contact number:");
                scanf("%lld",&rear->contact_no);
				printf("\n******************************");
				front=rear;
		}
		else
		{
				temp=(struct node1*)malloc(sizeof(node1));
				printf("\n******************************");
				printf("\nenter id of medicine:");
                scanf("%d",&temp->id);
                printf("\nenter quantity:");
                scanf("%d",&temp->quantity);
                printf("\nenter price:");
                scanf("%f",&temp->price);
                printf("\nenter medicine name:");
                scanf("%s",temp->medicine_name);
                printf("\nenter company:");
                scanf("%s",temp->company);
                printf("\nenter info of medicine:");
                scanf("%s",temp->info);
                printf("\nenter patient name:");
                scanf("%s",temp->patient_name);
                printf("\nenter doctors name:");
                scanf("%s",temp->doctor_name);
                printf("\nenter mfg date:");
				scanf("%d/%d/%d",&(temp->dd),&(temp->mm),&(temp->yy));
				printf("\nenter exp date:");
				scanf("%d/%d/%d",&(temp->dd1),&(temp->mm1),&(temp->yy1));
                printf("\nenter patient's contact number:");
                scanf("%lld",&temp->contact_no);
				printf("\n******************************");
				rear->next=temp;
				temp->next=NULL;
				rear=temp;
		}
	}
}

void display_queue(node1 *front)
{
    node1 *p;
    int sum=0;
    int j=0;

    if(front==NULL)
    {
        printf("\n*Queue Empty*\n");
    }
    else
    {
        p=front;
		printf("\nid\tquantity\tprice\tmedicine_name\tcompany");
        printf("\tinfo\tpatient_name\tdoctor_name\tmfg_dt\t         exp_dt         contact");
		printf("\n\n");
		while(p!=NULL)
		{
			printf("\n%d",p->id);
            printf("\t%d",p->quantity);
            printf("\t\t%.2f",p->price);
            printf("\t\t%s",p->medicine_name);
            printf("\t%s",p->company);
            printf("\t%s",p->info);
            printf("\t%s",p->patient_name);
            printf("\t\t%s",p->doctor_name);
            printf("\t\t%d/%d/%d",(p->dd),(p->mm),(p->yy));
			printf("\t\t%d/%d/%d",(p->dd1),(p->mm1),(p->yy1));
            printf("\tlld",p->contact_no);
            p=p->next;

		}
   }
}

void del_queue()
{
    node1 *temp;
    if(front==NULL)
    {
        printf("\n*Queue Empty*\n");
    }
    else
    {
		temp = front;
		front=front->next;
		free(temp);
    }

}





