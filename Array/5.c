#include <stdio.h>
int main()
{
    int a[100][100]={0};
    int i,j,num=1;
    int n,m,z=0;

    scanf("%d %d",&n,&m);
   
    while(z!=n+m)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(z== i+j)
                    a[i][j]=num++;
            }
            
        }
        z++;
    }
    
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
