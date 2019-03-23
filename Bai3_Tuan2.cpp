#include<iostream>
#include<math.h>
#include <iomanip> 
using namespace std;
const double PI=3.14159265359;
class Diem
{
	int x,y;
public:
	Diem(int h=0,int t=0);
	Diem(const Diem & d);
	int KiemTraTrung(const Diem & d);
	double KhoangCach(const Diem & d2);
	Diem DoiXungX();
	Diem DoiXungY();
	Diem DoiXungO();
	int getX();
	int getY();
	void Nhap();
	void Xuat(char s[]="");		
};
Diem::Diem(int h,int t)
{
	x=h,y=t;
}
Diem::Diem(const Diem & d)
{
	*this=d;
}
int Diem::KiemTraTrung(const Diem & d)
{
	if(x==d.x&&y==d.y)
		return 1;
	return 0;
}
double Diem::KhoangCach(const Diem & d2)
{
	return sqrt((x-d2.x)*(x-d2.x)+(y-d2.y)*(y-d2.y));
}
Diem Diem::DoiXungX()
{
	return Diem(x,-y);
}
Diem Diem::DoiXungY()
{
	return Diem(-x,y);
}
Diem Diem::DoiXungO()
{
	return Diem(-x,-y);
}
int Diem::getX()
{
	return x;
}
int Diem::getY()
{
	return y;
}
void Diem::Nhap()
{
	cout<<"Nhap toa do x: ";cin>>x;
	cout<<"Nhap toa do y: ";cin>>y;
}
void Diem::Xuat(char s[])
{
	cout<<s<<"("<<x<<","<<y<<")"<<endl;
}

