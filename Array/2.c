#include <stdio.h>

void changelocate(int *a,int m, int *x)
{
    int i,tmp;
    tmp=x[a[0]];
    for(i=m-1;i>=1;i--)
    {
        x[a[i]]=x[a[i-1]];
    }
    x[a[1]]=tmp;
}
//3 81 9 12 0 –9 36 33 91 10
int main()

{
    int n,x[100];
    int i;
    int m,a[100];

    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    
    scanf("%d",&m);
    
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    changelocate(a, m, x);
    
    for(i=0;i<n;i++)
        printf(" %d",x[i]);
    printf("\n");
    
    return 0;
}
