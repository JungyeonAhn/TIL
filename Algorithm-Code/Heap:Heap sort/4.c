#include <stdio.h>
#include <stdlib.h>

int n = 0;
int H[100];

void upHeap(int i)
{
	int tmp;
	while (i>1 && H[i / 2]<H[i])
	{
		tmp = H[i];
		H[i] = H[i / 2];
		H[i / 2] = tmp;
		i = i / 2;
	}
}
void downHeap(int i)
{
	int l, r, largest, tmp;
	l = 2 * i;
	r = 2 * i + 1;
	largest = i;
	if (l <= n && H[l]>H[i])
		largest = l;
	if (r <= n && H[r]>H[largest])
		largest = r;
	if (largest != i)
	{
		tmp = H[i];
		H[i] = H[largest];
		H[largest] = tmp;
		downHeap(largest);
	}
}
void insertItem(int key)
{
	n = n + 1;
	H[n] = key;
	upHeap(n);
}
void rBuildHeap(int i)
{
	if (i>n)
		return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
	return;
}
void buildHeap()
{
	int i;
	for (i = n / 2; i >= 1; i--)
		downHeap(i);
}
void inPlaceHeapSort()
{
	int i, tmp, len;
	buildHeap();
	len = n;
	for (i = len; i >= 2; i--)
	{
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		n = n - 1;
		downHeap(1);
	}
	n = len;
}
void printArray()
{
	int i;
	for (i = 1 ; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}
int main()
{
	int i, key, x;
	scanf("%d", &x);

	for (i = 0; i < x; i++)
	{
		scanf("%d", &key);
		insertItem(key);
	}
	inPlaceHeapSort();
	printArray();

	return 0;
}