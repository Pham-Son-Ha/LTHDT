/*
Bài 42(lthdtbai42.cpp): Tính diện tích và chu vi các hình: Hình chữ nhật biết 2 cạnh,
hình tam giác biết 3 cạnh, hình tròn biết bán kính. Nhập vào một số hình trong đó
có cả hình chữ nhật, hình tam giác và hình tròn. Đưa ra diện tích
và chu vi các hình đã nhập. Y/c cài đặt đa hình động và lớp trừu tượng; viết 1 hàm
lựa chọn hình, nhập kích thước cho hình và trả về hình đã nhập; viết 1 hàm đưa ra
diện tích và chu vi của một hình truyền vào qua đối số.
*/
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop
class Hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
        virtual float tinhCV()=0;
};

class HinhCN:public Hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

class HinhTG:public Hinh
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

class HinhTR:public Hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao ham thong thuong
Hinh* nhapKT();
void hienTT(Hinh *h);

//===chuong trinh chinh===
int main()
{
    //Khai bao mang con tro lop co so Hinh
    Hinh *dsHinh[50];
    int n=0;
    char traLoi;

    //Nhap hinh
    do
    {
        dsHinh[n++] = nhapKT();

        cout<<"\nCó nhập tiếp không?(c/k): ";
        cin>>traLoi;
    }
    while(traLoi=='c' || traLoi=='C');

    //Dua ra
    cout<<"\nDiện tích và chu vi các hình đã nhập là:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Hình thứ "<<i+1<<" có:";
        hienTT(dsHinh[i]);
        cout<<"\n\n";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
//Cac ham lop hinh chu nhat
void HinhCN::nhap()
{
    cout<<"Nhập vào 2 cạnh hình chữ nhật: ";
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

//Cac ham lop tam giac
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhập vào 3 cạnh của tam giác: ";
        cin>>a>>b>>c;

        if(a+b<=c || a+c<=b || b+c<=a)
            cout<<"3 số đã nhập không phải 3 cạnh tam giác. Nhập lại!\n";

    }
    while(a+b<=c || a+c<=b || b+c<=a);
}

float HinhTG::tinhDT()
{
    float p=(a+b+c)/2;

    return sqrt(p*(p-a)*(p-b)*(p-c));
}

float HinhTG::tinhCV()
{
    return a+b+c;
}

//Cac ham lop hinh tron
void HinhTR::nhap()
{
    cout<<"Nhập vào bán kính hình tròn: ";
    cin>>r;
}

float HinhTR::tinhDT()
{
    return 3.14*r*r;
}

float HinhTR::tinhCV()
{
    return 2*3.14*r;
}

//Cac ham thong thuong
Hinh* nhapKT()
{
    Hinh *h;
    char traLoi;

    //Lay vao lua chon cua nguoi dung
    cout<<"Nhập kích thước cho hình nào?(1-CN,2-TG,3-TR): ";
    cin>>traLoi;

    //Tao doi tuong hinh tuong ung voi lua chon cua nguoi dung
    switch(traLoi)
    {
        case '1':
            h = new HinhCN;
            break;

        case '2':
            h = new HinhTG;
            break;

        case '3':
            h = new HinhTR;
            break;

        default:
            h = new HinhCN;
    }

    //Nhap kich thuoc cho hinh
    h->nhap(); //Da hinh dong

    //Tra ve hinh da nhap
    return h;
}

void hienTT(Hinh *h)
{
    printf("\nDiện tích là: %0.1f",h->tinhDT()); //Da hinh dong
    printf("\nChu vi là: %0.1f",h->tinhCV()); //Da hinh dong
}
