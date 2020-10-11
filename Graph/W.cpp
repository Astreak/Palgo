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
    void add_w(C a,C b,int w){
        wgh[a].push_back(make_pair(b,w));
        wgh[b].push_back(make_pair(a,w));
    }
    void add_edge(C a, C b,int w);
    void bfs(C s);
    void dfs1(C v,unordered_map<C,bool>&visited);
    void dfs(C s);
    bool detect_cycle_utils(C v,unordered_map<C,bool>&visited,C parent);
    bool iscycle(C a);
    bool mother(C a);
   
};
TT
// change directive propertyu
void G<C>::add_edge(C a,C b,int w){
    wgh[a].push_back({b,w});
    wgh[b].push_back({a,w});
    
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


bool is_sorted(vector<ll> A){
    for(int i=1;i<A.size();i++){
        if(A[i-1]>A[i])
            return false;
    }
    return true;
}

int minstep(vector<int> A){
    int n=A.size();
    unordered_map<int,bool> vis;
    unordered_map<int,vector<int>> adj;
    vector<int> L(n);
    
    
    for(int i=0;i<n;i++)
        adj[A[i]].push_back(i);
    L[0]=0;
    vis[0]=true;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        auto x=Q.front();
        Q.pop();
        if(x==n-1)
            break;
        int d=A[x];
        for(int i=0;i<adj[d].size();i++){
            int idx=adj[d][i];
            if(!vis[idx]){
                Q.push(idx);
                vis[idx]=true;
                L[idx]=L[x]+1;
            }
        }
        if(x-1>=0 && !vis[x-1]){
            vis[x-1]=true;
            Q.push(x-1);
            L[x-1]=L[x]+1;            
        }
        if(x+1<n && !vis[x+1]){
            vis[x+1]=true;
            Q.push(x+1);
            L[x+1]=L[x]+1;
        }
        
     }
     return L[n-1];
    
    
}
bool check_valid(vector<vector<int>> A,int r,int c){
    int n=A.size();
    int m=A[0].size();
    if((r>=0 && r<n) &&(c>=0 && c<m) && A[r][c]==1)
        return true;
    else
        return false;    
}
 
void  Bat_dfs(vector<vector<int>> A,unordered_map<int,bool>&M1,unordered_map<int,bool>&M2,int i,int j,int&c){
        static int x_axis[8]={-1,-1,-1,0,0,1,1,1};
        static int y_axis[8]={-1,0,1,-1,1,-1,0,1};
        if(!M1[i] || !M2[j]){
            M1[i]=true;
            M2[j]=true;
            for(int k=0;k<8;k++){
                if(check_valid(A,i+x_axis[k],j+y_axis[k])){
                    Bat_dfs(A,M1,M2,i+x_axis[k],j+y_axis[k],c);
                    ++c;
                }
            }
        }
}

int main_batman(vector<vector<int>> A){
        int M=INT_MIN;
        int n=A.size();
        int m=A.at(0).size();
        for(int i=0;i<n;i++){
        
            for(int j=0;j<m;j++){
                int c=0;    
                unordered_map<int,bool> M1(false);
                unordered_map<int,bool> M2(false);
                Bat_dfs(A,M1,M2,i,j,c);
                
                M=max(M,c);
            }
            
        }
        return M;
}
struct Hoo{
    int alpha;
    int beta;
    int gamma;
};

bool pattern(string s,string g){
    int n=s.length();
    int m=g.length();
    for(int i=0;i<n;i++){
            int j;
            bool flag=true;
            for(j=0;j<m;j++){
                if(i+j>=n || g[j]!=s[i+j]){
                    flag=false;
                    break;
                }
            
            }
            if(flag)
                return true;
    
        }
    
    return false;
}


int main(){
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   G<char> graph;
   graph.add_edge('X','A',1);
   graph.add_edge('A','F',1);
   graph.add_edge('F','L',a);
   graph.add_edge('L','M',2);
   graph.add_edge('M','G',1);
   graph.add_edge('G','E',2);
   graph.add_edge('E','X',b);
   graph.add_edge('M','O',3);
   graph.add_edge('M','Y',2);
   graph.add_edge('O','Y',1);
   graph.add_edge('Y','K',3);
   graph.add_edge('Y','I',3);
   graph.add_edge('I','H',c);
   graph.add_edge('K','J',d);
   graph.add_edge('J','H',1);
   graph.add_edge('H','C',2);
   graph.add_edge('H','D',2);
   graph.add_edge('C','X',4);
   graph.add_edge('D','B',1);
   graph.add_edge('B','X',1);
   
   
       
}
    

        

