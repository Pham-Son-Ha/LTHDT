/*
 Tính diện tích các hình: Hình tam giác biết 3 cạnh a,b,c; hình chữ nhật biết 2 cạnh a,b; hình tròn biết bán kính r; hình trụ biết bán kính r và chiều cao :h.
 Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo dài với chiều cao h.
 Nhập vào một số hình trong đó cả cả hình tam giác, chữ nhật, tròn, trụ. Đưa ra diện tích các hình đã nhập.
 Yêu cầu cài đặt đa hình động; viết một hàm thông thường lựa chọn nhập vào kích thước một hình
 và trả về hình đã nhập, một hàm đưa ra diện tích hình truyền vào qua đối số.
*/

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

//Khai bao lop hinh
class Hinh
{
    private:

    public:
        virtual void nhap()=0;
        virtual float tinhDT()=0;
};

//Khai bao lop Hinh TG
class HinhTG:public Hinh
{
    private:
        float a,b,c;

    public:
        void nhap();
        float tinhDT();
};

//Khai bao lop Hinh CN
class HinhCN:public Hinh
{
    private:
        float a,b;

    public:
        void nhap();
        float tinhDT();
};

//Khai bao lop Hinh Tron
class HinhTron:public Hinh
{
    private:
        float r;

    public:
        void nhap();
        float tinhDT();
        float tinhCV();
};

//Khai bao lop Hinh Tru
class HinhTru:public HinhTron
{
    private:
        float h;

    public:
        void nhap();
        float tinhDT();
};

//Khai bao ham thong thuong
Hinh* nhapKT();
void hienTT(Hinh *h);

//===Chuong trinh chinh===
int main()
{
    //Khai bao mang con tro lop co so Hinh
    Hinh *dshinh[100];

    //Khai bao bien
    int n=0;
    char traloi;

    //Nhap
    do
    {
        dshinh[n++] = nhapKT();
        cout<<"\nCo nhap nua khong (c/k)? ";
        cin>>traloi;
    }
    while(traloi=='c'||traloi=='C');

    cout<<"\nDien tich cac hinh la:";
    for(int i=0;i<n;i++)
    {
        printf("\nHinh thu %d co ",i+1);
        hienTT(dshinh[i]);
    }

    cout<<endl;
    return 0;
}

//===Dinh nghia ham===
//Ham thanh vien lop hinh TG
void HinhTG::nhap()
{
    do
    {
        cout<<"Nhap 3 canh tam giac: ";
        cin>>a>>b>>c;
        if(a+b<=c||a+c<=b||b+c<=a)
            cout<<"3 so da nhap khong phai 3 canh tam giac. Nhap lai\n";
    }
    while(a+b<=c||a+c<=b||b+c<=a);
}

float HinhTG::tinhDT()
{
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

//Ham lop hinh CN
void HinhCN::nhap()
{
    cout<<"Nhap vao 2 canh hinh chu nhat: ";
    cin>>a>>b;
}

float HinhCN::tinhDT()
{
    return a*b;
}

// Ham lop Hinh Tron
void HinhTron::nhap()
{
    cout<<"Nhap vao ban kinh r: ";
    cin>>r;
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}
//Ham hinh tru
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

//Ham thong thuong
Hinh* nhapKT()
{
    char traloi;
    Hinh *h;

    cout<<"\nBan nhap hinh nao (1-Chu nhat,2-Tam giac,3-Tron,4-Tru)? ";
    cin>>traloi;

    switch(traloi)
    {
        case '1':
            h = new HinhCN;
            break;
        case '2':
            h = new HinhTG;
            break;
        case '3':
            h = new HinhTron;
            break;
        case '4':
            h = new HinhTru;
            break;
        default:
            h = new HinhCN;
    }

    //Dung da hinh dong de nhap kich thuoc hinh da chon
    h->nhap();

    //Tra ve hinh da nhap kich thuoc
    return h;
}

void hienTT(Hinh *h)
{
    printf("Dien tich la: %0.1f",h->tinhDT()); //Su dung da hinh dong de tinh dien tich
}

