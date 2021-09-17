#include <stdio.h>
#include <stdlib.h>

int n;
int H[100];

void downHeap(int i)
{
	int l,r,largest,tmp;
	l=2*i;
	r=2*i+1;
	largest=i;
	if(l<=n && H[l]>H[i])
		largest=l;
	if(r<=n && H[r]>H[largest])
		largest=r;
	if(largest!=i)
	{
		tmp=H[i];
		H[i]=H[largest];
		H[largest]=tmp;
		downHeap(largest);
	}
}
void rBuildHeap(int i)
{
	if(i>n)
		return;
	rBuildHeap(2*i);
	rBuildHeap(2*i+1);
	downHeap(i);
	return;
}
void buildHeap()
{
	int i;
	for(i=n/2;i>=1;i--)
		downHeap(i);
}
void printHeap()
{
	int i;
	for(i=1;i<=n;i++)
		printf(" %d",H[i]);
	printf("\n");
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&H[i]);
	rBuildHeap(1);
	buildHeap();
	printHeap();
	return 0;
}