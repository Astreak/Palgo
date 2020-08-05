#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long 
#define bits __builtin_clz
#define tp __builtin_popcount

using namespace __gnu_pbds; 
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> G; 
             

struct Point{
    int x;
    int y;
    
};
int sum(vector<int> A,int n,int v){
    if(n==0)
        return -1;
    if (A[n-1]==v)
        return n-1;
    else
        return sum(A,n-1,v);
    return -1;
}

int find(vector<int> A,int low,int high,int v){
    if(low<=high){
        if(A[low]==v)
            return low;
        else if(A[high]==v)
            return high;
        else{
            int mid=low+(high-low+1)/2;
            int u=find(A,low,mid,v);
            if(u!=-1)
                return u;
            else{
                int k=find(A,mid+1,high,v);
                if(k!=-1)
                    return k;
            }
        }
           
    } 
    return -1;          
   


}
int find_max(vector<int>A,int s,int n){
    if(n-s>=1){
        if(n-s==1)
            return A[s]>A[n]?A[s]:A[n];
        else{
            int mid=s+(n-s)/2;
            int a=find_max(A,s,mid);
            int b=find_max(A,mid,n);
            return max(a,b);
        }
    }
}

int find_min(vector<int> A,int s,int n){
        if(n-s>=1){
            if(n-s==1)
                return A[n]>=A[s]?A[s]:A[n];
        else{
            int mid=s+(n-s)/2;
            int a=find_min(A,s,mid);
            int b=find_min(A,mid,n);
            return min(a,b);
        }
    }
}

int bis(vector<ll> A,ll val){
    int low=0;
    int high=A.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==val)
            return mid;
        else if(A[mid]>val)
            high=mid-1;
        else
            low=mid+1;
            
    }
    return -1;
}


void merge(vector<int>& A,int low,int mid,int high){
    int l1=mid-low+1;
    int l2=high-mid;
    int a[l1];
    int b[l2];
    for(int i=0;i<l1;i++)
        a[i]=A[i+low];
    for(int j=0;j<l2;++j){
        b[j]=A[j+mid+1];
    }
    int i=0;
    int j=0;
    int k=low;
    while(i<l1 && j<l2){
        if(a[i]<=b[j]){
            A[k]=a[i];
            ++i;
        }
        else{
            A[k]=b[j];
            ++j;
        }
        ++k;
    }
    while(i<l1){
        A[k]=a[i];
        k++;
        i++;
        
    }
    while(j<l2){
        A[k]=b[j];
        k++;
        j++;
    }
    
    
}

void sort(vector<int>& A,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        sort(A,low,mid);
        sort(A,mid+1,high);
        merge(A,low,mid,high);    
    }
        
}

int min_dist(vector<int> a,int low,int high,int c=INT_MAX){
    if(high-low>=1){
        if(high-low==1)
            return c=min(c,abs(a[high]-a[low]));
        else{
            int mid=low+(high-low)/2;
            return min(min_dist(a,low,mid,c),min_dist(a,mid+1,high,c));
        }
    }
    
}

ll rev(ll n){
    ll res=0;
    while(n){
        ll r=n%10;
        res=10*res+r;
        n/=10;
    }
    return res;
}

vector<ll> code(vector<ll>O){
    vector<ll> L;
    L.push_back(O[0]);
    for(int i=1;i<O.size();i++){
        L.push_back(L[i-1]+O[i]);
    }
    return L;
}

ll CC(int  o){
    ll u=(1<<(o-1))-1;
    return u;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<ll> O;
        vector<ll>L;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                O.push_back(i);
            else
                L.push_back(i);
        }
        int c=0;
        unordered_map<ll,bool> vis(false);
        for(int i=0;i<O.size();i++){
            if(O[i]==0){
                if(find(L.begin(),L.end(),O[i]+k+1)==L.end() && O[i]+k+1<s.length() && vis[O[i]+k+1]==false){
                    vis[O[i]+k+1]=true;
                    ++c;
                }
            }
            else if(O[i]==int(s.length())-1){
                if(find(L.begin(),L.end(),O[i]-k-1)==L.end() && (O[i]-k-1)>=0 && vis[O[i]-k-1]==false){
                    vis[O[i]-k-1]=true;
                    ++c;
                }
            }
            else{
                if(find(L.begin(),L.end(),O[i]+k+1)==L.end() && O[i]+k+1<s.length() && vis[O[i]+k+1]==false){
                    ++c;
                    vis[O[i]+k+1]=true;
                }
                if(find(L.begin(),L.end(),O[i]-k-1)==L.end() && (O[i]-k-1)>=0 && vis[O[i]-k-1]==false){
                    ++c;
                    vis[O[i]-k-1]=true;
                    
                }
            }
        }
        cout<<c<<"\n";
        
    }
        
}
    
       

    

