#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char st[100];
int top=-1;

int Isoperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='(' || ch==')' || ch=='{' || ch=='}' || ch=='[' || ch==']' || ch=='^'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+'|| ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char ch){
    top++;
    st[top]=ch;
}

char pop(){
    char ch=st[top];
    top--;
    return ch;
}

char stacktop(){
    return st[top];
}

int Isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

char *infTOpo(char *infix){
    char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));

    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!Isoperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(infix[i]=='('){
                push(infix[i]);
                i++;
            }
            else if(infix[i]==')'){
                do{
                    postfix[j]=pop();
                    j++;
                }while(st[top]!='(');
                top--;
                i++;
            }
            else if(precedence(infix[i])>precedence(stacktop())){
                push(infix[i]);
                i++;
            }
            else if(precedence(infix[i])<precedence(stacktop())){
                postfix[j]=pop();
                j++;
            }
            else if(precedence(infix[i])==precedence(stacktop())){
                if(infix[i]=='^'){
                    push(infix[i]);
                    i++;
                }
                else if(infix[i]=='*' || infix[i]=='/' || infix[i]=='+' || infix[i]=='-'){
                    postfix[j]=pop();
                    j++;
                    push(infix[i]);
                    i++;
                }
            }
        }
    }

    while(!Isempty()){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    printf("hsdj");
    char *infix="a-b+(m^n)*(o+P)-q/r^s*t+z";
    printf("Postfix is %s", infTOpo(infix));
    return 0;
}