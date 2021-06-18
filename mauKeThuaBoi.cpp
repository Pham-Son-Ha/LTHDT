/*
Thời điểm là một loại ngày tháng và cũng là một loại thời gian nhưng có thêm địa điểm.
Ngày tháng có ngày, tháng, năm. Thời gian có giờ và phút.
Nhập vào một thời điểm, đưa ra thời điểm đó ở dạng Địa điểm, dd/mm/yy - h:mm.
Y/c viết hàm tạo không có đối số và có đối số cho tất cả các lớp.
Ví dụ: Hà Nội, 30/09/19 – 14:27
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai bao lop ngay thang
class NgayThang
{
    private:
        int ngay,thang,nam;

    public:
        NgayThang();
        NgayThang(int ngay,int thang,int nam);
        void nhap();
        void hien();
};

//Khai bao lop thoi gian
class ThoiGian
{
    private:
        int gio,phut;

    public:
        ThoiGian();
        ThoiGian(int gio,int phut);
        void nhap();
        void hien();
};

//Khai bao lop thoi diam
class ThoiDiem:public NgayThang,public ThoiGian
{
    private:
        char diaDiem[31];

    public:
        ThoiDiem();
        ThoiDiem(int ngay,int thang,int nam,int gio,int phut,const char *diaDiem);
        void nhap();
        void hien();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong thoi diem
    ThoiDiem td;

    //Tuong tac    cout<<"Nhap vao mot thoi diem:\b";
    cout<<"Nhap vao mot thoi diem:\n";
    td.nhap();

    cout<<"\nThoi diem da nhap la:\n";
    td.hien();

    cout<<endl;
    return 0;
}

//===dinh nghia ham===
//Ham cua lop ngay thang
NgayThang::NgayThang():ngay(0),thang(0),nam(0)
{

}

NgayThang::NgayThang(int ngay,int thang,int nam):ngay(ngay),thang(thang),nam(nam)
{

}

void NgayThang::nhap()
{
    char kt;

    cout<<"Nhap ngay (dang dd/mm/yyyy): ";
    cin>>ngay>>kt>>thang>>kt>>nam;
}

void NgayThang::hien()
{
    printf("%02d/%02d/%d",ngay,thang,nam);
}

//Ham cua lop thoi gian
ThoiGian::ThoiGian():gio(0),phut(0)
{

}

ThoiGian::ThoiGian(int gio,int phut):gio(gio),phut(phut)
{

}

void ThoiGian::nhap()
{
    char kt;

    cout<<"Nhap thoi gian (dang h:mm): ";
    cin>>gio>>kt>>phut;
}

void ThoiGian::hien()
{
    printf("%d:%02d",gio,phut);
}

//Ham lop thoi diem
ThoiDiem::ThoiDiem():NgayThang(),ThoiGian()
{
    //Khoi tao xau rong cho bien diaDiem
    strcpy(diaDiem,"");
}

ThoiDiem::ThoiDiem(int ngay,int thang,int nam,int gio,int phut,const char *diaDiem):NgayThang(ngay,thang,nam),ThoiGian(gio,phut)
{
    strcpy(this->diaDiem,diaDiem);
}

void ThoiDiem::nhap()
{
    NgayThang::nhap();
    ThoiGian::nhap();
    cout<<"Nhap dia diem: ";
    scanf(" ");cin.get(diaDiem,sizeof(diaDiem));
}

void ThoiDiem::hien()
{
    cout<<diaDiem<<", ";
    NgayThang::hien();
    cout<<" - ";
    ThoiGian::hien();
}

