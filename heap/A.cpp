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
struct Traingle{
    int a=1;
    int b=1;
    int c=1;
};

double Area(int a,int b,int c){
    double s=(a+b+c)/2;
    double u=s*(s-(double)a)*(s-(double)b)*(s-(double)c);
    return sqrt(u);
}
typedef Traingle TT;

class Heap{
    public:
    int cap;
    int* a;
    int curr;
    Heap(int cap){
        this->cap=cap;
        curr=0;
        a=new int[this->cap];
    }
    int parent(int i){
        return (i-1)/2;
    }
    int right(int i){
        return 2*i+2;
    }
    int left(int i){
        return 2*i+1;
    }
    int __get_min(){
        return a[0];
    }
    void Heapify(int s,int i);
    
    
    
    
};

void swap(int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
}

void heapify(vector<int>&A ,int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && A[left]>A[largest])
        largest=left;
    if(right<n && A[right]>A[largest])
        largest=right;
    if(i!=largest){
        swap(A[i],A[largest]);
        heapify(A,largest,n);
    }
}

void sort(vector<int>&A){
    int n=A.size();
    int mid=(n)/2;
    for(int i=mid;i>=0;i--){
        heapify(A,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(A[0],A[i]);
        heapify(A,0,i);
    }
    
}
int sorted_rotated(int* a,int n,int v){
    int low=0;
    int high=n;
    while(low<high){
        int mid=low+(high-low)/2;
        if(a[mid]==v)
            return mid;
        else if(a[mid]>v){
            if(a[low]<=v)
                high=mid;
            else
                low=mid+1;
        }
        else{
            low=mid+1;
        }
        
    }
    return -1;
}

void merge(int* A,int low,int high,int mid){
    int f=mid-low+1;
    int l=high-mid;
    int a[f],b[l];
    for(int i=0;i<=f;i++)
        a[i]=A[i+low];
    for(int j=0;j<=l;j++)
        a[j]=A[mid+1+j];
    int i=0;
    int j=0;
    int k=low;
    while(i<f && j<l){
        if(a[i]<=b[j]){
            A[k]=a[i];
            
            i++;
        }
        else{
            A[k]=b[j];
            j++;
            
        }
        ++k;
    }
    while(i<f){
        A[k]=a[i];
        i++;
        k++;
    }
    while(j<l){
        A[k]=b[j];
        j++;
        k++;
    }
    
}

void mergs(int* A,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergs(A,low,mid);
        mergs(A,mid+1,high);
        merge(A,low,high,mid);
    }
}

int rotated_sorted(int* a,int n){
    int low=0;
    int high=n;
    while(low<high){
        int mid=low+(high-low)/2;
        if(a[mid]>a[low])
            low=mid+1;
        else if(a[mid]<high)
            high=mid;
        else
            low++;
    }
    return high;
}



int main(){
    int a[]={2,12,34,45,-156,-111,-2};
    
    int I=7-rotated_sorted(a,7);
    vector<int> A;
    for(int i=6;i>=7-I;i--)
        A.push_back(a[i]);
    for(int i=0;i<7-I;i++)
        A.push_back(a[i]);
    for(int x:A)
        cout<<x<<" ";
   
    
    
    
    
    
    
    
    
     
    
}
             

