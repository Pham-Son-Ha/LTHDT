/*
Bài 27(lthdtbai27.cpp): Viết chương trình nhập vào danh sách n sinh viên,
mỗi sinh viên có thông tin về mã sinh viên, tên và điểm tbc.
Mã SV là các số nguyên được lấy tự động có giá trị từ 11 trở đi.
Đưa ra màn hình số lượng (không dùng n) và danh sách sinh viên đã nhập.
Yêu cầu trong chương trình có sử dụng biến tĩnh và hàm tĩnh;
sử dụng mảng đối tượng động.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop sinh vien
class SinhVien
{
    private:
        int maSV;
        char hoTen[31];
        float diemTBC;

        //Bien cua lop
        static int stt;

    public:
        void nhap();
        void hien();

        //Ham cua lop
        static int laySL();
};

//Dinh nghia bien cua lop va khoi tao gia tri ban dau
int SinhVien::stt = 10;

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n;

    cout<<"Nhap vao so luong sinh vien: ";
    cin>>n;

    //Tao mang dong ds n doi tuong SinhVien de chua thong tin cua n sv
    SinhVien *ds = new SinhVien[n];

    //Nhap thong tin cua n sv vao n doi tuong
    cout<<"Nhap thong tin sinh vien:\n";
    for(int i=0;i<n;i++)
    {
        printf("Sinh vien thu %d:\n",i+1);
        ds[i].nhap();
        cout<<endl;
    }

    cout<<"\nDanh sach cac sinh vien da nhap la:\n";
    for(int i=0;i<n;i++)
    {
        printf("Sinh vien thu %d:\n",i+1);
        ds[i].hien();
        cout<<"\n\n";
    }

    cout<<"Tong so sinh vien da nhap la: "<<SinhVien::laySL(); //Goi ham cua lop

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void SinhVien::nhap()
{
    //Tao ma sinh vien tu dong
    maSV = ++stt;

    //Nhap ho ten va diem tbc
    cout<<"Ma sinh vien: "<<maSV<<endl;
    cout<<"Ho ten: ";scanf(" ");cin.get(hoTen,sizeof(hoTen));
    cout<<"Diem TBC: ";cin>>diemTBC;
}

void SinhVien::hien()
{
    cout<<"Ma sinh vien: "<<maSV;
    cout<<"\nHo ten: "<<hoTen;
    cout<<"\nDiem TBC: "<<diemTBC;
}

//Ham cua lop
int SinhVien::laySL()
{
    return stt-10;
}


