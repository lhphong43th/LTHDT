#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class ThiSinh
{
	private:
		char  ms[10], hoten[50], ngaysinh[10], hstruong[50], diachi[50];
		int gt;
		float toan, van, anh;
	public:
		ThiSinh(){
		}	
		ThiSinh(char* MSTS, char* HoTen, char* NgaySinh, int GioiTinh, char* HSTruong, char* DiaChi, float Toan, float Van, float Anh);
		void Nhap();
		void Xuat();
		int KetQua();
		int GiayBD();
		
		
};

ThiSinh::ThiSinh(char* MSTS, char* HoTen, char* NgaySinh, int GioiTinh, char* HSTruong, char* DiaChi, float Toan, float Van, float Anh)
{
	strcpy(ms,MSTS);
	strcpy(hoten, HoTen);
	strcpy(ngaysinh, NgaySinh);
	gt=GioiTinh;
	strcpy(hstruong, HSTruong);
	strcpy(diachi, DiaChi);
	
	toan=Toan;
	van=Van;
	anh=Anh;
}
void ThiSinh::Nhap()
{
	
	int n;
	cout<<" NHAP DANH SACH THI SINH"<<endl;
	cout<<"-Nhap so phan tu:";
	cin>>n;
	for ( int i=1; i<=n; i++)
	{
		cout<<"Nhap thong tin thi sinh thu "<<i<<endl;
		cout<<"Nhap ma so thi sinh:";
		fflush(stdin);
		gets(ms);
		cout<<"Nhap ho ten:";
		fflush(stdin);		
		gets(hoten);
		cout<<"Nhap ngay sinh:";
		fflush(stdin);		
		gets(ngaysinh);
		cout<<"Nhap gioi tinh:";
		cin>>gt;
		cout<<"Nhap truong:";
		fflush(stdin);
		gets(hstruong);
		cout<<"Nhap dia chi:";
		fflush(stdin);			
		gets(diachi);
		cout<<"Nhap diem toan:";
		fflush(stdin);
		//cin>>toan;
		scanf("%f", &toan);
		cout<<"Nhap diem van:";
		//cin>>van;
		scanf("%f", &van);

		cout<<"Nhap diem anh:";
		//cin>>anh;
		scanf("%f", &anh);

		
	}
	
}
void ThiSinh::Xuat()
{
	cout<<"-Ho ten:"<<hoten<<endl;
	cout<<"-Ngay sinh:"<<ngaysinh<<endl;
	cout<<"-Gioi tinh:"<<gt<<endl;
	cout<<"-Hoc sinh truong:"<<hstruong<<endl;
	cout<<"-Dia chi:"<<diachi<<endl;
	cout<<"-Diem toan:"<<toan<<endl;
	cout<<"-Diem van:"<<van<<endl;
	cout<<"-Diem anh:"<<anh<<endl;
	
}
int ThiSinh::KetQua()
{
	int diemchuan;
	cout<<"Nhap diem chuan:";
	cin>>diemchuan;
	float DiemTB=(toan+van+anh) / 3;
	if(DiemTB>=5 || toan>=3 || van>=3 || anh>=3 && DiemTB >= diemchuan)
		cout<<"-Ket qua: Rot"<<endl;
	else
		cout<<"-Ket qua: Dau"<<endl;
	return 0;		
}
int ThiSinh::GiayBD()
{

}



int main()
{
	ThiSinh ts;
	int n, chon = 0;
	int isExit = false;
	do 
	{
		system("cls");
        cout<<"\t\t\t ====================MENU=================="<<endl;
        cout<<"\t\t\t |1. Tao danh sach sinh vien                    |"<<endl;
        cout<<"\t\t\t |2. Xuat danh sach sinh vien                   |"<<endl;
        cout<<"\t\t\t |3. Ket qua thi theo diem chuan                |"<<endl;
        cout<<"\t\t\t |4. Giay bao diem                              |"<<endl;        
        cout<<"\t\t\t |5. Thoat                                      |"<<endl;
        cout<<"Lua chon cong viec tuong ung: ";
        cin>>chon;
        switch(chon)
        {
        	case 1:
        	{
        		//cout<<"Nhap so luong thi sinh:";
                //cin>>n;
                ts.Nhap();
                printf("\nBan da nhap thanh cong!");
                isExit = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
			}
			case 2:
			{
				ts.Xuat();
				getch();
				break;
			}
			case 3:
				{
					ts.KetQua();
					getch();
					break;
				}
			case 4:
                {
                	ts.Xuat();
                	ts.KetQua();
                	ts.GiayBD();
                	getch();
                	break;
				}
			case 5:
				getch();
					break;
            default:
                cout<<"Ban chon sai. Moi ban chon lai MENU!"<<endl;
                getch();
                break;	
		}
	}while(!isExit);
	


	
	return 0;
}

