/*
Bài 43(lthdtbai43.cpp): Viết chương trình quản lý nhân sự của một trường học;
nhân sự gồm có giảng viên và sinh viên; giảng viên có mã gv, họ tên và số bài báo;
sinh viên có mã sv, họ tên và điểm tbc. Nhập vào một số nhân sự trong đó có cả giảng viên
và sinh viên. Đưa ra thông tin của các nhân sự đã nhập kèm theo đánh giá:
giảng viên đánh giá là giỏi nếu số bài báo >=5, sinh viên đánh giá là giỏi
nếu điểm TBC>=8.0. Y/c cài đặt đa hình động.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop hinh
class NhanSu
{
    private:
        char hoTen[31];

    public:
        virtual void nhap();
        virtual void hien();
};

class GiangVien:public NhanSu
{
    private:
        char maGV[10];
        int sbb;

    public:
        void nhap();
        void hien();
};
class SinhVien:public NhanSu
{
    private:
        char maSV[10];
        float diemTBC;

    public:
        void nhap();
        void hien();
};

//===Chuong trinh chinh===
int main()
{
    //Khai bao mang con tro lop co so Nhan su
    NhanSu* ds[50];

    //Khai bao bien
    int n=0;
    char traloi1,traloi2;

    //Nhap
    do
    {
        cout<<"\nChon nhan su de nhap (1-Giang vien,2-Sinh vien)? ";
        cin>>traloi1;

        switch(traloi1)
        {
            case '1':
                ds[n]=new GiangVien;
                break;
            case '2':
                ds[n]=new SinhVien;
                break;
            default:
                ds[n]=new GiangVien;
        }

        //Dung da hinh dong de nhap kich thuoc hinh da chon
        ds[n++]->nhap();

        cout<<"Co nhap nua khong (c/k)? ";
        cin>>traloi2;
    }
    while(traloi2=='c'||traloi2=='C');

    cout<<"\nDanh sach nhan su da nhap la:\n";
    for(int i=0;i<n;i++)
    {
        ds[i]->hien(); //Su dung da hinh dong de hien thong tin nhan su

        cout<<"\n\n";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Ham thanh vien lop Nhan su
void NhanSu::nhap()
{
    cout<<"Nhap ho ten: ";
    scanf(" ");cin.get(hoTen,sizeof(hoTen));
}

void NhanSu::hien()
{
    cout<<"Ho ten: "<<hoTen;
}

//Ham thanh vien lop Giang vien
void GiangVien::nhap()
{
    cout<<"Nhap ma giang vien: ";
    cin>>maGV;
    NhanSu::nhap();
    cout<<"Nhap so bai bao: ";
    cin>>sbb;
}

void GiangVien::hien()
{
    cout<<"Ma giang vien: "<<maGV<<endl;
    NhanSu::hien();
    cout<<"\nSo bai bao: "<<sbb;
    if(sbb>=5) cout<<"\nLa giang vien gioi!";
}

//Ham thanh vien lop Sinh vien
void SinhVien::nhap()
{
    cout<<"Nhap ma sinh vien: ";
    cin>>maSV;
    NhanSu::nhap();
    cout<<"Nhap diem tbc: ";
    cin>>diemTBC;
}

void SinhVien::hien()
{
    cout<<"Ma sinh vien: "<<maSV<<endl;
    NhanSu::hien();
    cout<<"\nDiem TBC: "<<diemTBC;
    if(diemTBC>=8) cout<<"\nLa sinh vien gioi!";
}