class DoanThang
{
	Diem mut1,mut2;
public:
	DoanThang();
	DoanThang(const Diem &d1, const Diem &d2);
	DoanThang(int x1,int y1,int x2,int y2);
	DoanThang(const DoanThang &s);
	void Nhap(); 
	void Xuat();
	double DoDai();
	double Goc(DoanThang dt2);
	void vectorChiPhuong();
	void vectorPhapTuyen();
	void phuongtrinhtongquat();
	//Xu?t vector ch? ph??ng: v=(a,b)=(mut1.x-mut2.x,mut1.y-mut2.y)
	//Xu?t vector pháp tuy?n: u=(-b,a)=(b,-a)
	//Xu?t ph??ng trình t?ng quát ???ng th?ng ax+by+c: -b(x-mut1.x)+a(y-mut1.y)
};
DoanThang::DoanThang()
{
	mut1=Diem(0,0);
	mut2=Diem(1,1);
}
DoanThang::DoanThang(const Diem &d1, const Diem &d2)
{
	mut1=d1;
	mut2=d2;
	int kt;
	kt=mut1.KiemTraTrung(mut2);
	if(kt==1)
	{
		cout<<"2 diem trung nhau. Doan thang se lay gia tri mac dinh"<<endl;
		mut1=Diem(0,0);
		mut2=Diem(1,1);
		Xuat();
	}
	
}
DoanThang::DoanThang(int x1,int y1,int x2,int y2)
{
	mut1=Diem(x1,y1);
	mut2=Diem(x2,y2);
	int kt;
	
	kt=mut1.KiemTraTrung(mut2);
	if(kt==1)
	{
		cout<<"2 diem trung nhau. Doan thang se lay gia tri mac dinh"<<endl;
		mut1=Diem(0,0);
		mut2=Diem(1,1);
		Xuat();
	}
	
}
DoanThang::DoanThang(const DoanThang &s)
{
	*this=s;
}
void DoanThang::Nhap()
{
	int kt;
	do{
		cout<<"Nhap diem 1: "<<endl;
		mut1.Nhap();	
		cout<<"Nhap diem 2: "<<endl;
		mut2.Nhap();
		kt=mut1.KiemTraTrung(mut2);
		if(kt==1)
			cout<<"Ban nhap 2 diem trung nhau. Vui long nhap lai!"<<endl;
	}
	while(kt==1);
	
} 
void DoanThang::Xuat()
{
	mut1.Xuat("Diem 1: ");
	mut2.Xuat("Diem 2: ");
}
double DoanThang::DoDai()
{
	return mut1.KhoangCach(mut2);
}
double DoanThang::Goc(DoanThang dt2)
{
	double a1,a2,b1,b2;
	a1=mut1.getX()-mut2.getX();
	a2=mut1.getY()-mut2.getY();
	b1=dt2.mut1.getX()-dt2.mut2.getX();
	b2=dt2.mut1.getY()-dt2.mut2.getY();
	
	return acos((a1*b1+a2*b2)/(sqrt(a1*a1+a2*a2)*sqrt(b1*b1+b2*b2)))*180/PI;
}
void DoanThang::vectorChiPhuong(){
	double a1,a2;
	a1=mut1.getX()-mut2.getX();
	a2=mut1.getY()-mut2.getY();
	cout<<"Vector chi phuong: "<<"("<<a1<<","<<a2<<")";
}
void DoanThang::vectorPhapTuyen()
{
	double a,b;
	a=mut1.getX()-mut2.getX();
	b=mut1.getY()-mut2.getY();
	cout<<"Vector phap tuyen: "<<"("<<-b<<","<<a<<")";
}
void DoanThang::phuongtrinhtongquat()
{
	// -b(x-mut1.x)+a(y-mut1.y)
	//-bx+b*mut1.x+a*y-a*mut1.y
	//-bx+ay+b*mut1.x-a*mut1.y
	double a,b,c;
	a=mut1.getX()-mut2.getX();
	b=mut1.getY()-mut2.getY();
	c=(b*mut1.getX()-a*mut1.getY());
	if(a==0)
	{
	
		cout<<-b<<"x";
		if(c>0)
			cout<<" + " <<c;
		else if(c<0)
			cout<<" - " <<-c;	
		cout<<" = 0"<<endl;
		return;
	}
	if(b==0)
	{
	
		cout<<a<<"y";
		if(c>0)
			cout<<" + " <<c;
		else if(c<0)
			cout<<" - " <<-c;	
		cout<<" = 0"<<endl;
		return;
	}
	if(-b!=0)
		cout<<-b<<"x";
	if(a>0)
		cout<<" + " <<a<<"y";
	else if(a<0)
		cout<<" - " <<-a<<"y";
	if(c>0)
		cout<<" + " <<c;
	else if(c<0)
		cout<<" - " <<-c;	
	cout<<" = 0"<<endl;	
}

class HinhChuNhat
{
	Diem A,B,C,D;
public:
	HinhChuNhat(); //hinh chu nhat don vi (0,0),(0,1),(1,1),(1,0)
	HinhChuNhat(const Diem &d1, const Diem &d2, const Diem &d3, const Diem &d4);
	HinhChuNhat (int x1,int y1,int x2,int y2, int x3,int y3,int x4,int y4);
	double DienTich();
	double ChuVi();
	double CanhAB();
	double CanhBC();
	double CanhCD();
	double CanhDA();
	static int KTHinhChuNhat(Diem d1, Diem d2, Diem d3, Diem d4);
	static int KTHinhChuNhat1(Diem d1, Diem d2, Diem d3, Diem d4);
	void Nhap();
	void Xuat();

};
HinhChuNhat::HinhChuNhat() //hinh chu nhat don vi (0,0),(0,1),(1,1),(1,0)
{	
	A=Diem(0,0);
	B=Diem(0,1);
	C=Diem(1,1);
	D=Diem(1,0);
}
HinhChuNhat::HinhChuNhat(const Diem &d1, const Diem &d2, const Diem &d3, const Diem &d4)
{
	A=d1;
	B=d2;
	C=d3;
	D=d4;
}
HinhChuNhat::HinhChuNhat (int x1,int y1,int x2,int y2, int x3,int y3,int x4,int y4)
{
	A=Diem(x1,y1);
	B=Diem(x2,y2);
	C=Diem(x3,y3);
	D=Diem(x4,y4);
}
int HinhChuNhat::KTHinhChuNhat(Diem d1, Diem d2, Diem d3, Diem d4)
{
	DoanThang AB(d1,d2);
	DoanThang BC(d2,d3);
	DoanThang CD(d3,d4);
	DoanThang DA(d4,d1);
	
	if(AB.Goc(BC)==90.0&&CD.Goc(DA)==90.0&&BC.Goc(CD)==90.0)
		return 1;
	return 0;
	
}

