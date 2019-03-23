#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;



class DIEM 
{
	int x,y;
	public:
		DIEM();
		DIEM(int ,int);
		void Nhap();
		void Xuat();
		float KC(DIEM d2);
		int Getx();
		int Gety();		
};
int main()
{
	DIEM d1,d2;
	
	cout<<"nhap toa do diem 1:"<<endl;
	d1.Nhap();
	
	cout<<"nhap toa do diem 2:"<<endl;
	d2.Nhap();
	
	cout<<"diem 1:";
	d1.Xuat();
	
	cout<<endl<<"diem 2:";
	d2.Xuat();
	
	cout<<endl<<"khoang cach :  "<<d2.KC(d1);
}

DIEM::DIEM()
{
	x=y=0;
}
DIEM::DIEM(int tdx,int tdy)
{
	x=tdx;
	y=tdy;
}
void DIEM::Nhap()
{
	cout<<"nhap x: ";cin>>x;
	cout<<"nhap y: ";cin>>y;
	
}
void DIEM::Xuat()
{
	cout<<"("<<x<<","<<y<<")";
}
float DIEM::KC(DIEM d2)
{
	return	sqrt((x-d2.x)*(x-d2.x)+(y-d2.y)*(y-d2.y));
	
}

