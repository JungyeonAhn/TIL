#include <stdio.h>



int main()
{
    
    int arr[100][100];
    int n,m,a,b,i,j,x=0,y=-1,flag=1;
    int num=1;

    scanf("%d%d",&n,&m);
    
    a=n;
    b=m;
    
    while(b!=0 && a!=0)
    {
        for(i=0; i<b; i++)
        {
            y+=flag;
            arr[x][y]=num;
            num++;
            
        }

        a--;
        
        for(i=0; i<a; i++)
        {
            x+=flag;
            arr[x][y]=num;
            num++;
            
        }
        b--;
        flag*=-1;
        
    }

    
    for(i=0; i<n; i++)
    {
        for(j=0; j<m;j++)
        {
            printf(" %d",arr[i][j]);
            
        }
        printf("\n");
    }

    return 0;
    
}

