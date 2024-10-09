#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int ele){
    if(top == MAX-1){
        printf(" OVERFLOW \n");
    }
    else{
        top++;
        stack[top] = ele;
        printf("pushed\n");
    }
}

void pop(){
    if(top == -1){
        printf(" UNDERFLOW \n");
    }
    else{
        top--;
        printf("popped \n");
    }
}

void display(){
    if(top == -1){
        printf("the stack is empty \n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d \n",stack[i]);
        }
    }
}

int main(){
    push(5);
    push(10);                
    push(15);
    push(20);
    display();
    pop();
    pop();
    display();
}
