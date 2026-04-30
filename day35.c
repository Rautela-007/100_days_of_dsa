#include <stdio.h>
int main(){
int n;
printf("Enter number of queue elements:\n");
scanf("%d",&n);
int a[1000];
printf("Enter %d queue elements separated by spaces:\n",n);
for(int i=0;i<n;i++) scanf("%d",&a[i]);
printf("Queue elements: ");
for(int i=0;i<n;i++){printf("%d",a[i]);if(i<n-1) printf(" "); }
printf("\n");
return 0;}