int HinhChuNhat::KTHinhChuNhat1(Diem d1, Diem d2, Diem d3, Diem d4)
{
	int x1,x2,y1,y2,z1,z2,t1,t2,v1,v2,w1,w2;
	x1=d1.getX()-d2.getX();
	x2=d1.getY()-d2.getY();
	y1=d2.getX()-d3.getX();
	y2=d2.getY()-d3.getY();
	z1=d3.getX()-d4.getX();
	z2=d3.getY()-d4.getY();
	t1=d4.getX()-d1.getX();
	t2=d4.getY()-d1.getY();
	
	
	if(x1*y1+x2*y2==0&&z1*t1+z2*t2==0&&y1*z1+y2*z2==0)
		return 1;
	return 0;
	
}

double HinhChuNhat::DienTich()
{
	return A.KhoangCach(B)*C.KhoangCach(D);
}
double HinhChuNhat::ChuVi()
{
	return 2*(A.KhoangCach(B)+C.KhoangCach(D));
}
double HinhChuNhat::CanhAB()
{
	return A.KhoangCach(B);
}
double HinhChuNhat::CanhBC()
{
	return B.KhoangCach(C);
}
double HinhChuNhat::CanhCD()
{
	return C.KhoangCach(D);
}
double HinhChuNhat::CanhDA()
{
	return D.KhoangCach(A);
}
void HinhChuNhat::Nhap()
{
	cout<<"Diem A: "<<endl;
	A.Nhap();
	cout<<"Diem B: "<<endl;
	B.Nhap();
	cout<<"Diem C: "<<endl;
	C.Nhap();
	cout<<"Diem D: "<<endl;
	D.Nhap();
}
void HinhChuNhat::Xuat()
{
	cout<<"Diem A: ";
	A.Xuat();
	cout<<endl;
	cout<<"Diem B: ";
	B.Xuat();
	cout<<endl;
	cout<<"Diem C: ";
	C.Xuat();
	cout<<endl;
	cout<<"Diem D: ";
	D.Xuat();
	cout<<endl;
}
int main()
{
	Diem d1(-1,1);
	Diem d2(3,-3);
	Diem d3(-1,-7);
	Diem d4(-5,-3);
	DoanThang dt1(d1,d2);
	DoanThang dt2(d2,d3);
	DoanThang dt3(d3,d4);
	DoanThang dt4(d4,d1);
	
	cout<<"Goc dt1 va dt2 "<<std::setprecision(15)<<dt1.Goc(dt2)<<endl;
	cout<<"Goc dt3 va dt4 "<<std::setprecision(15)<<dt3.Goc(dt4)<<endl;
	cout<<"KT HCN: "<<HinhChuNhat::KTHinhChuNhat(d1,d2,d3,d4)<<endl;
	cout<<"KT HCN: "<<HinhChuNhat::KTHinhChuNhat1(d1,d2,d3,d4)<<endl;
	
	HinhChuNhat hcn(d1,d2,d3,d4);
	cout<<"AB:"<<hcn.CanhAB()<<endl;
	cout<<"BC:"<<hcn.CanhBC()<<endl;
	cout<<"CD:"<<hcn.CanhCD()<<endl;
	cout<<"DA:"<<hcn.CanhDA()<<endl;
	cout<<"Chu vi: "<<hcn.ChuVi()<<endl;
	cout<<"Dien tich: "<<hcn.DienTich()<<endl;
}
