#include <stdio.h>
void heapify(int a[],int n,int i){
int l=2*i+1,r=2*i+2,ma=i;
if(l<n&&a[l]>a[ma]) ma=l;
if(r<n&&a[r]>a[ma]) ma=r;
if(ma!=i){int t=a[i];a[i]=a[ma];a[ma]=t;heapify(a,n,ma);}
}
int main(){
int n;
printf("Enter number of elements:\n");
scanf("%d",&n);
int a[1000];
printf("Enter %d array elements separated by spaces:\n",n);
for(int i=0;i<n;i++) scanf("%d",&a[i]);
for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
for(int i=n-1;i>=0;i--){int t=a[0];a[0]=a[i];a[i]=t;heapify(a,i,0);}
printf("Sorted array: ");
for(int i=0;i<n;i++){printf("%d",a[i]);if(i<n-1) printf(" "); }
printf("\n");
return 0;}
