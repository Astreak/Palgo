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
        for(auto x:F)
            A.push_back(x);
        for(int i=0;i<A.size();i++){
            update(n,i,A[i]);
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


int main(){
    vector<int> A={12, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n=A.size();
    Fenwick<int> BIT(n);
    BIT.copy_array(A);
    for(int i=0;i<BIT.A.size();i++){
        cout<<BIT.A[i]<<"\n";
    }
    cout<<"sum is comming "<<"\n";
    cout<<BIT.sum(2)<<"\n";
    
}



