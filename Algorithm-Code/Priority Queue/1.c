#include <stdio.h>
#include <stdlib.h>

int* SelectionSort(int *A, int n)
{
	int i,j, max,tmp;
	for(i=n-1;i>=0;i--)
	{
		max=i;
		for(j=i-1;j>=0;j--)
		{
			if(A[j]>A[max])
				max=j;
		}
		tmp=A[max];
		A[max]=A[i];
		A[i]=tmp;
	}
	return A;
}
int main()
{
	int n,i,j,max,tmp;
	int *A;
	scanf("%d",&n);
	A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	A=SelectionSort(A,n);
	for(i=0;i<n;i++)
		printf(" %d",A[i]);
	free(A);
	return 0;
}
