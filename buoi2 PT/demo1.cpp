#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
class PTBac2
{
	double a,b,c,x1,x2;
	int soNghiem;
	public:
		PTBac2(double m=0,double n=0,double p=0);
		void Nhap();
		void Xuat();
		void GiaiPT();
		void XuatNghiem();
	
};

PTBac2::PTBac2(double m, double n, double p)
{
	a=m;
	b=n;
	c=p;
}
void PTBac2::Nhap()
{
	cout<<"nhap a:";
	cin>>a;
	cout<<"nhap b:";
	cin>>b;
	cout<<"nhap c:";
	cin>>c;
}
void PTBac2::Xuat()
{
	cout<<"phuong trinh: "<<a<<"x^2";
	if (b>=0)
		cout<<"+";
	cout<<b<<"x";
	if (c>=0)
		cout<<"+";
	cout<<c<<"=0"<<endl;
	
}
void PTBac2::GiaiPT()
{
	double d=b*b-4*a*c;
	if (d<0)
		soNghiem=0;
	else if(d==0)
 	{
 		soNghiem=1;
		x1=-b/(2*a);
		x2=-b/(2*a);
	}
	else if (d>0)
	{
		soNghiem=2;	
		x1=(-b-sqrt(d))/(2*a);
		x2=(-b+sqrt(d))/(2*a);	
	}	
}
void PTBac2::XuatNghiem()
{
	if(soNghiem==0)
		cout<<"phuong trinh vo nghiem";
	if(soNghiem==1)
	{
		cout<<"phuong trinh co nghiem kep"<<endl;
		cout<<"x1:"<<x1;
	}	
	if(soNghiem==2)	
	{
		cout<<"phuong trinh co 2 nghiem"<<endl;
		cout<<"x1: "<<x1<<endl;
		cout<<"x2: "<<x2<<endl;
	}	
}

int main()
{
	PTBac2 pt;
	pt.Nhap();
	pt.Xuat();
	pt.GiaiPT();
	pt.XuatNghiem();
	return 0;
}
