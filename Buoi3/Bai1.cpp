#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
class  ThiSinh
{
	
	private:
		char HoTen[50], NgaySinh[10];
		float Word, Excel, TracNghiem;
	public:
		ThiSinh();
		ThiSinh(char* HoTen, char* NgaySinh, float Word, float Excel, float TracNghiem);
		void Nhap();
		void Xuat();
		int KetQua();	
};
int main()
{
	ThiSinh ts;
	cout<<endl<<"---------NHAP THONG TIN THI SINH---------"<<endl;
	ts.Nhap();
	cout<<"------------THONG TIN THI SINH---------"<<endl;
	ts.Xuat();
	ts.KetQua();
	return 0;
}
ThiSinh::ThiSinh()
{
}

ThiSinh::ThiSinh(char* HoTen, char* NgaySinh, float Word, float Excel, float TracNghiem)
{
	strcpy(this->HoTen,HoTen);
	strcpy(this->NgaySinh,NgaySinh);
	this->Word=Word;
	this->Excel=Excel;
	this->TracNghiem=TracNghiem;
}
void ThiSinh::Nhap()
{

	cout<<"Nhap ho ten: ";
	fflush(stdin);
	gets(HoTen);
	cout<<"Nhap ngay sinh: ";
	fflush(stdin);
	gets(NgaySinh);
	cout<<"Nhap diem Word: ";
	cin>>Word;
	cout<<"Nhap diem Excel: ";
	cin>>Excel;
	cout<<"Nhap diem trac nghiem: ";
	cin>>TracNghiem;
}
void ThiSinh::Xuat()
{
	cout<<"-Ho ten:"<<HoTen<<endl;
	cout<<"-Ngay sinh:"<<NgaySinh<<endl;
	cout<<"-Diem Word:"<<Word<<endl;
	cout<<"-Diem Excel:"<<Excel<<endl;
	cout<<"-Diem trac nghiem:"<<TracNghiem<<endl;

}
int ThiSinh::KetQua()
{
	int DiemTB=(Word+Excel+TracNghiem)/3;
	if(DiemTB<5 ||Word<5|| Excel<5|| TracNghiem<5)
		cout<<"Ket qua: Rot"<<endl;
	else
		cout<<"Ket qua: Dau"<<endl;	
	return 0;
}













