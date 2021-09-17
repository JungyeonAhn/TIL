#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, n, m = 0, i = 0;
	char str[30] = { NULL };
	scanf("%d %d %d", &a, &b, &n);
	getchar();
	gets(str);
	while (a <= b || i < n)
	{
		m = (a + b) / 2;
		if (str[i] == 'Y')
			a = m + 1;
		else if (str[i] == 'N')
			b = m;
		i++;
	}
	printf("%d", m);
	return 0;
}