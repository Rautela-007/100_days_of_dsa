#include <stdio.h>
#include <string.h>
int a[1000],sz=0;
void up(int i){while(i&&a[(i-1)/2]>a[i]){int t=a[i];a[i]=a[(i-1)/2];a[(i-1)/2]=t;i=(i-1)/2;}}
void down(int i){
while(2*i+1<sz){
int j=2*i+1;
if(j+1<sz && a[j+1]<a[j]) j++;
if(a[i]<=a[j]) break;
int t=a[i];a[i]=a[j];a[j]=t;i=j;
}}
int main(){
int n;
printf("Enter number of min heap operations:\n");
scanf("%d",&n);
printf("Enter operations: insert value, peek, or extractMin\n");
while(n--){
char op[20];scanf("%s",op);
if(strcmp(op,"insert")==0){int x;scanf("%d",&x);a[sz]=x;up(sz++);}
if(strcmp(op,"peek")==0){if(sz==0) printf("-1\n"); else printf("%d\n",a[0]);}
if(strcmp(op,"extractMin")==0){
if(sz==0) printf("-1\n");
else{printf("%d\n",a[0]);a[0]=a[--sz];down(0);}
}}
return 0;}
