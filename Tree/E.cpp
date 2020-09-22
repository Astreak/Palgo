#include<bits/stdc++.h>
#define ll long long 
#define tt template<typename T>
using namespace std;
tt
class Fenwick{
  public:
    T n;
    
    vector<T> A;

    void copy_array(vector<T> F){
        for(int i=0;i<=n;i++){
           A.push_back(0);
        }   
        for(int i=0;i<F.size();i++){
            update(n,i,F[i]);
        }
    }
    void update(int n,int i,T val);
    int sum(int i);
      
};
tt
void Fenwick<T>::update(int n,int i,T val){
    int index=i+1;
    while(index<=n){
        A[index]+=val;
        index+=(index&(-index));
    }
}
tt
int Fenwick<T>::sum(int i){
    int sum=0;
    int index=i+1;
    while(index>0){
        sum+=A[index];
        index-=(index&(-index));
    }
}

bool reverse_sort(vector<ll> A,int start,int end){
    for(int i=start+1;i<=end;i++){
        if(A[i-1]>A[i])
            return false;
    }
    return true;
}

ll bin_exp(ll a,ll b){
    ll res=1;
    while(b>=1){
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
ll prog(ll a){
    return a*(a+1);
}

int main(){
   int t;
   cin>>t;
   while(t--){
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<pair<char,ll>> P;
        for(int i=0;i<n;i++){
            if(P.empty() || P.back().first!=s[i]){
                P.push_back(make_pair(s[i],1));
            }
            else
                P.back().second++;
        }
        ll cut=0;
        ll leading=0;
        bool flag=false;
        vector<ll> O;
        for(int i=0;i<P.size();i++){
            if(P[i].first=='1'){
                flag=true;
                ++cut;
            }
            else if(P[i].first=='0')
                O.push_back(P[i].second);
            if(!flag)
                ++leading;
        }
        reverse(P.begin(),P.end());
        flag=false;
        ll trail=0;
        for(int i=0;i<P.size();i++){
            if(P[i].first=='1'){
                flag=true;
                break;
            }
            if(!flag)
                ++trail;
                
            
        }
        sort(O.begin(),O.end());
        ll ans;
        if(cut<=m){
            if(cut<m){
                ll diff=leading+trail+cut;
                if(m-cut>=2)
                    ans=0;
                else
                    ans=min(leading,trail);
            }
            else
                ans=leading+trail;
        
        }
        else{
            ll g=0;
            ll s=0;
            ll diff=cut-m;
            for(int i=0;i<O.size();i++){
                if(g==diff)
                    break;
                s+=O[i];
                ++g;
            }
            ans=s;
        }
        cout<<ans<<"\n";
   
   }
           
           
}



