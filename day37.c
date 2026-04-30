#include <stdio.h>
#include <string.h>
int main(){
int n;
printf("Enter number of priority queue operations:\n");
scanf("%d",&n);
int a[1000],sz=0;
printf("Enter operations: insert value, delete, or peek\n");
while(n--){
char op[10];scanf("%s",op);
if(strcmp(op,"insert")==0){int x;scanf("%d",&x);a[sz++]=x;}
else if(strcmp(op,"delete")==0){
if(sz==0) printf("-1\n");
else{
int mi=0;
for(int i=1;i<sz;i++) if(a[i]<a[mi]) mi=i;
printf("%d\n",a[mi]);
for(int i=mi;i<sz-1;i++) a[i]=a[i+1];
sz--;
}}
else if(strcmp(op,"peek")==0){
if(sz==0) printf("-1\n");
else{
int mi=0;
for(int i=1;i<sz;i++) if(a[i]<a[mi]) mi=i;
printf("%d\n",a[mi]);
}}}
return 0;}
