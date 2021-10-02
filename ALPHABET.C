#include<stdio.h>
#include<conio.h>

void main()
{
	char c;

	clrscr();

	printf("Enter the Character:");
	scanf("%c",&c);

	if((c>='a'&& c<='z') || (c>='A'&& c<='Z'))
	{
	printf("It is an Alphabet.");
	}

	else
	{
	printf("It is not an Alphabet.");
	}

	getch();

	}