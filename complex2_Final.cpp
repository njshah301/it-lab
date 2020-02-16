#include<iostream>
using namespace std;
class complex{
private:
    int Real,Img;
    static int NO_Of_Object;
public:
    void setReal(int Re){
    Real=Re;
    }
int getReal(){
return Real;
}

    void setImg(int Im){
    Img=Im;

    }
int getImg(){
return Img;
}
static int getNoOfobject(){
return NO_Of_Object;
}
void addition(const complex &a5,const complex &a6){
Real=a5.Real+a6.Real;
Img=a5.Img+a6.Img;
}


complex &magnitude(complex &a,complex &b){
int mag1,mag2;
mag1=a.Real*a.Real+a.Img*a.Img;
mag2=b.Img*b.Img+b.Real*b.Real;

if(mag1>mag2)
{
    return a;
}
else
    return b;
}
complex(){                //Default Constructor
    Real=0;
    Img=0;
    NO_Of_Object++;
        }
  complex(complex &c){    //copy constructor
  Real=c.Real;
  Img=c.Img;
  NO_Of_Object++;
  }
  complex(int i,int j){   //parameterized constructor
  Real=i;  Img=i;
  NO_Of_Object++;
}



}a1,a2,a3;

int complex::NO_Of_Object=0;
int main(){

int Re,Img;

cin>>Re>>Img;

a1.setReal(Re);
a1.setImg(Img);

cin>>Re>>Img;

a2.setReal(Re);
a2.setImg(Img);
a3.addition(a1,a2);
cout<<a3.getReal()<<"+i"<<a3.getImg()<<"\n";
complex &a4=a2.magnitude(a1,a2);
cout<<a4.getReal()<<"+i"<<a4.getImg()<<"\n";
complex *p;
p=&a3;
p->addition(a1,a2);
cout<<p->getReal()<<"+i"<<p->getImg()<"\n";
cout<<"Enter the size of array\n";
int size1;
cin>>size1;
int i,j,k,l,m,n;
p=new complex[size1];
int a,b;
for(i=0;i<size1;i++){
    cin>>a>>b;
    p[i].setReal(a);
    p[i].setImg(b);
}
complex a3;      //default constructor
cout<<a3.getReal()<<"+i"<<a3.getImg()<<"\n";
//copy constructor
a3=a1;
cout<<a3.getReal()<<"+i"<<a3.getImg()<<"\n";
complex a5(10,20);                                //parameterized constructor
cout<<a5.getReal()<<"+i"<<a5.getImg()<<"\n";
cout<<complex::getNoOfobject()<<"\n";
return 0;
}
