#include<iostream>
#include<math.h>
using namespace std;
class complex{

                double real;
                double imagin;
                public:
void setReal(double r)
{
real=r;
}
double getReal()
{
return real;
}
double setImg(double i)
{
imagin=i;
}
double getImg()
{
return imagin;
}
void add(const complex &a1,const complex &a2)
{	
real=a1.real+a2.real;
imagin=a1.imagin+a2.imagin;
}

void addition(complex a1,complex a2);
void max(complex &a,complex &b);
complex adding(complex a1,complex a2)
{
complex c;
c.real=a1.real+a2.real;
c.imagin=a1.imagin+a2.imagin;
return c;
}
double mag (complex a)
{
	double ma=sqrt((a.real*a.real)+(a.imagin*a.imagin));
	return ma;
}



        }a1,a2,a3,a4,a5,a6;
void complex:: addition (complex a1,complex a2)
{
real=a1.real+a2.real;
imagin=a1.imagin+a2.imagin;
}
void complex:: max(complex &a,complex &b)
{
        int mag1,mag2;
        mag1=sqrt((a.real*a.real)+(a.imagin*a.imagin));
        mag2=sqrt((b.real*b.real)+(b.imagin*b.imagin));
        if(mag1>mag2)
                cout<<a.real<<"+i"<<a.imagin<<endl;
        else
                cout<<b.real<<"+i"<<b.imagin<<endl;
}


int main()
{
double a,b,c,d;

cin>>a>>b>>c>>d;
a1.setReal(a);
a1.setImg(b);
a2.setReal(c);
a2.setImg(d);
a3.add(a1,a2);
a4.addition(a1,a2);
a5=a5.adding(a1,a2);
cout<<a5.getReal()<<endl;
cout<<a5.getImg()<<endl;
cout<<a4.getReal()<<endl;
cout<<a4.getImg()<<endl;
cout<<a3.getReal()<<endl;
cout<<a3.getImg()<<endl;
a5.max(a1,a2);
complex *p;
p=&a6;
p->add(a1,a2);
cout<<"sum="<<p->getReal()<<"+i"<<p->getImg()<<endl;
int size;
double x,y;
cout<<"Enter the size of the array";
cin>>size;
p=new complex [size];
a6.setImg(0);
a6.setReal(0);
for(int i=0;i<size;i++)
{
	cout<<"Enter the "<<i+1<<"complex number"<<endl;
	cin>>x>>y;
	p[i].setReal(x);
	p[i].setImg(y);
	cout<<p[i].getReal()<<"+i"<<p[i].getImg()<<endl;
}
}


