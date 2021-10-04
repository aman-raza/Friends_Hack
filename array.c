#include<stdio.h>
void main()
{
	int n,i;
	printf("enter the value of array\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the value of 1D array\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("element of 1D array\n");
	for(i=0; i<n; i++)
	{
		printf("value of a[%d]=%d\n",i,a[i]);
		printf("address of a[%d]=%d\n",i,&a[i]);
	}
}
