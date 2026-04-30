#include <stdio.h>
int main(){
int n;
printf("Enter number of stack elements:\n");
scanf("%d",&n);
int a[1000],top=-1;
printf("Enter %d stack elements separated by spaces:\n",n);
for(int i=0;i<n;i++){int x;scanf("%d",&x);a[++top]=x;}
int m;
printf("Enter number of elements to pop:\n");
scanf("%d",&m);
for(int i=0;i<m;i++) if(top>=0) top--;
printf("Stack after popping: ");
for(int i=top;i>=0;i--){printf("%d",a[i]);if(i>0) printf(" "); }
printf("\n");
return 0;}
