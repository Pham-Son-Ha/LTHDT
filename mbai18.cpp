/*Bài 18(lthdtbai18.cpp): Tính tổng 2 phân số, đưa các phân số ra màn hình ở dạng chưa rút gọn và đã rút gọn.*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class PhanSo
{
    private:
        int tuSo,mauSo;
    public:
        PhanSo();
        PhanSo rutGon();
        PhanSo operator+(const PhanSo &ps2);
        friend istream& operator>>(istream &cin, PhanSo &ps);
        friend ostream& operator<<(ostream &cout, PhanSo &ps);
};
//===chuong trinh chinh====
int main()
{
    //Tao 3 doi tuong phan so
    PhanSo ps1,ps2,tong;

    //Nhap
    cout<<"Nhap vao phan so 1 ";
    cin>>ps1;
    cout<<"Nhap vao phan so 2 ";
    cin>>ps2;

    //Tinh tong
    tong = ps1 + ps2;

    //Dua ra
    cout<<"\nPhan so truoc khi rut gon la:";
    cout<<"\nps1 = "<<ps1;
    cout<<"\nps2 = "<<ps2;
    cout<<"\nps1 + ps2 = "<<tong;

    //Rut gon
    ps1.rutGon();
    ps2.rutGon();
    tong.rutGon();

    cout<<"\n\nPhan so sau khi rut gon la:";
    cout<<"\nps1 = "<<ps1;
    cout<<"\nps2 = "<<ps2;
    cout<<"\nps1 + ps2 = "<<tong;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
PhanSo::PhanSo():tuSo(0),mauSo(1)
{

}

PhanSo PhanSo::rutGon()
{
    int a= tuSo,b= mauSo;
    int r = a%b;

    //Tim UCLN
    while(r)
    {
        a=b;b=r;r =a%b;
    }

    // Rut gon
    tuSo =tuSo/b;
    mauSo =mauSo/b;

    return *this;
}

PhanSo PhanSo::operator+(const PhanSo &ps2)
{
    PhanSo tg;
    if(mauSo == ps2.mauSo)
    {
        tg.tuSo = tuSo+ ps2.tuSo;
        tg.mauSo = mauSo;
    }
    else
    {

        tg.tuSo = tuSo*ps2.mauSo + mauSo*ps2.tuSo;
        tg.mauSo = mauSo* ps2.mauSo;
    }

    return tg;
}

istream& operator>>(istream &cin, PhanSo &ps)
{
    char kt;

    cout<<"(dang a/b): ";
    cin>>ps.tuSo>>kt>>ps.mauSo;

    return cin;
}

ostream& operator<<(ostream &cout, PhanSo &ps)
{
    if(ps.tuSo*ps.mauSo < 0) cout<<"-"<<fabs(ps.tuSo)<<"/"<<fabs(ps.mauSo);
    else cout<<fabs(ps.tuSo)<<"/"<<fabs(ps.mauSo);

    return cout;
}
