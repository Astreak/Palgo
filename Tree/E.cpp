#include<bits/stdc++.h>
#include<cmath>
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
    return a*(a-1);
}

ll prim_fac(ll n){
	set<ll> S;
	for(int i=2;i*i<=n;i++){
	    if(n%i==0){
		
		while(n%i==0){
		    S.insert(i);
		    n/=i;
		}
	    }
	}
	if(n>1)
	    S.insert(n);
	return S.size();
	
}

ll C(ll a,ll b){
    return (a+b-1)/b;
}
bool is_rev(vector<ll> A){
    for(int i=1;i<A.size();i++){
	if(A[i-1]<=A[i])
	    return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
	ll p,f,cnt1,cnt2,s,w;
	cin>>p>>f;
	cin>>cnt1>>cnt2;
	cin>>s>>w;
	ll Sum=p+f;
	ll M=INT_MIN;
	for(int i=0;i<=cnt1;i++){
		ll temp=i*s;
		if(temp<=Sum){
		    ll diff=Sum-temp;
		    ll g=diff/w;
		    if(g>cnt2)
			g=cnt2;
		    M=max(M,g+i);
		}
	}
	cout<<M<<"\n";
    }
}




