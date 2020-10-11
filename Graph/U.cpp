#include<bits/stdc++.h>
#define ll long long
using namespace std;
static vector<int> XOX={0,0,1,-1};
static vector<int> YOY={1,-1,0,0};

bool poss(ll n,ll m,ll x,ll y){
      return ((x<n&&x>=0)&& (y<m&&y>=0));
} 

void add_edge(ll a,ll b,unordered_map<ll,vector<ll>>& M){
    M[a].emplace_back(b);
    
  
}

void bfs(unordered_map<ll,vector<ll>> M,ll s,unordered_map<ll,bool>& vis){
      
      queue<ll> Q;
      Q.push(s);
      vis[s]=true;
      while(!Q.empty()){
	 ll x=Q.front();
	 Q.pop();
	 
	 for(auto r:M[x]){
	    if(!vis[r]){
	      vis[r]=true;
	      Q.push(r);
	    }
	}
    }
  
}
void dfs(unordered_map<ll,vector<ll>> M,ll s,unordered_map<ll,bool>& vis){
      stack<ll> Q;
      Q.push(s);
      vis[s]=true;
      while(!Q.empty()){
	 ll x=Q.top();
	 Q.pop();
	 
	 for(auto r:M[x]){
	    if(!vis[r]){
	      vis[r]=true;
	      Q.push(r);
	    }
	}
    }
  
}
unordered_map<ll,ll> cycle(unordered_map<ll,vector<ll>> M,ll s,unordered_map<ll,bool>& vis){
      queue<ll> Q;
      Q.push(s);
      vis[s]=true;
      unordered_map<ll,ll> L;
      L[s]=0;
      while(!Q.empty()){
	 ll x=Q.front();
	 Q.pop();
	 for(auto r:M[x]){
	    
	    if(!vis[r]){
	      vis[r]=true;
	      Q.push(r);
	      L[r]=L[x]+1;
	    }
	    else if(r==x)
	      cout<<"smallest cycle "<<L[r]<<"\n";
	    
	}
    }
    return L;
}
 
void problem(ll s,ll h,vector<vector<ll>> A,map<pair<ll,ll>,bool>& M1,ll n,ll m){
      
      queue<pair<ll,ll>> Q;
      Q.push({s,h});
      M1[{s,h}]=true;
      
      while(!Q.empty()){
	  auto x=Q.front();
	  Q.pop();
	  ll a=x.first;
	  ll b=x.second;
	  for(int i=0;i<4;i++){
	      if(poss(n,m,a+XOX[i],b+YOY[i]) && (!M1[{a+XOX[i],b+YOY[i]}]) && (A[a+XOX[i]][b+YOY[i]]==0)){
		  M1[{a+XOX[i],b+YOY[i]}]=true;
		  Q.push({a+XOX[i],b+YOY[i]});
		  
	      }
	  }
    }
    
    return ;
  
}

int main(){
    map<pair<ll,ll>,bool> vis1;
  
    vector<vector<ll>> A;
    ll n,m;
    cin>>n>>m;
    
    
    for(int i=0;i<n;i++){
	vector<ll>temp;
	for(int j=0;j<m;j++){
	    char k;
	    cin>>k;
	    if(k=='.'){
	      
	      temp.emplace_back(0);
	    }
	    else
	      temp.emplace_back(1);
	    
	}
	A.push_back(temp);
    }
    ll cnt=0;
    vector<pair<ll,ll>> P;
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(A[i][j]==0)
		P.push_back({i,j});
	}
    }
    for(auto x:P){
	if(!vis1[x]){
	    problem(x.first,x.second,A,vis1,n,m);
	    ++cnt;
	}
    }
    cout<<cnt<<"\n";
    
    
  
  
    
    
    
	
}

