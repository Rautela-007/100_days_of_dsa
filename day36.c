#include <stdio.h>
int main(){
int n;
printf("Enter number of queue elements:\n");
scanf("%d",&n);
int a[1000];
printf("Enter %d queue elements separated by spaces:\n",n);
for(int i=0;i<n;i++) scanf("%d",&a[i]);
int m;
printf("Enter number of positions to rotate left:\n");
scanf("%d",&m);
printf("Rotated queue: ");
for(int i=0;i<n;i++){
int idx=(i+m)%n;
printf("%d",a[idx]);
if(i<n-1) printf(" ");
}
printf("\n");
return 0;}
