#include <stdio.h>
#include <string.h>

int findchar(char s[],int n,char c,int cnt)
{
    if(n==0)
        return cnt;
    
    if(s[n-1]==c)
        cnt++;
    
    cnt=findchar(s,n-1, c,cnt);
    return cnt;
}

int main()
{
    char str[101],c;
    int n;
    scanf("%s",str);
    getchar();
    n=strlen(str);
    
    scanf("%c",&c);
    
    printf("%d\n",findchar(str,n,c,0));
    
    return 0;
}
