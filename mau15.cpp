/*
Bài 15(lthdtbai15.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Ba cạnh a,b,c có thể nhập vào
từ bàn phím hoặc từ tệp văn bản.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class HinhTG
{
    private:
        float a,b,c;

    public:
        void nhap();
        void docTep(const char *tenTep);
        float tinhDT();
        float tinhCV();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong tam giac
    HinhTG htg;

    //Tuong tac
    htg.nhap();

    printf("Dien tich tam giac la: %0.1f",htg.tinhDT());
    printf("\nChu vi tam giac la: %0.1f",htg.tinhCV());

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhap vao 3 canh cua tam giac: ";
        cin>>a>>b>>c;

        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 so vua nhap khong phai 3 canh tam giac. Nhap lai!\n";
    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

void HinhTG::docTep(const char *tenTep)
{
    //Khai bao tep vao
    ifstream fin(tenTep);

    //Doc vao 3 canh tam giac tu tep
    fin>>a>>b>>c;

    //Kiem tra
    if(a+b<=c || a+c<=b || b+c<=a)
        cout<<"3 so tren tep khong phai 3 canh tam giac.\n";
}

float HinhTG::tinhDT()
{
    //Neu 3 canh ko hop le
    if(a+b<=c || a+c<=b || b+c<=a) return 0;

    //Neu 3 canh hop le
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float HinhTG::tinhCV()
{
    //Neu 3 canh ko hop le
    if(a+b<=c || a+c<=b || b+c<=a) return 0;

    //Neu 3 canh hop le
    return a+b+c;
}


