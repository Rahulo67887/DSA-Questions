#include <stdio.h>
#include<stdlib.h>

# define N 20
char stack[N];
int top=-1;

void push(char x){
    if(top==N-1){
        printf("Stack overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    top--;
}

void paranthesis(char *paran){
    for(int i=0; paran[i]!='\0'; i++){
        if(paran[i]=='(' || paran[i]=='{' || paran[i]=='['){
            push(paran[i]);
        }
        else if(paran[i]==')' || paran[i]=='}' || paran[i]==']') {
            if(top==-1){
                printf("Unbalanced Paranthesis");
                return;
            }
            else if(((paran[i]==')' && stack[top]!='(') || (paran[i]=='}' && stack[top]!='{') || (paran[i]==']' && stack[top]!='['))){
                printf("Unbalanced Paranthesis");
                return;
            }
            if((paran[i]==')' && stack[top]=='(') || (paran[i]=='}' && stack[top]=='{') || (paran[i]==']' && stack[top]=='[')){
                pop();
            }
        }
    }
    if(top!=-1){
        printf("Unbalanced Paranthesis");
    }
    else if(top==-1){
        printf("Paranthesis is balanced");
    }
}

int main(){
    char paran[]="(})";
    paranthesis(paran);

    
    return 0;
}