#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long 
#define bits __builtin_clz
#define tp __builtin_popcount
#define INF 10e6;


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

void ab(ll& x){
    x=floor(x/2)+10;
}
void an(ll& x){
    x-=10;
}
int code(vector<ll> arr,int a,int b,ll sum) 
{ 
    ll n=arr.size();
    unordered_map<ll, ll> m; 
  
     
    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int twice_count = 0; 
  
     
    for (int i=0; i<n; i++) 
    { 
        
        twice_count += m[sum-arr[i]]; 
  
        
        if (sum-arr[i] == arr[i]) 
            twice_count--;
        
        else
            continue; 
    } 
  
    
    return twice_count/2; 
} 

ll code2(vector<ll>arr) 
{   
    ll n=arr.size();
    
    unordered_map<ll, ll> M; 
  
    
    for (int i = 0; i < n - 1; i++){ 
        vector<ll> s;
        for (int j = i + 1; j < n; j++){ 
            if(find(s.begin(),s.end(),arr[i]+arr[j])==s.end()){
            M[(arr[i] + arr[j])]++;
            s.push_back(arr[i]+arr[j]);
            }
        }
    } 
  
    ll max_count = 0; 
  
    
    for (auto ele : M) 
        if (max_count < ele.second) 
            max_count = ele.second; 
  
    return max_count; 
} 
 
ll  cde3(vector<ll> arr){
   ll n=arr.size();
   ll sum[20]={0};
   ll maxC = 0;
   
   for (int i = 0; i < n - 1; i++){
        vector<ll> s;
      for (int j = i + 1; j < n; j++){
         ll y=arr[i]+arr[j];
         if(find(arr.begin(),arr.end(),y)==arr.end()){
            sum[arr[i]+arr[j]]++;
            s.push_back(y);
        }
        
            
      }
    }
      for(int i=0;i<20;i++)
         if(sum[i]>maxC)
            maxC=sum[i];
   return maxC;
} 
ll bs(vector<ll> A,ll k){
    int low=0;
    int high=int(A.size())-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==k)
            return mid+1;
        else if(A[mid]>k)
            high=mid-1;
        else
            low=mid+1;
            
    }
    return -1;
}
bool is_palindrom(string s,int low,int high){
    if(low<high){
        if(s[low]==s[high])
            return is_palindrom(s,low+1,high-1);
        else
            return false;
    }
    return true;
    
}

void print_pal(vector<vector<string>>& A,vector<string>& C,int low,int high,string s){
    if(low==high){
        A.push_back(C);
        return ;
    }
    for(int i=low;i<high;++i){
        if(is_palindrom(s,low,i)){
            C.push_back(s.substr(low,i-low+1));
            print_pal(A,C,i+1,high,s);
            C.pop_back();
        }
    }

}

void count_consonents(string s,vector<char> A,int& c,int high){
    if(high){
        if(find(A.begin(),A.end(),s[high-1])==A.end())
            ++c;
        count_consonents(s,A,c,high-1);
    }
    
}
void insert_at_bottom(stack<int>& S,int x){
    if(S.size()==0){
        S.push(x);
        return ;
    }
    int a=S.top();
    S.pop();
    insert_at_bottom(S,x);
    S.push(a);
}

void reverse_stack(stack<int>& S){
    if(S.size()==0)
        return ;
    int a=S.top();
    S.pop();
    reverse_stack(S);
    insert_at_bottom(S,a);
    
}

int count_subs(string s,int low,int& c,int high){
    if(low<=high){
        if(s[low]==s[high])
            ++c;
        return count_subs(s,low+1,c,high-1)+count_subs(s,low+1,c,high)-count_subs(s,low,c,high-1);
    }
    
}
bool sum_of_digits(int s,int& c,int n){
    if(s>=2){
        if(s!=n  && n%s==0)
            ++c;
        return sum_of_digits(s-1,c,n);
        
    }
    if(c==2)
        return true;
    else
        return false;
        
    
}


ll bin_exp(ll a, ll b){
    if(b==0)
        return 1;
    ll res=bin_exp(a,b/2);
    if(b&1)
        return a*res*res;
    else
        return res*res;
}

int edit_distance(string s,string m){
    int y=s.length();
    int k=m.length();
    int dp[y][k];
    for(int i=0;i<=y;i++){
        for(int j=0;j<=k;j++){
            if(i==0 && j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s[i-1]==m[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    return dp[y][k];
}

bool is_prime(ll n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;    
}

bool is_palin(ll n){
    int r=0;
    ll res=0;
    ll temp=n;
    while(n){
        r=n%10;
        res=res*10+r;
        n/=10;
        
    }
    return temp==res;
}

int factorial(ll n){
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}

vector<ll> test_case(string s,ll x,ll y,ll a,ll b,unordered_map<char,ll> M){

    ll u=abs(a-x)+abs(b-y);
    vector<ll> J;
    
    
    bool x_flag=false;
    bool y_flag=false;
    if(a>=x){
        if(a-x<=M['R'])
            x_flag=true;
        else
            x_flag=false;
    }
    else{
        if(x-a<=M['L'])
            x_flag=true;
        else
            x_flag==false;
    }
    if(b>=y){
        if(b-y<=M['U'])
            y_flag=true;
        else
            y_flag=false;
    }
    else{
        if(y-b<=M['D'])
            y_flag=true;
        else
            y_flag==false;
    }
    if(x_flag==true && y_flag==true){
        J.push_back(1);
        J.push_back(u);
    }
    else
        J.push_back(0);
    
    

    
    
    
    return J;
}



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    
    cin>>t;
    while(t--){
        string s;
        unordered_map<char,ll> M;
        cin>>s;
        ll x,y;
        //scanf("%lld %lld\n",&x,&y);
        cin>>x>>y;
        int q;
        cin>>q;
        vector<pair<ll,ll>> P;
        for(int i=0;i<q;i++){
            ll a,b;
            //scanf("%lld %lld\n",&a,&b);
            cin>>a>>b;
            P.push_back(make_pair(a,b));
        }
        for(auto x:s)
            M[x]++;
        
        for(auto w:P){
            ll u=abs(w.first-x)+abs(y-w.second);
            bool x_f=false;
            bool y_f=false;
            if(w.first>=x){
                if(M['R']>=(w.first-x))
                    x_f=true;
                else
                    x_f=false;
            }
            else{
                if(M['L']>=(x-w.first))
                    x_f=true;
                else
                    x_f=false;
            }
            if(w.second>=y){
                if(M['U']>=(w.second-x))
                    y_f=true;
                else
                    y_f=false;
            }
            else{
                if(M['D']>=(y-w.second))
                    y_f=true;
                else
                    y_f=false;
            }
            if(x_f && y_f){
                cout<<"YES"<<" "<<u<<"\n";
            }
            else
                cout<<"NO"<<"\n";
            
        }
    
    }
        
    
    
}



      
