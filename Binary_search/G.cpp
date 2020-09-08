#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll E=10e8+7;
ll bin_exp(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1)
            res=res*a;
        a*=a;
        n>>=1;
    }
    return res;
}

void extended_gcd(ll a,ll b,ll& x,ll&y){
    ll x1=0;
    ll y1=1;
    ll a1=a;
    ll b1=b;
    while(b1){
        ll q=(a1/b1);
        tie(x,x1)=make_tuple(x1,x-q*x1);
        tie(y,y1)=make_tuple(y1,y-q*y1);
        tie(a1,b1)=make_tuple(b1,a1%b1);
    }
    
    return ;
}

ll test_case(ll n,vector<ll> A){
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        
        for(auto x:A){
            if(i>=x && dp[i-x]!=0){
                dp[i]+=dp[i-x];    
            }
        }
    }
    return dp[n];
    
}
bool is_palin(string s){
    ll n=s.length();
    for(int i=0;i<n/2+1;i++){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;   
}
void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
   ll n;
   cin>>n;
   vector<ll> A(n);
   for(auto& x:A)
        cin>>x;
   sort(A.begin(),A.end());
   vector<ll> temp;
   temp.push_back(A[0]);
   ll fact=0;
   int i=1;
   while(i<n){
        ll t=A[i];
        if(find(temp.begin(),temp.end(),t)!=temp.end()){
            while(binary_search(temp.begin(),temp.end(),t)){
                
                ++t;
                ++fact;
            }
        }
        temp.push_back(t);
        i++;
   }
    
    cout<<fact<<"\n";
    
    
}

    
