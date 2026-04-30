#include <stdio.h>
#include <ctype.h>
char s[1000];int top=-1;
int p(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/')return 2;return 0;}
int main(){
char exp[1000];
printf("Enter infix expression:\n");
scanf("%s",exp);
printf("Postfix expression: ");
for(int i=0;exp[i];i++){
char c=exp[i];
if(isalnum(c)) printf("%c",c);
else{
while(top!=-1 && p(s[top])>=p(c)) printf("%c",s[top--]);
s[++top]=c;
}}
while(top!=-1) printf("%c",s[top--]);
printf("\n");
return 0;}
