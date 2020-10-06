#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
     ll n;
     cin>>n;
     vector<ll> A(n);
     for(auto& x:A)
	cin>>x;
      ll dp[n+1][2];
      for(int i=0;i<=n;i++)
	  dp[i][0]=dp[i][1]=0;
      for(int i=1;i<=n;i++){
	  for(int j=0;j<i;j++){
	      if(A[i-1]==1){
		  if(j!=i-1){
		      dp[i][0]=max(dp[i][0],max(dp[j][0],dp[j][1])+1);
		      dp[i][1]=max(dp[i][1],dp[j][1]);
		  }
		  else{
		      dp[i][0]=max(dp[i][0],dp[j][1]+1);
		      dp[i][1]=max(dp[i][1],dp[j][1]);
		  }
	      }
		  
	      else if(A[i-1]==2){
		  if(j!=i-1){
		      dp[i][0]=max(dp[i][0],dp[j][0]);
		      dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+1);
		  }
		  else{
		      dp[i][0]=max(dp[i][0],dp[j][0]);
		      dp[i][1]=max(dp[i][1],dp[j][0]+1);
		  }
		  
	      }
	       else if(A[i-1]==3){
		  if(j!=i-1){
		      dp[i][0]=max(dp[i][0],max(dp[j][0],dp[j][1])+1);
		      dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+1);
		  }
		  else{
		      dp[i][0]=max(dp[i][0],dp[j][1]+1);
		      dp[i][1]=max(dp[i][1],dp[j][0]+1);
		  }
		  
	      }
	      else{
		  dp[i][0]=max(dp[i][0],dp[j][0]);
		  dp[i][1]=max(dp[i][1],dp[j][1]);
		}
	}
    }
    cout<<n-max(dp[n][0],dp[n][1])<<"\n";
	      
	      
		  
      
}

