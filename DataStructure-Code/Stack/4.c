#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1;
int StackSize=100;

void push(char *stack, char c){
    if(top==StackSize-1)
        return;
    //printf("Stack FULL\n");
    else
        stack[++top]=c;
}
char pop(char *stack){
    if(top==-1){
        //printf("Stack Empty\n");
        return -1;
    }
    else
        return stack[top--];
}



int main()
{
    int n,i,j,a,b,result=0;
    char str[100];
    char *stack=(char*)malloc(sizeof(char)*StackSize);
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%s",str);
        top=-1;
        result=0;
        for(j=0;j<strlen(str);j++){
            
            if(str[j]=='*'){
                a=pop(stack);
                b=pop(stack);
                result=a*b;
                push(stack,result);
            }
            else if(str[j]=='/'){
                a=pop(stack);
                b=pop(stack);
                result=b/a;
                push(stack,result);
            }
            else if(str[j]=='+'){
                a=pop(stack);
                b=pop(stack);
                result=a+b;
                push(stack,result);
            }
            else if(str[j]=='-'){
                a=pop(stack);
                b=pop(stack);
                result=b-a;
                push(stack,result);
            }
            else
                push(stack,str[j]-48);
        }
        printf("%d\n",pop(stack));
    }
    
}
