#include<bits/stdc++.h>
#define ll long long 
#define tt template<typename T>
using namespace std;
tt
class Fenwick{
  public:
    T n;
    Fenwick(T a){
        this->n=a;
    }
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
        if(A[i-1]<A[i])
            return false;
    }
    return true;
}

int main(){
   int t;
   cin>>t;
   while(t--){
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
       
        
   }
}



