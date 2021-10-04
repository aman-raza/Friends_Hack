#include<stdio.h>
void main()
{
	int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the value of array");
	for (i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("value of array\n");
	for (i=0; i<n; i++)
	{
		printf("%d",a[i]);
		
	}
	printf("reverse array is\n");
	for (i=n-1; i>=0; i--)
	{
		printf("%d ",a[i]);
	}
}
