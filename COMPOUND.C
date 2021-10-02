#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float p,r,t,i,n;

	clrscr();

	printf("Enter the Principal Amount:");
	scanf("%f",&p);
	printf("Enter the Rate of Interest:");
	scanf("%f",&r);
	printf("Enter the Time Period:");
	scanf("%f",&t);


	i=p*(pow(1+r/100,t));

	printf("The Compound Interest is %.2f.",i);

	getch();

	}

