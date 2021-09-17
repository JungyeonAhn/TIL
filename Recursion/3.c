#include <stdio.h>

int print(int n)
{
    if(n==0)
        return 1;
    
    printf("%d\n",n%10);
    
    return print(n/10);
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    print(n);
    
    return 0;
}
