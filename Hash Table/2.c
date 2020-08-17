#include <stdio.h>
#include <stdlib.h>
int hashfunction(int x, int M)
{
	return x % M;
}
void inizilizeHtable(int *H, int M)
{
	int i;
	for (i = 0; i < M; i++)
	{
		H[i] = 0;
	}
}
int getNextBucket(int x, int i, int M)
{
	return (hashfunction(x,M) + i) % M;
}
void insert(int *H, int M, int x)
{
	int code;
	int i = 0;
	while (i < M)
	{
		code = getNextBucket(x, i, M);
		if (H[code] == 0)
		{
			H[code] = x;
			printf("%d\n", code);
			return;
		}
		else
		{
			printf("C");
			i = i + 1;
		}
	}
}
void search(int *H, int M, int x)
{
	int code;
	int i = 0;
	while (i < M)
	{
		code = getNextBucket(x, i, M);
		if (H[code] == 0) {
			printf("-1\n");
			return;
		}
		else if(x == H[code])
		{
			printf("%d %d\n", code, H[code]);
			return;
		}
		else
			i = i + 1;
	}
}
void print(int *H, int M)
{
	int i;
	for (i = 0; i < M; i++)
	{
		printf(" %d", H[i]);
	}
	printf("\n");
}
int main()
{
	int M, N, x, i, cnt = 0;
	int *H;
	char c;
	scanf("%d %d", &M, &N);
	H = (int*)malloc(sizeof(int)*M);
	inizilizeHtable(H, M);
	while (1)
	{
		getchar();
		scanf("%c", &c);
		if (c == 'e')
			break;
		else if (c == 'i' && cnt < N)
		{
			cnt++;
			scanf("%d", &x);
			insert(H, M, x);
		}
		else if (c == 's')
		{
			scanf("%d", &x);
			search(H, M, x);
		}
		else
			continue;
	}
	free(H);
	return 0;
}