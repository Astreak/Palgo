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
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        ll k=(y-x);
        if(n==2){
            cout<<x<<" "<<y<<"\n";
            continue;
            
        }
        if(k+1==n){
            for(int i=x;i<=y;i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else{
            if(k+1<n){
                ll diff=n-k-1;
                ll cnt=0;
                ll start=x;
                ll end=y;
                for(int i=x-1;i>=1 && cnt<diff;i--){
                    start=i;
                    cnt++;
                }
                if(cnt!=diff){
                    ll f=(diff-cnt);
                    end+=(diff-cnt);
                }
                for(int i=start;i<=end;i++)
                    cout<<i<<" ";
                cout<<"\n";
                
            }
            else{
                ll jump=1;
                for(int i=1;i<=k;i++){
                    if(k%i==0){
                        if((k/i)+1<=n){
                            jump=i;
                            break;
                        }
                    }
                }
                ll adv=(k/jump)+1;
                if(adv==n){
                    
                    for(int i=x;i<=y;i+=jump)
                        cout<<i<<" ";
                }
                else{
                    ll diff=n-adv;
                    
                    ll start=x;
                    ll end=y;
                    ll cnt=0;
                    for(int i=x;i>=1 && cnt<diff;i-=jump){
                        start=i;
                        if(i!=x)
                            ++cnt;
                    }
                    if(diff!=cnt){
                        end+=(diff-cnt)*jump;
                    }
                    for(int i=start;i<=end;i+=jump){
                        cout<<i<<" ";
                    }
                }
                cout<<"\n";
            }
        }
    }
}


































    
