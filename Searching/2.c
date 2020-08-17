#include <stdio.h>
#include <stdlib.h>

int FindElement(int*A,int k, int l, int r)
{
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (k == A[mid])
			break;
		else if (k < A[mid])
			r = mid-1;
		else if (k > A[mid])
			l = mid+1;
	}
	if (k > A[mid]) return mid + 1;
	return mid;
}
int main()
{
	int n, k,i;
	int *A;
	scanf("%d%d", &n, &k);
	A = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	i=FindElement(A,k, 0, n - 1);
	printf(" %d", i);
	return 0;
}