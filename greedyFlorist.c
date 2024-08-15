#include<stdio.h>
#include<stdlib.h>
int compare(void const *a,void const *b){
  return *(int*)b-*(int*)a;
}
int greedyFlorist(int b[],int n,int m){
  int f[m],total=0;
  for(int i=0;i<m;i++) f[i]=0;
  for(int i=0,j=0;i<n;i++,j=(j+1)%m){
     total+=b[i]*(1+f[j]); 
     f[j]++;  
   }
   return total;
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int b[n];
  for(int i=0;i<n;i++){
    scanf("%d ",&b[i]);
  }
  qsort(b,n,sizeof(int),compare);
  printf("%d ",greedyFlorist(b,n,m));
  return 0;
}