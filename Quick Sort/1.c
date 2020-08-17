#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) { 
	int tmp; 
	tmp = *a; 
	*a = *b;
	*b = tmp;
}
int find_pivot_index(int*A, int start, int end)
{
	int a, b, c, mid;
	
	a = start + rand() % (end - start);
	b = start + rand() % (end - start);
	c = start + rand() % (end - start);
	
	mid = a < b ? (a > c ? a : c < b ? c : b) : b > c ? b : (c < a ? c : a);
	
	return mid;
}
int partition(int *A,int start,int end)
{
	int pivot,i,mid,pivot_index;
	int pIndex = start;
	
	pivot_index = find_pivot_index(A,start, end);
	swap(&A[pivot_index], &A[end]);
	pivot = A[end];
	
	for (i = start; i < end ; i++)
	{
		if (A[i] <= pivot)
		{
			swap(&A[i], &A[pIndex]);
			pIndex = pIndex + 1;
		}
	}
	swap(&A[pIndex], &A[end]);
	return pIndex;
}
int* quickSort(int *A, int start, int end)
{
	int pIndex;
	if (start < end)
	{
		pIndex = partition(A, start, end);
		quickSort(A, start, pIndex - 1);
		quickSort(A, pIndex + 1,end);
	}
	return A;
}
int main()
{
	int n, i,num;
	int *A;
	scanf("%d", &n);
	
	A = (int*)malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
		
	quickSort(A, 0, n-1);
	
	for (i = 0; i < n; i++)
		printf(" %d", A[i]);
		
	printf("\n");

	return 0;
}