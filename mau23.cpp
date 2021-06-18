/*
Bài 23(lthdtbai23.cpp): Nhập vào một danh sách n mặt hàng; mỗi mặt hàng có tên hàng, số lượng, đơn giá.
Tính tổng tiền của n mặt hàng.
*/

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class MatHang
{
    private:
        char tenMatHang[30];
        int soLuong;
        float donGia;

    public:
        float tinhTien();

        //Ham ban
        friend istream& operator>>(istream &cin,MatHang &mh);
        friend ostream& operator<<(ostream &cout,MatHang &mh);
};

//===Chuong trinh chinh===
int main()
{
    //Khai bao bien
    int n;
    float tongTien=0;

    //Nhap n
    cout<<"Nhap vao so luong mat hang: ";cin>>n;

    //Tao mang dong n doi tuong mat hang de chua n mat hang
    MatHang *ds = new MatHang[n];

    //Nhap n mat hang va tinh tong tien cua n mat hang
    cout<<"Nhap thong tin cac mat hang:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap mat hang thu "<<i+1<<":\n";
        cin>>ds[i];

        tongTien += ds[i].tinhTien();
    }

    //Dua ra
    cout<<"\nDanh sach cac mat hang da nhap la:";
    for(int i=0;i<n;i++)
    {
        cout<<"\nMat hang thu "<<i+1<<":";
        cout<<ds[i];

        cout<<"\n\n";
    }

    printf("\nTong tien cua %d mat hang la: %0.1f",n,tongTien);

    //Huy mang dong cac doi tuong
    delete [] ds;

    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
float MatHang::tinhTien()
{
    return soLuong*donGia;
}

istream& operator>>(istream &cin,MatHang &mh)
{
    cout<<"Nhap vao ten mat hang: ";scanf(" ");cin.get(mh.tenMatHang,sizeof(mh.tenMatHang));
    cout<<"Nhap vao so luong: ";cin>>mh.soLuong;
    cout<<"Nhap vao don gia: ";cin>>mh.donGia;

    return cin;
}

ostream& operator<<(ostream &cout,MatHang &mh)
{
    cout<<"\n\tTen mat hang: "<<mh.tenMatHang;
    cout<<"\n\tSo luong: "<<mh.soLuong;
    printf("\n\tDon gia: %0.1f",mh.donGia);
    printf("\n\tThanh tien: %0.1f",mh.soLuong*mh.donGia);

    return cout;
}


