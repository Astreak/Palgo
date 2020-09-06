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



int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        if(n==2)
            cout<<x<<" "<<y<<"\n";
        else{
            ll k=y-x;
            if(k+1==n){
                for(int i=x;i<=y;i++){
                    
                    cout<<i<<" ";
                }
                }
            else{
                ll jump=0;
                
                if(k+1<n){
                    ll temp=n-k-1;
                    ll start;
                    ll end=y;
                    ll cnt=0;
                    for(int i=x-1;i>=1 && cnt<temp;i--){
                        cnt++;
                        start=i;
                    }
                    if(cnt!=temp){
                        end=end+(temp-cnt);
                    }
                    for(int i=start;i<=end;i++)
                        cout<<i<<" ";
                }
                else{
                    for(int i=1;i<=k;i++){
                        if(k%i==0){
                            if((k/i)+1<=n){
                                jump=i;
                                break;
                            }
                        }
                    }
                    if((k/jump)==n){
                        for(int i=x;i<=y;i+=jump)
                            cout<<i<<" ";
                        
                    }
                    else{
                        ll diff=n-(k/jump)-1;
                        ll start=x;
                        ll end=y;
                        ll cnt=0;
                        for(int i=x-jump;i>=1 && cnt<diff;i-=jump){
                            start=i;
                            cnt++;
                        }
                            
                        if(cnt!=diff)
                            end=end+((diff)-cnt)*jump;
                        for(int i=start;i<=end;i+=jump)
                            cout<<i<<" ";
                        
                    }
                    
                }                
            
            }
            cout<<"\n";
        }         
          
            
        
        
        
        
    }    
    
}




    
