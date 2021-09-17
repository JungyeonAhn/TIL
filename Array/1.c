#include <stdio.h>

void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void reverse(int *x,int a, int b)
{
    int i;
    for(i=0;i<=(b-a)/2;i++)
    {
        swap(x+a+i,x+b-i);
    }
    
}
//3 81 9 12 0 –9 36 33 91 10
int main()

{
    int n,x[100];
    int i;
    int m,a,b;

    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    
    scanf("%d",&m);
    
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        reverse(x,a,b);
    }
    
    for(i=0;i<n;i++)
        printf(" %d",x[i]);
    printf("\n");
    
    return 0;
}
