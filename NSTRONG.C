#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,fact=1,temp,rem,sum=0;

	clrscr();

	printf("Enter limit n:");
	scanf("%d",&n);
	printf("The Strong Numbers Between 1 to %d are:\n",n);

	i=1;

	while(i<=n)
	{
		temp=i;
		sum=0;
			while(temp>0)
			{
			rem=temp%10;
			fact=1;

				while(rem>0)
				{
				fact=fact*rem;
				rem--;
				}
				sum=sum+fact;
				temp=temp/10;
				}
					if(sum==i)
					{
					printf("%d\t",i);
					}



		i++;
	}

	getch();
	}
