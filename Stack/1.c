#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1;
int StackSize;

void push(char *stack, char c){
    if(top==StackSize-1)
        printf("Stack FULL\n");
    else
        stack[++top]=c;
}
char pop(char *stack){
    if(top==-1){
        printf("Stack Empty\n");
        return -1;
    }
    else
        return stack[top--];
    
}
void peek(char *stack){
    if(top==-1){
        printf("Stack Empty\n");
    }
    else
        printf("%c\n",stack[top]);
}
void duplicate(char *stack){
    if(top==StackSize-1)
        printf("Stack FULL\n");
    else{
        char c = pop(stack);
        push(stack,c);
        push(stack,c);
    }
    
}
void upRotate(char *stack,int n){
    char c,tmp[StackSize];
    if(n>top+1)
        return;
    c=pop(stack);
    for(int i=0;i<n-1;i++){
        tmp[i]=pop(stack);
    }
    push(stack,c);
    for(int i=n-2;i>=0;i--){
        push(stack,tmp[i]);
    }
}
void downRotate(char *stack,int n){
    char c,tmp[StackSize];
    if(n>top+1)
        return;
    for(int i=0;i<n-1;i++){
        tmp[i]=pop(stack);
    }
    c=pop(stack);
    for(int i=n-2;i>-1;i--){
        push(stack,tmp[i]);
    }
    push(stack,c);
    
}
void print(char *stack){
    for (int i =top; i >-1; i--){
        printf("%c", stack[i]);
    }
    printf("\n");
}
int main()
{
    int n,m,i;
    char *stack, str[10],c;
    
    scanf("%d%d",&StackSize,&m);
    stack=(char*)malloc(sizeof(char)*StackSize);
    
    for(i=0;i<m;i++){
        getchar();
        scanf("%s",str);
        if(strcmp(str,"POP")==0){
            pop(stack);
        }
        else if(strcmp(str,"PUSH")==0){
            getchar();
            scanf("%c",&c);
            push(stack,c);
        }
        else if(strcmp(str,"PEEK")==0){
            peek(stack);
        }
        else if(strcmp(str,"DUP")==0){
            duplicate(stack);
        }
        else if(strcmp(str,"UpR")==0){
            scanf("%d",&n);
            upRotate(stack,n);
        }
        else if(strcmp(str,"DownR")==0){
            scanf("%d",&n);
            downRotate(stack,n);
        }
        else if(strcmp(str,"PRINT")==0){
            print(stack);
        }
        
        
    }
    
    
    free(stack);
    
}
