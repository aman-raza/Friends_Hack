#include<stdio.h>
int main()
{
  int i,j,k,n;
  printf("no.");
  scanf("%d",&n);
  for(i=0;i<=n;i++)
  {
    for(j=1;j<=i;j++)
    {
      printf("%d",j);
    }
    printf("1\n");
  }
  return 0;
}
