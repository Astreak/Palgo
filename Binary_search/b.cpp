#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll upper(vector<ll> A,int n){
    int low=0;
    int high=A.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if((mid==0 || A[mid-1]<n) && A[mid]>= n)
            return mid;
        else if(A[mid]==n)
            return mid;
        else if(A[mid]>n)
            high=mid-1;
        else
         low=mid+1;
         
            
    }
    return -1;
    
}

ll cal(ll m,ll n){
    if(m%n==0)
        return n;
    else
        return (m/n)+1;
}

bool ok(ll m,ll n){
    ll low=0;
    ll high=m;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(cal(m,mid+1)+mid==n)
            return true;
        else if(cal(m,mid+1)+mid>n)
            high=mid-1;
        else
            low=mid+1;
    }
    low=0;
    high=m;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(cal(m,mid+1)+mid==n)
            return true;
        else if(cal(m,mid+1)+mid>n)
            low=mid+1;
        else
            high=mid-1;
    }
    return false;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> A(n);
    for(auto& x:A)
        cin>>x;
    sort(A.begin(),A.end());
    vector<ll>B;
    ll mid=1+(n-1)/2;
    for(int i=n-1;i>=mid;i--)
        B.push_back(A[i]);
    for(int j=0;j<mid;j++)
        B.push_back(A[j]);
    for(ll x:B)
        cout<<x<<" ";
}
