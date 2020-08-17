#include <stdio.h>

int main()

{
    int n,k;
    int x[100][100];
    int i,j;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        if(i%2==0){
            k=i*n+1;
            for(j=0;j<n;j++)
                printf(" %d",k++);
        }
        else{
            k=n*(i+1);
            for(j=0;j<n;j++)
                printf(" %d",k--);
        }
        printf("\n");
    }
    
    
    return 0;
}
