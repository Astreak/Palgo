#include<bits/stdc++.h>
#define ll long long 
using namespace std;

bool bs(vector<ll> A,ll n){
    int low=0;
    int high=A.size();
    while(low<high){
        ll mid=low+(high-low)/2;
        if(A[mid]==n)
            return true;
        else if(A[mid]>n)
            high=mid-1;
        else
            low=mid+1;
            
    }
    return false;
}

ll first_occ(vector<ll> A,ll v){
    int low=0;
    int high=A.size();
    while(low<high){
        int mid=low+(high-low)/2;
        if(A[mid]==v)
            high=mid;
        else if(A[mid]>v)
            high=mid-1;
        else
            low=mid+1;
            
    }
    return high;
}

ll last_occ(vector<ll> A,ll n){
    int low=0;
    int high=A.size()-1;
    while(low<high-1){
        int mid=low+(high-low)/2;
        if(A[mid]==n)
            low=mid;
        else if(A[mid]>n)
            high=mid-1;
        else
            low=mid+1;
            
    }
    return low;
}

ll lower(vector<ll> A,ll h){
    int low=0;
    int high=A.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(A[mid]<=h)
            high=mid;
        else if(A[mid]>h)
            high=mid-1;
        else
            low=mid+1; 
    }
    return high;
}

ll binary(vector<ll> A,ll n){
    int low=0;
    int high=A.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==n)
            return mid;
        else if(A[mid]>n)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll n;
     cin>>n;
     vector<ll> A(n);
     for(auto& x: A)
        cin>>x;
     ll m;
     cin>>m;
     vector<ll> K(m);
     for(auto& c:K)
        cin>>c;
    vector<ll> L1;
   
    L1.push_back(A[0]);
    
    for(int i=1;i<n;i++){
        L1.push_back(L1[i-1]+A[i]);
        
    }
   for(int i=0;i<m;i++){
        if(binary_search(A.begin(),A.end(),K[i]))
            cout<<upper_bound(L1.begin(),L1.end(),K[i])-L1.begin()<<"\n";
        
        else{
            ll u=lower_bound(L1.begin(),L1.end(),K[i])-L1.begin();
            cout<<u+1<<"\n";
        }
   }
    



}

