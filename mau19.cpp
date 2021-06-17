/*
Bài 19(lthdtbai19.cpp): Cho điểm A(x1,y1) và điểm B(x2,y2). Tính khoảng cách AB.
*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop diem trong mat phang
class Diem
{
    private:
        float x,y;

    public:
        Diem();
        Diem(float x,float y);
        float tinhKC(const Diem &D2);

        //Ham ban
        friend istream& operator>>(istream &cin,Diem &D);
        friend ostream& operator<<(ostream &cout,Diem &D);
};

//===chuong trinh chinh===
int main()
{
    //Tao 2 doi tuong diem A, B
    Diem A,B;

    //Nhap toa do
    cout<<"Nhap toa do diem A:\n";
    cin>>A;
    cout<<"Nhap toa do diem B:\n";
    cin>>B;

    //Tinh khoang cach AB
    float kc = A.tinhKC(B);

    //Dua ra kq
    cout<<"\nDiem A"<<A;
    cout<<"\nDiem B"<<B;
    printf("\nKhoang cach AB = %0.1f",kc);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Diem::Diem():x(0),y(0)
{

}

Diem::Diem(float x,float y):x(x),y(y)
{

}

float Diem::tinhKC(const Diem &D2)
{
    return sqrt((D2.x-x)*(D2.x-x) + (D2.y-y)*(D2.y-y));
}

//Ham ban, ham thong thuong, khong nam trong doi tuong
istream& operator>>(istream &cin,Diem &D)
{
    cout<<"Nhap toa do x y: ";
    cin>>D.x>>D.y;

    return cin;
}

ostream& operator<<(ostream &cout,Diem &D)
{
    printf("(%0.1f,%0.1f)",D.x,D.y);

    return cout;
}


