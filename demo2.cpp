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
class DoanThang
{
	DIEM A, B;
	public:
		DoanThang();
		DoanThang(const DIEM &d1, const DIEM &d2);
		DoanThang(int x1,int y1,int x2, int y2);
		void Nhap();
		void Xuat();
		float DoDai();
};
DoanThang::DoanThang()
{
	A=DIEM(0,0);
	B=DIEM(1,1);
}
DoanThang::DoanThang(const DIEM &d1, const DIEM &d2)
{
	A=d1;
	B=d2;
}
DoanThang::DoanThang(int x1,int y1,int x2, int y2)
{
	A=DIEM(x1,y1);
	B=DIEM(x2,y2);
}
void DoanThang::Nhap()
{
	cout<<"nhap toa do diem A:"<<endl;
	A.Nhap();
	cout<<"nhap toa do diem B:"<<endl;
	B.Nhap();
}
void DoanThang::Xuat()
{
	cout<<endl<<"toa do diem A:";
	A.Xuat();
	cout<<endl<<"toa do diem B:";
	B.Xuat();
}
float DoanThang::DoDai()
{
	return A.KC(B);
}
int main()
{
	DoanThang dt;
	dt.Nhap();
	dt.Xuat();
	
	cout<<endl<<"d(A ,B) = "<<dt.DoDai();
	
}
