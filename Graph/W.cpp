#include<bits/stdc++.h>
#define ll long long 
#define T template<class C> 
using namespace std;
T
class Tree{
    public:
    T data;
    unordered_map<T,vector<T>> adj;
    
};
T
void add_edge(Tree<T>&G,T a,T b){
    G.adj[a].push_back(b);
    G.adj[b].push_back(a);
};

int main(){
    Tree<int> root;
    a
}

