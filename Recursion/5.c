#include <stdio.h>

void moveh(char from,char to)
{
    printf("%c %c\n",from,to);
}
void hanoi(int n,char from,char by,char to)
{
    if(n==1)
        moveh(from,to);
    else{
        
        hanoi(n - 1, from, to, by);    // 1번  N-1개의 원반을 기둥C을 거쳐 B로 옮긴다.
        moveh(from, to);                // 2번 기둥 A에서 1개의 원반을 기둥 C으로 옮긴다.
        hanoi(n - 1, by, from, to);    // 3번 기둥 B에서 N-1개의 원반을 기둥 C으로 옮긴다
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    hanoi(n,'A', 'B', 'C');
    
    return 0;
}
