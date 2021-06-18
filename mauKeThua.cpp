/*
De:Viet chuong trinh thinh the tich va dien tich be mat cua hinh tru co ban kinh r va chieu cao h. Biet rang hinh tru la mot loai hinh tron co ban kinh r duoc keo dai voi chieu cao h
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop hinh tron
class HinhTron
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao lop hinh tru ke thua tu lop hinh tron
class HinhTru:public HinhTron
{
    private:
        float h;

    public:
        void nhap();
        float tinhDT();
        float tinhTT();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong hinh tru
    HinhTru h;

    cout<<"Nhap vao kich thuoc hinh tru:\n";
    h.nhap();

    printf("Dien tich hinh tru la: %0.1f",h.tinhDT());
    printf("\nThe tich hinh tru la: %0.1f",h.tinhTT());

    cout<<endl;
    return 0;
}

//===dinh nghia ham===
void HinhTron::nhap()
{
    cout<<"Nhap vao ban kinh r: ";
    cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14 * r * r;
}

float HinhTron::tinhCV()
{
    return 2 * 3.14 * r;
}

void HinhTru::nhap()
{
    HinhTron::nhap();
    cout<<"Nhap vao chieu cao h: ";
    cin>>h;
}

float HinhTru::tinhDT()
{
    return 2*HinhTron::tinhDT() + HinhTron::tinhCV()*h;
}

float HinhTru::tinhTT()
{
    return HinhTron::tinhDT()*h;
}

