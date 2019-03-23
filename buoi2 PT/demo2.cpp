#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
class PTBac1
{
	float a1,b1,a2,b2,c1,c2;
	public:
		PTBac1(double m=0,double n=0,double p=0,double q=0,double r=0,double s=0);
		void Nhap();
		void Xuat();
		void GiaiHePT();
	
	
};

PTBac1::PTBac1(double m, double n, double p,double q, double r, double s)
{
	a1=m;
	b1=n;
	a2=p;
	b2=q;
	c1=r;
	c2=s;
}
void PTBac1::Nhap()
{
	cout<<"nhap a1:";
	cin>>a1;
	cout<<"nhap b1:";
	cin>>b1;
	cout<<"nhap c1:";
	cin>>c1;
	cout<<"nhap a2:";
	cin>>a2;
	cout<<"nhap b2:";
	cin>>b2;
	cout<<"nhap c2:";
	cin>>c2;
}
void PTBac1::Xuat()
{
	cout<<a1<<"x";
	if (b1>=0)
		cout<<"+";
	cout<<b1<<"y"<<"="<<c1<<endl;
	
	cout<<a2<<"x";
	if (b2>=0)
		cout<<"+";
	cout<<b2<<"y"<<"="<<c2<<endl;
}
void PTBac1::GiaiHePT()
{
	float D=a1*b2-a2*b1;
	float Dx=c1*b2-b1*c2;
	float Dy=a1*c2-a2*c1;
	float x=Dx/D;
	float y=Dy/D;
	
	if (D!=0)
	{
		cout<<"phuong trinh co 2 nghiem:"<<endl;
		cout<<"X: "<<x<<endl;
		cout<<"y: "<<y;
	}
	
	else
	{
		if(Dx==0&&Dy==0)
			cout<<"phuong trinh vo so nghiem.";
		else
			cout<<"phuong trinh vo nghiem.";
	}
}

int main()
{
	PTBac1 pt;
	pt.Nhap();
	cout<<"--------pt---------"<<endl;
	pt.Xuat();
	pt.GiaiHePT();
	
}








