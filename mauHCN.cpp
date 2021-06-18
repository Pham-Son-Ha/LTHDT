/*
 Tính diện tích và chu vi hình chữ nhật có 2 cạnh a, b.
 */
#include<stdio.h>
#include<iostream>

using namespace std;

//Khai bao lop
class HinhCN
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//===chuong trinh chinh===
int main ()
{
    //Tao 1 doi tuong hinh chu nhat
    HinhCN hcn;

    //Tuong tac voi doi tuong hc
    hcn.nhap();

    //dua ra dien tich va chu vi
    cout<<"Dien tich hinh chu nhat la: "<<hcn.tinhDT();
    cout<<"\nChu vi hinh chu nhat la: "<<hcn.tinhCV();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh a va b: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

float HinhCN::tinhCV()
{
    return (a+b)*2;
}

