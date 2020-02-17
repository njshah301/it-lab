#include<iostream>
#include<iostream>
using namespace std;
class base{
protected:
int bs;
public:
base(int b){
bs=b;
}
void setBs(int b){
bs=b;
}
int getBs(){
return bs;
}
virtual void display(){
cout<<"value of bs\n"<<bs;
}
};
class derived:public base{
protected:
int ds;
public:
derived(int b,int d):base(b)
{
ds=d;
}
void setDs(int d){
ds=d;
}
int getDs(){
return ds;
}
void display(){
cout<<"bs= \n"<<bs;
cout<<"ds= \n"<<ds;
}
};

int main(){
base b(5);
base *bptr;
derived d(3,4);
bptr=&b;
bptr->display();
bptr=&d;
bptr->display();
derived *dptr;
dptr=&d;
dptr->display();

return 0;
}
