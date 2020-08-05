#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long 
#define bits __builtin_clz
#define tp __builtin_popcount
#define TT template<class C>
using namespace __gnu_pbds; 
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> O; 
TT
class G{
    public:
    unordered_map<C,vector<C>> adj;
    unordered_map<C,vector<pair<C,int>>> wgh;
    int V;// of no use for debugging lol
    void add_w(int a,int b,int w){
        wgh[a].push_back(make_pair(b,w));
        wgh[b].push_back(make_pair(a,w));
    }
    void add_edge(C a, C b);
    void bfs(C s);
    void dfs1(C v,unordered_map<C,bool>&visited);
    void dfs(C s);
    bool detect_cycle_utils(C v,unordered_map<C,bool>&visited,C parent);
    bool iscycle(C a);
    bool mother(C a);
   
};
TT
// change directive propertyu
void G<C>::add_edge(C a,C b){
    adj[a].push_back(b);
    
}
TT
void G<C>::bfs(C s){
    unordered_map<C,bool> visited(false);
    queue<C> Q;
    Q.push(s);
    visited[s]=true;
    while(!Q.empty()){
        C v=Q.front();
        cout<<v<<"\n";
        Q.pop();
        for(auto i=adj[v].begin();i!=adj[v].end();++i){
            if(!visited[*i]){
                Q.push(*i);
                visited[*i]=true;
            }
        }
    }
}
TT
void G<C>::dfs1(C v,unordered_map<C,bool>&vis){
    //cout<<v<<"\n";
    vis[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();++i){
        if(!vis[*i])
            dfs1(*i,vis);
    }
}
TT
void G<C>::dfs(C s){
    unordered_map<C,bool> vis;
    dfs1(s,vis);
}

TT
bool G<C>::detect_cycle_utils(C v,unordered_map<C,bool>& visited,C p){
    visited[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            if(detect_cycle_utils(*i,visited,v))
                return true;
        }
        else if(*i!=p)
            return true;
    }
    return false;
}

TT
bool G<C>::iscycle(C a){
    unordered_map<C,bool>vis(false);
    vector<C> A;
    for(auto x:adj){
        A.push_back(x.first);
    }
    for(C x:A){
        if(!vis[x]){
            if(detect_cycle_utils(x,vis,-1))
                return true;
        }
    }
    return false;
}


