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


int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>P;
    priority_queue<ll> Q;
    ll sum=0;
    ll m=INT_MIN;
    while(n--){
        ll a,b;
        cin>>a>>b;
        P.push_back(make_pair(a,b));
        sum+=a;
        
        Q.push(b);
    }
    

    vector<ll> ans;
    for(int j=0;j<P.size();j++){
        ll o=sum-P[j].first;
        if(Q.top()==P[j].second){
            ll temp=Q.top();
            Q.pop();
            ans.push_back(Q.top()*o);
            Q.push(temp);
        }
        else
            ans.push_back(Q.top()*o);
        
    }
    for(auto x:ans)
        cout<<x<<" ";
    cout<<"\n";
}


































    
