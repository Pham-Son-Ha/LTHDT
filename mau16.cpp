/*
Bài 16(lthdtbai16.cpp): Đọc vào bán kính và màu nền (Xanh, Đỏ, Tím, Vàng) của n hình tròn
từ tệp văn bản "hinhtron.txt". Đưa ra màn hình bán kính, màu nền, diện tích và chu vi
của các hình tròn. Tính tổng diện tích và chu vi của n hình tròn.
Đếm số lượng hình tròn có nền màu Xanh, Đỏ, Tím, Vàng.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop hinh tron
class HinhTron
{
    private:
        float r;
        char mauNen[7];

    public:
        void thietLapR(float r);
        void thietLapMauNen(const char *mauNen);
        void hienThi();
        float tinhDT();
        float tinhCV();
        int layMaMau();
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong tep doc vao
    ifstream fin("hinhtron.txt");

    //Khai bao bien
    int n;
    float r,tongDT=0,tongCV=0;
    char mauNen[7];
    int dem[4]={0};

    //Doc so luong hinh tron tu tep
    fin>>n;

    //Tao mang dong n doi tuong hinh tron de chua du lieu cua n hinh tron doc vao tu tep
    HinhTron *ds = new HinhTron[n];

    //Doc du lieu n hinh tron tu tep vao doi tuong hinh tron
    for(int i=0;i<n;i++)
    {
        fin>>r>>mauNen;

        ds[i].thietLapR(r);
        ds[i].thietLapMauNen(mauNen);
    }

    //Tinh tong dt, cv cua n hinh tron; dem hinh tron theo mau
    for(int i=0;i<n;i++)
    {
        tongDT += ds[i].tinhDT();
        tongCV += ds[i].tinhCV();
        dem[ds[i].layMaMau()]++;
    }

    //Dua ra
    cout<<"Danh sach cac hinh tron la:\n";
    for(int i=0;i<n;i++)
    {
        printf("Hinh tron thu %d:\n",i+1);
        ds[i].hienThi();
        cout<<"\n\n";
    }

    printf("\nTong dien tich cua %d hinh tron la: %0.1f",n,tongDT);
    printf("\nTong chu vi cua %d hinh tron la: %0.1f",n,tongCV);
    cout<<"\nSo hinh tron mau Xanh: "<<dem[0];
    cout<<"\nSo hinh tron mau Đỏ: "<<dem[1];
    cout<<"\nSo hinh tron mau Tím: "<<dem[2];
    cout<<"\nSo hinh tron mau Vàng: "<<dem[3];

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTron::thietLapR(float r)
{
    this->r = r;
}

void HinhTron::thietLapMauNen(const char *mauNen)
{
    strcpy(this->mauNen,mauNen);
}

void HinhTron::hienThi()
{
    printf("Hinh tron co:");
    printf("\n\tBan kinh: %0.1f",r);
    printf("\n\tMau nen: %s",mauNen);
    printf("\n\tDien tich: %0.1f",3.14*r*r);
    printf("\n\tChu vi: %0.1f",2*3.14*r);
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

int HinhTron::layMaMau()
{
    if(strcasecmp(mauNen,"Xanh")==0) return 0;
    if(strcasecmp(mauNen,"Đỏ")==0) return 1;
    if(strcasecmp(mauNen,"Tím")==0) return 2;
    if(strcasecmp(mauNen,"Vàng")==0) return 3;
}



