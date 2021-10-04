#include<stdio.h>
void main()
{
	int i,n,sum=0;
	printf("how many times want to enter\n");
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
	for(i=0; i<n; i++)
	{
		sum=sum +a[i];
	}
	printf("sum of 1D array=%d",sum);
}
