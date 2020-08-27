#include<bits/stdc++.h>
#define ll long long
using namespace std;

typedef class Point{
    public:
        int x,y;
        Point(int a,int b){
            this->x=a;
            this->y=b;
            
        }
        Point(){
            this->x=0;
            this->y=0;
        }
        void __set(int a,int b){
            x=a;
            y=b;
        }
        Point operator+(Point a);        
        void show(){
            cout<<this->x<<" "<<this->y<<"\n";    
        }
        Point operator*(Point a);
        Point operator-(Point a);
        

}pt;


Point Point::operator+(Point a){
    Point temp;
    temp.x=x+a.x;
    temp.y=x+a.y;
    return temp;
}
Point Point::operator*(Point a){
    Point temp;
    temp.x=a.x*x;
    temp.y=y*a.y;
    return temp;
}
Point Point::operator-(Point a){
    Point temp;
    temp.x=a.x-x;
    temp.y=a.y-y;
    return temp;
}

int dot(Point a,Point b){
    int X=a.x*b.x;
    int Y=a.y*b.y;
    return X+Y;
}

int cross(Point a,Point b){
    int X=a.x*b.y;
    int Y=a.y*b.x;
    return X-Y;
}

int orient(pt a,pt b,pt c){
    int k=cross(b-a,c-a);
    return k/abs(k);
}
float cos(pt a,pt b){
    double a1=(pow(a.x,2)+pow(a.y,2));
    double b1=(pow(b.x,2)+pow(b.y,2));
    a1=sqrt(a1);
    b1=sqrt(b1);
    double u=dot(a,b);
    if(u==0)
        return u=90;
    else{
        assert(a1*b1!=0);
        return u/(a1*b1);
    }
    
}
float sin(pt a,pt b){
    double a1=(pow(a.x,2)+pow(a.y,2));
    double b1=(pow(b.x,2)+pow(b.y,2));
    a1=sqrt(a1);
    b1=sqrt(b1);
    double u=cross(a,b);
    if(u==0)
        return u=90;
    else{
        assert(a1*b1!=0);
        return u/(a1*b1);
    }
    
}


int main(){
    Point A(1,0);
    Point B(0,1);
    Point G(2,3);
    cout<<cross(A,B)<<"\n"; 
    
}
