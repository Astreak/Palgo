#include<bits/stdc++.h>
#include<cmath>
#define ll long long 
#define tt template<typename T>
using namespace std;
tt
class Fenwick{
  public:
    T n;
    Fenwick(T n){
	this->n=n;
    }
    vector<T> A;
    vector<T> M;
      void copy_array(vector<T> F){
         for(int i=0;i<1000000;i++)
	    A.push_back(0);
        for(int i=0;i<F.size();i++)
            update(n,i,F[i]);
        
    }
    void update(T n,T i,T val);
    T sum(T i);
    void MIN_BIT();
    T mini(T i);
      
};
tt
void Fenwick<T>::update(T n,T i,T val){
    int index=i+1;
    while(index<=n){
        A[index]+=val;
        index+=(index&(-index));
    }
}
tt
T Fenwick<T>::sum(T i){
    T sum=0;
    T index=i+1;
    while(index>0){
        sum+=A[index];
        index-=(index&(-index));
    }
    return sum;
}
tt
void Fenwick<T>::MIN_BIT(){
      vector<T> M=A;
      for(int i=0;i<A.size();i++){
	  ll temp=i;
	  ll c=INT_MAX;
	  while(temp<n){
	    c=min(c,A[temp]);
	    temp+=(temp&(-temp));
	  }
	  M[i]=c;
      }


}
tt
T Fenwick<T>::mini(T i){
    T temp=INT_MAX;
    T I=i+1;
    while(I>0){
	temp=min(temp,A[I]);
	I-=(I&(I-1));
    }
    return temp;
  
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
    vector<ll> A={1,2,3,4,5,6,7,8};
    Fenwick<ll> fen(A.size());
    
       
    
}




