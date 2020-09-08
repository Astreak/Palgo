#include<bits/stdc++.h>
#define ll long long 
#define tt template<typename T>
#define deb(x) cout<<x<<"\n"
#define inp(x) cin>>x
using namespace std;
tt
class Tree{
    public:
    int data;
    unordered_map<T,vector<T>> adj;
    void add_edge(T a,T b);
    void dfs(T a,T r);
    void bfs(T a);
    int Lpath(T s,T e);
};

tt
void Tree<T>::add_edge(T a,T b){
    adj[a].push_back(b);
    
    
}
tt
void Tree<T>::bfs(T a){
    unordered_map<T,bool> vis;  
    queue<T> Q;
    Q.push(a);
    vis[a]=true;
    while(!Q.empty()){
        auto x=Q.front();
        cout<<x<<" ";
        for(auto i=adj[x].begin();i!=adj[x].end();i++){
            if(!vis[*i]){
                vis[*i]=true;
                Q.push(*i);
            }
        }
        Q.pop();
    }
}

tt
void Tree<T>::dfs(T a,T root){
   //cout<<a<<" ";
   for(auto x:adj[a]){
        if(x!=a)
            dfs(x,a);
   }   
}
tt
int Tree<T>::Lpath(T a,T g){
    unordered_map<T,int>dp;
    dp[a]=1;
    int c=0;
    for(auto x:adj[a]){
        if(x==a)
            continue;
        dfs(x,a);
        dp[a]+=dp[x];
        c=max(x,dp[a]);
    }
    return c;
}
tt 
void  min_path(Tree<T> A,T root,unordered_map<T,int>&M){
    
    unordered_map<T,bool> vis;
    queue<T> Q;
    Q.push(root);
    
    M[root]=1;
    vis[root]=true;
    while(!Q.empty()){
        auto k=Q.front();
        
        for(auto i=A.adj[k].begin();i!=A.adj[k].end();i++){
            if(!vis[*i]){
                vis[*i]=true;
                Q.push(*i);
                M[*i]=M[root]+1;
            }
        }
        Q.pop();
    }
    
}
void swapping(ll& x,ll& y){
    ll temp=x;
    x=y;
    y=temp;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(auto& x:A)
            cin>>x;
        sort(A.rbegin(),A.rend());
        vector<int> B;
        unordered_map<int,bool> M(false);
        B.push_back(A[0]);
        M[0]=true;
        while(B.size()<n){
            int c=0;
            int val=0;
            int indx=0;
            for(int j=0;j<n;j++){
                if(M[j]==false){
                    int diff=__gcd(B[B.size()-1],A[j]);
                    if(c<diff){
                        c=diff;
                        val=A[j];
                        indx=j;
                        
                    }    
                    else if(c==diff && val<A[j]){
                        val=A[j];
                        indx=j;
                    }
                }
                
            }
            if(val!=0){
                M[indx]=true;
                    
                B.push_back(val);
            }

        }
        
        for(auto x:B)
            cout<<x<<" ";
        cout<<"\n";
    }
    
    
    
    
}
