#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *A, int l, int r, int k)
{
	int mid = (l + r) / 2;
	if (l <= r)
	{
		if (k == A[mid])
			return mid;
		else if (k < A[mid])
			return binarySearch(A, l, mid - 1, k);
		else if (k > A[mid])
			return binarySearch(A, mid + 1, r, k);
	}
	else
	{
		if (mid == 0) return -1;
		return mid;
	}
}
int main()
{
	int *A;
	int n, i, index,k;
	scanf("%d %d", &n,&k);
	A = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	index = binarySearch(A, 0, n - 1, k);

	printf("%d", index);

	return 0;
}