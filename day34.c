#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{int data;struct node* next;}n;
n* top=NULL;
void push(int x){n* t=malloc(sizeof(n));t->data=x;t->next=top;top=t;}
int pop(){int x=top->data;n* t=top;top=top->next;free(t);return x;}
int main(){
char s[1000];
printf("Enter postfix expression with spaces:\n");
fgets(s,1000,stdin);
char* t=strtok(s," ");
while(t){
if(t[0]>='0'&&t[0]<='9') push(atoi(t));
else{
int b=pop(),a=pop();
if(t[0]=='+') push(a+b);
if(t[0]=='-') push(a-b);
if(t[0]=='*') push(a*b);
if(t[0]=='/') push(a/b);
}
t=strtok(NULL," ");
}
printf("Postfix result: %d\n",pop());
return 0;}
