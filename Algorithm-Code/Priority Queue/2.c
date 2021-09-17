#include <stdio.h>
#include <stdlib.h>
int* InsertSort(int *p,int n)
{
	int j, i, key;
	for(j=1;j<n;j++)
	{
		key=p[j];
		i=j-1;
		while(i>=0 && p[i]>key)
		{
			p[i+1]=p[i];
			i=i-1;
		}
		p[i+1]=key;
	}
	return p;
}
int main()
{
	int n,i,j,key;
	int *p=NULL;
	scanf("%d",&n);
	p=(int *)malloc(n*sizeof(int));
	for(j=0;j<n;j++)
		scanf("%d",&p[j]);

	p=InsertSort(p,n);

	for(j=0;j<n;j++)
		printf(" %d",p[j]);


	free(p);
	return 0;
}