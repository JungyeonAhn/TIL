#include <stdio.h>

int findmax(int x[],int n)
{
    int max;
    if(n==1)
        return x[0];
    max=findmax(x,n-1);
    if(x[n-1]>max)
        return x[n-1];
    else
        return max;
}

int main()
{
    int n,i;
    int x[20],max;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    
    max=findmax(x,n);

    printf("%d",max);
    
    return 0;
}
