#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1;
int StackSize=1000;

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
    char str[1000], stack[1000],data;
    int i,cnt=0,flag=0;
    gets(str);
    
    for(i=0;i<strlen(str);i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            push(stack,str[i]);
            cnt++;
        }
        if(str[i]==')' || str[i]==']' || str[i]=='}'){
            data=pop(stack);
            cnt++;
            if(str[i]==')' && data!='(')
                flag=-1;
            if(str[i]==']' && data!='[')
                flag=-1;
            if(str[i]=='}' && data!='{')
                flag=-1;
        }
    }
    if(top==-1 && flag!=-1)
         printf("OK_%d\n",cnt);
    else
        printf("Wrong_%d\n",cnt);

    
    
}
