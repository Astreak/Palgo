#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c,d;
    cin>>a>>b>>c>>d;
    pair<int,string> p1,p2,p3,p4,p5;
    p1.second="X A B C D Y";
    p2.second="X J K M N O Y";
    p3.second="X J P Q O Y";
    p4.second="X G H I Y";
    p5.second="X E F G H I Y";
    //cout<<"yo";
    //cout<<p5.second;
    p1.first=3+2+b+3+4;
    p2.first=d+4+4+4+3+3;
    p3.first=d+3+4+a+3;
    p4.first=c+4+4+3;
    p5.first=4+3+4+4+4+3;
    int min=p1.first;
    if(min>p2.first)
        min=p2.first;
    if(min>p3.first)
        min=p3.first;
    if(min>p4.first)
        min=p4.first;
    if(min>p5.first)
        min=p5.first;
    if(min==p1.first)
        cout<<p1.second;
    if(min==p2.first)
        cout<<p2.second;
    if(min==p3.first)
        cout<<p3.second;
    if(min==p4.first)
        cout<<p4.second;
    if(min==p5.first)
        cout<<p5.second;
    return 0;
}
