/*
Bài 25(lthdtbai25.cpp): Viết chương trình nhập vào một thời gian có giờ và phút.
Tính và đưa ra màn hình thời gian sau n phút nhập vào từ bàn phím.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai báo lớp
class ThoiGian
{
    private:
        int gio,phut;

    public:
        ThoiGian();
        ThoiGian operator+(int n);

        //Hàm bạn
        friend istream& operator>>(istream &cin,ThoiGian &t);
        friend ostream& operator<<(ostream &cout,ThoiGian &t);
};

//===Chuong trinh chinh===
int main()
{
    //Tao 2 doi tuong thoi gian
    ThoiGian bd,kt;

    //Khai bao bien
    int n;

    //Nhap du lieu
    cout<<"Nhap vao thoi gian bat dau ";cin>>bd;
    cout<<"Nhap vao so phut: ";cin>>n;

    //Tinh thoi gian sau n phut
    kt = bd + n;

    //Dua ra
    cout<<"\nThoi gian bat dau: "<<bd;
    cout<<"\nThoi gian sau "<<n<<" phut la: "<<kt;

    cout<<endl;
    return 0;
}

//===Dinh nghia ham===
ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian ThoiGian::operator+(int n)
{
    ThoiGian tg;

    tg.phut = phut + n;
    tg.gio = gio;

    //Dua tg.phut ve gia tri hop le: 0<=tg.phut<=59
    tg.gio += tg.phut/60;
    tg.phut = tg.phut%60;

    //Dua tg.gio ve dang hop le: 0<=tg<=23
    tg.gio = tg.gio%24;

    //Tra ve thoi gian sau khi cong voi n phut
    return tg;
}

istream& operator>>(istream &cin,ThoiGian &t)
{
    char kt;

    do
    {
        cout<<"(h:mm): ";
        cin>>t.gio>>kt>>t.phut;

        if(t.gio<0 || t.gio>23 || t.phut<0 || t.phut>59)
            cout<<"Thoi gian nhap chua dung dang 24 gio, nhap lai.\n";
    }
    while(t.gio<0 || t.gio>23 || t.phut<0 || t.phut>59);

    return cin;
}

ostream& operator<<(ostream &cout,ThoiGian &t)
{
    printf("%d:%02d",t.gio,t.phut);

    return cout;
}


