/*
Tính tổng hai số phức. Chong toan tu +. Viet 3 ham tao va 1 ham huy.
- Ham tao khong doi so khoi tao a, b bang 0
- Ham tao 1 doi so khoi tao a bang doi so
- Ham tao 2 doi so khoi tao a, b bang doi so tuong ung
- Ham huy co than ham rong
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop so phuc
class SoPhuc
{
    private:
        float a,b;

    public:
        SoPhuc(); //Ham tao khong doi so
        SoPhuc(float x); //Ham tao 1 doi so
        SoPhuc(float x,float y); //Ham tao 2 doi so
        ~SoPhuc(); //Ham huy
        SoPhuc operator+(const SoPhuc &p2);

        //Ham ban
        friend istream& operator>>(istream &cin,SoPhuc &p);
        friend ostream& operator<<(ostream &cout,SoPhuc &p);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong so phuc
    SoPhuc p1(2),p2(7,-5),s;
    /*
    //Nhap vao 2 so phuc
    cout<<"Nhap so phuc p1:\n";
    cin>>p1; //Uoc gi co the dung cin>>p1;

    cout<<"Nhap so phuc p2:\n";
    cin>>p2; //Uoc gi co ther dung cin>>p2;

    //Tinh tong
    s = p1 + p2;
    */
    //Dua ra
    cout<<"p1 = "<<p1; //Uoc gi co the dung cout<<p1;
    cout<<"\np2 = "<<p2;
    cout<<"\np1 + p2 = "<<s;


    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SoPhuc::SoPhuc():a(0),b(0)
{
    cout<<"\nHam tao khong doi so da thuc hien.";
}

SoPhuc::SoPhuc(float x):a(x),b(0)
{
    cout<<"\nHam tao mot doi so da thuc hien.";
}

SoPhuc::SoPhuc(float x,float y):a(x),b(y)
{
    cout<<"\nHam tao hai doi so da thuc hien.";
}

SoPhuc::~SoPhuc()
{
    cout<<"\nHam huy da thuc hien.";
}

SoPhuc SoPhuc::operator+(const SoPhuc &p2)
{
    SoPhuc tong;

    tong.a = a + p2.a;
    tong.b = b + p2.b;

    return tong;
}

//Ham ban, ham thong thuong, khong nam trong doi tuong
istream& operator>>(istream &cin,SoPhuc &p)
{
    cout<<"Nhap vao phan thuc: "; cin>>p.a;
    cout<<"Nhap vao phan ao: "; cin>>p.b;

    return cin;
}

ostream& operator<<(ostream &cout,SoPhuc &p)
{
    if(p.b>=0) cout<<p.a<<" + j"<<p.b;
    else cout<<p.a<<" - j"<<-p.b;

    return cout;
}

