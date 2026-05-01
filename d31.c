//Stack Implementation Using Array
#include <stdio.h>
#include <stdlib.h>
int stackoperations();
void display();
int pop();
int peek();
int push();

int top=-1;
int stack[100];

int main(){
    stackoperations();
    return 0;
}

int stackoperations(){
    int i;
    printf("\nStack Operations");
    printf("\n1- Display Stack");
    printf("\n2- Pop");
    printf("\n3- Push");
    printf("\n4- Peek");
    printf("\n=>> ");
    scanf("%d",&i);
    if (i == 1)
        display();
    else if (i== 2)
        pop();
    else if (i==3) 
        push();
    else if (i==4)
        peek();
    else
        printf("Invalid choice");
    stackoperations();
}
void display(){
    if (top == -1){
        printf("Stack is Empty");
        stackoperations();
    }
    for (int k=top ; k>=0 ; k--){
        if (k==top) {
            printf("%d <-top",stack[k]);
            printf("\n");
        }
        else{
            printf("%d",stack[k]);
            printf("\n");
        }
    }  
}
int pop(){
    if (top == -1){
        printf("Stack Underflow");
        stackoperations();
    }
    int value=stack[top];
    top--;
    printf("Pop value is = %d",value);
}
int peek(){
    if (top==-1){
        printf("Stack Underflow");
    }
    int value = stack[top];
    printf("%d",value);
}
int push(){
    if (top == 99){
        printf("Stack Overflow");
        stackoperations();
    }
    int value;
    char ch='y';
    while ((ch=='y') || (ch=='Y')){
        printf("Enter value => ");
        top++;
        scanf("%d",&stack[top]);
        if (top==99){
            printf("Stack overflow");
            break;
        }
        printf("If You want to add more Press y or Not for N");
        scanf(" %c",&ch);
    }
}
