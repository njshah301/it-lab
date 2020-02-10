#include<iostream>
using namespace std;
class complex{
public:
int x,y;
complex(int x1,int y1){
x=x1;
y=y1;
}
int getX(){
return x;}

int gety(){
return y;}


};
int main(){

complex p(10,20);
cout<<p.x<<p.y;


return 0;
}
