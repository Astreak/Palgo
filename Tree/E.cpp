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
        if(A[i-1]<A[i])
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<char>> dp;
        for(int i=0;i<n;i++){
            vector<char> row;
            for(int j=0;j<n;j++){
                char temp;
                cin>>temp;
                row.push_back(temp);
            }
            dp.push_back(row);    
        }
        bool flag=true;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(dp[i][j]=='1'){
                    if(dp[i][j+1]!='1' &&  dp[i+1][j]!='1'){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag)
                break;
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
               
}



