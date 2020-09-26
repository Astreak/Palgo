#include<bits/stdc++.h>
#include<cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long 
#define bits __builtin_clz
#define tp __builtin_popcount
#define INF 10e6;

using namespace __gnu_pbds; 
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> G; 
             


bool is_prime(ll n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
    
unordered_map<ll,ll> prime_facts(ll n){
    unordered_map<ll,ll> M;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            M[i]++;
            n/=i;
        }
    }
    if(n>1)
        M[n]++;
    return M;
}
ll helper(ll n){
    ll S=0;
    while(n){
        S+=n%10;
        n/=10;
    }
    return S;  
}

int main(){
   int t;
   cin>>t;
   while(t--){
      for(int i=0;i<n;i++){
	
      }
    }
      
    
}
