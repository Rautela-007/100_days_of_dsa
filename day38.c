#include <stdio.h>
#include <string.h>
int a[1000],f=0,r=-1;
int main(){
int n;
printf("Enter number of deque operations:\n");
scanf("%d",&n);
printf("Enter operations: push_front value, push_back value, pop_front, pop_back, front, back, size, or empty\n");
while(n--){
char op[20];scanf("%s",op);
if(strcmp(op,"push_front")==0){int x;scanf("%d",&x);for(int i=r+1;i>0;i--)a[i]=a[i-1];a[0]=x;r++;}
if(strcmp(op,"push_back")==0){int x;scanf("%d",&x);a[++r]=x;}
if(strcmp(op,"pop_front")==0 && r>=0){for(int i=0;i<r;i++)a[i]=a[i+1];r--;}
if(strcmp(op,"pop_back")==0 && r>=0){r--;}
if(strcmp(op,"front")==0) printf("%d\n",r>=0?a[0]:-1);
if(strcmp(op,"back")==0) printf("%d\n",r>=0?a[r]:-1);
if(strcmp(op,"size")==0) printf("%d\n",r+1);
if(strcmp(op,"empty")==0) printf("%d\n",r==-1);
}
return 0;}
