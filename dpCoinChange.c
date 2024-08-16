#include<stdio.h>
int dpCoinChange(int coins[],int n,int amount){
  int dp[amount+1];
  dp[0]=0;
  for(int i=0;i<n;i++) dp[coins[i]]=1;
  
  for(int i=1;i<=amount;i++){
    if(dp[i]==1) continue;
    else{
      int min=INT_MAX;
      for(int j=0;j<n && coins[j]<=i;j++){
        if(min > dp[i-coins[j]])
          min=dp[i-coins[j]);
      }
      dp[i]=min+1;
   }
  }
  return dp[amount];
}
