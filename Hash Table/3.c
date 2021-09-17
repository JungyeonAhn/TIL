#include <stdio.h>
#include <stdlib.h>
int hashfunction(int x, int M)
{
	return x % M;
}
int hashfunction2(int x, int q)
{
	return q - (x % q);
}
int getNextBucket(int x, int i, int M, int q)
{
	return (hashfunction(x, M) + i * hashfunction2(x, q)) % M;
}
void inizilizeHtable(int *H, int M)
{
	int i;
	for (i = 0; i < M; i++)
	{
		H[i] = 0;
	}
}
void insert(int *H, int M, int x, int q)
{
	int code;
	int i = 0;
	while (i < M)
	{
		code = getNextBucket(x, i, M, q);
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
void search(int *H, int M, int x, int q)
{
	int code;
	int i = 0;
	while (i < M)
	{
		code = getNextBucket(x, i, M, q);
		if (H[code] == 0) {
			printf("-1\n");
			return;
		}
		else if (x == H[code])
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
	int M, N, x, i, cnt = 0, q;
	int *H;
	char c;
	scanf("%d %d %d", &M, &N, &q);
	H = (int*)malloc(sizeof(int)*M);
	inizilizeHtable(H, M);
	while (1)
	{
		getchar();
		scanf("%c", &c);
		if (c == 'e')
		{
			print(H, M);
			break;
		}
		else if (c == 'i' && cnt < N)
		{
			cnt++;
			scanf("%d", &x);
			insert(H, M, x, q);
		}
		else if (c == 's')
		{
			scanf("%d", &x);
			search(H, M, x, q);
		}
		else if (c == 'p')
			print(H, M);
		else
			continue;
	}
	free(H);
	return 0;
}