TT
int  nodes(G<C> g1,C s){
   unordered_map<C,bool> visited(false);
    queue<C> Q;
    Q.push(s);
    visited[s]=true;
    int c=0;
    while(!Q.empty()){
        C v=Q.front();
        if(v==(C)'n'){
            ++c;
            Q.pop();
            continue;
        }
        
        
        Q.pop();
        for(auto i=g1.adj[v].begin();i!=g1.adj[v].end();++i){
            if(!visited[*i]){
                Q.push(*i);
                visited[*i]=true;
            }
        }
        Q.push((C)'n');
    }
    return c;
}
TT 
bool G<C>::mother(C a){
    unordered_map<C,bool>vis(false);
    dfs1(a,vis);
    int c=1;
    vector<C> A;
    for(auto x:adj){
        A.push_back(x.first);
    }
    for(C x:A){
        if(!vis[x]){
           return false;
        }
    }
    return true;
    
}
// flood fill
template<class T>
void flood_fill(vector<vector<T>>& A,T n,T chg){
        int N=A.size();
        int M=A[0].size();
        unordered_map<int ,bool> vis1;
        unordered_map<int,bool> vis2;
        int pos1;
        int pos2;
        for(int i=0;i<N;i++){
            int flag=0;
            for(int j=0;j<M;j++){
                //debug :: cout<<A[i][j]<<"\n";
                if(A[i][j]==n){
                    pos1=i;
                    pos2=j;
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        queue<pair<int,int>> Q;
        pair<int,int> u;
        u.first=pos1;
        u.second=pos2;
        Q.push(u);
        vis1[pos1]=true;
        vis2[pos2]=true;
        while(!Q.empty()){
            auto y=Q.front();
            A[y.first][y.second]=chg;
            Q.pop();
            int a[8]={y.first-1,y.first-1,y.first-1,y.first,y.first,y.first+1,y.first+1,y.first+1};
            int b[8]={y.second-1,y.second,y.second+1,y.second-1,y.second+1,y.second-1,y.second,y.second+1};
            for(int i=0;i<8;i++){
                if((a[i]>=0 && a[i]<N) && (b[i]>=0 && b[i]<M)){
                    if(A[a[i]][b[i]]==n){
                        pair<int,int> u;
                        u.first=a[i];
                        u.second=b[i];
                        Q.push(u);
                        vis1[a[i]]=true;
                        vis2[b[i]]=true;
                    
                }
            }
        }
            
    } 


}
TT
int connected_components(G<C> g){
    vector<C> A;
    for(auto x:g.adj)
        A.emplace_back(x.first);
    int c=0;
    unordered_map<C,bool> M;
    for(C a:A){
        if(!M[a]){
            g.dfs1(a,M);
            ++c;
        }
    }
    return c;
}



TT
int path(G<C> g,C s,C d){
    unordered_map<C,bool> vis(false);
    int l=0;
    queue<C> Q;
    Q.push(s);
    vis[s]=true;
    map<int,vector<C>> K;
    K[0].push_back(s);
    Q.push(NULL);
    while(!Q.empty()){
        C v=Q.front();
        if(v==d)
            return l;
        if(v==NULL){
            ++l;
            Q.pop();
            continue;
        }
        Q.pop();
        for(auto i=g.adj[v].begin();i!=g.adj[v].end();++i){
            if(!vis[*i]){
                Q.push(*i);
                vis[*i]=true;
            }
        }
        Q.push(NULL);
        
        
        
    }
    return -1;
    
    
}

TT
int shortest_path(vector<vector<C>>A,C s,C d){
    int N=A.size();
    int M=A.at(0).size();
    unordered_map<C,bool> vis1(false);
    unordered_map<C,bool>vis2(false);
    vis1[s]=true;
    vis2[d]=true;
    int pos1;
    int pos2;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]!=s){
            pos1=i;
            pos2=j;
                
            }
        }
    }
    vis1[pos1]=true;
    vis2[pos2]=true;
    queue<pair<int,int>> Q;
    pair<int,int> u;
    u.first=pos1;
    u.second=pos2;
    Q.push(u);
    Q.push(NULL);
    int l=0;
    
    while(!Q.empty()){
        auto y=Q.front();
        if(y==NULL){
            ++l;
            Q.pop();
            continue;
        }
        if(A[y.first][y.second]==d){
            return l;
        }
        int a[8]={y.first-1,y.first-1,y.first-1,y.first,y.first,y.first+1,y.first+1,y.first+1};
        int b[8]={y.second-1,y.second,y.second+1,y.second-1,y.second+1,y.second-1,y.second,y.second+1};
        Q.pop();
        
        for(int i=0;i<8;++i){
            if((a[i]>=0 && a[i]<N)&&(b[i]>=0 && b[i]<M)){
                if(!vis[pos1] || !vis[pos2]){
                    pair<int,int> u;
                    u.first=a[i];
                    u.second=b[i];
                    Q.push_back(u);
                    vis1[a[i]]=true;
                    vis2[b[i]]=true;
                }
            }
        }
        Q.push(NULL);
        
    }
    
    
    return -1;
    
    
}


int main(){
   G<int> g1;
   g1.add_edge(2,3);
   g1.add_edge(4,1);
   g1.add_edge(4,7);
   g1.add_edge(3,6);
   g1.add_edge(7,2);
   vector<vector<int>> A={{1,2,3,4,5},{6,-1,7,8,9},{10,11,-12,90}};
   cout<<shortest_path(A,1,-1)<<"\n";
   
}
