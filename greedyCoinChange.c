#include<stdio.h>
#include<stdlib.h>
int compare(void const *a,void const *b){
  return *(int*)b-*(int*)a;
}
int coinChange(int coins[],int n,int amount){
  int num,count=0,i=0;
  while(amount!=0){
    num=amount/coins[i];
    amount-=num*coins[i];
    count+=num;
    i++;
  }
 return count;
}
int main(){
  int n,amount;
  scanf("%d %d",&n,&amount);
  int coins[n];
  for(int i=0;i<n;i++){
    scanf("%d ",&coins[i]);
  }
  qsort(coins,n,sizeof(int),compare);
  printf("%d ",coinChange(coins,n,amount));
  return 0;
}