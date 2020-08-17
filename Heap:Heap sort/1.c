#include <stdio.h>
#include <stdlib.h>

int n;
int H[100];

void upHeap(int i)
{
	int tmp;
	while(i>1 && H[i/2]<H[i])
	{
		tmp=H[i];
		H[i]=H[i/2];
		H[i/2]=tmp;
		i=i/2;
	}
}
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
void insertItem(int key)
{
	n=n+1;
	H[n]=key;
	upHeap(n);
	printf("0\n");
}
int removeMax()
{
	int key;
	key=H[1];
	H[1]=H[n];
	n=n-1;
	downHeap(1);
	return key;
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
	char c;
	int key;
	while(1)
	{
		scanf("%c",&c);
		switch(c)
		{
		case 'i':
			scanf("%d",&key);
			insertItem(key);
			break;
		case 'd':
			printf("%d\n",removeMax());
			break;
		case 'p':
			printHeap();
			break;
		case 'q':
			break;
		}
		if(c=='q') break;
		getchar();
	}
	return 0;
}