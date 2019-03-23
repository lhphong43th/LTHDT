#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
class  NhanVien
{
	
	private:
		char HoTen[50], NgaySinh[10];
		int SoNgayLV;
		float  LuongCB, TroCap ;
		int Luong;
	public:
		NhanVien();
		NhanVien(char* HoTen, char* NgaySinh,int SoNgayLV, float LuongCB, float TroCap );
		void Nhap();
		void Xuat();
		int TinhLuong();
		
};
int main()
{
	NhanVien nv;
	nv.Nhap();
	nv.Xuat();
	nv.TinhLuong();
	return 0;
}
NhanVien::NhanVien()
{
}
NhanVien::NhanVien(char* HoTen, char* NgaySinh,int SoNgayLV, float LuongCB, float TroCap )
{
	strcpy(this->HoTen, HoTen);
	strcpy(this->NgaySinh,NgaySinh);
	this->Luong=Luong;
	this->LuongCB=LuongCB;
	this->SoNgayLV=SoNgayLV;
	this->TroCap=TroCap;
}
void NhanVien::Nhap()
{
	cout<<"Nhap ho ten:";
	fflush(stdin);
	gets(HoTen);
	cout<<"Nhap ngay sinh:";
	fflush(stdin);
	gets(NgaySinh);
	cout<<"Nhap luong can ban:";
	cin>>LuongCB;
	cout<<"Nhap so ngay lam viec:";
	cin>>SoNgayLV;
	cout<<"Nhap tro cap:";
	cin>>TroCap;
}
void NhanVien::Xuat()
{
	cout<<"-Ho ten:"<<HoTen<<endl;
	cout<<"-Ngay sinh:"<<NgaySinh<<endl;
	TinhLuong();
	cout<<"-Luong can ban:"<<LuongCB<<endl;
	cout<<"-So Ngay lam viec:"<<SoNgayLV<<endl;
	cout<<"-Tro cap:"<<TroCap<<endl;
}
int NhanVien::TinhLuong()
{
    int	TinhLuong = (LuongCB+( SoNgayLV*100000)+ TroCap);
    cout<<"-Luong:"<<TinhLuong<<endl;
	return 0;
}
