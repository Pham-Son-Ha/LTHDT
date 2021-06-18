/*
Bài 30(lthdtbai30.cpp): Đọc vào một dãy số nguyên từ tệp văn bản, trong đó có cả số dương và số âm.
Sử dụng hàng đợi lưu trữ kế tiếp theo kiểu quay vòng để tách, đưa ra màn hình đồng thời
ghi ra tệp văn bản dãy các số dương và dãy các số âm.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop hang doi
class Queue
{
    private:
        enum {size=50};
        int Q[size];
        int F,R;

    public:
        Queue();
        void insert(int x);
        int remove();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    //Tao 2 doi tuong hang doi, Q1 chua cac so duong, Q2 chua cac so am
    Queue Q1,Q2;

    //Tao doi tuong tep doc vao va ghi ra
    ifstream fin("daysonguyen.txt");
    ofstream fout("kq-bai30.txt");

    //Khai bao bien
    int x;

    //Doc day so tu tep va dua ra man hinh,
    //dong thoi neu gap khong am thi dua vao Q1, neu gap so am thi dua vao Q2
    cout<<"Day so nguyen ban dau doc duoc tu tep la:\n";
    while(fin>>x)
    {
        cout<<x<<"  ";

        if(x>=0) Q1.insert(x);
        else Q2.insert(x);
    }

    cout<<"\n\nDay cac so duong la:\n";
    fout<<"Day cac so duong la:\n";
    while(!Q1.isEmpty())
    {
        x = Q1.remove();
        cout<<x<<"  ";
        fout<<x<<"  ";
    }

    cout<<"\n\nDay cac so am la:\n";
    fout<<"\n\nDay cac so am la:\n";
    while(!Q2.isEmpty())
    {
        x = Q2.remove();
        cout<<x<<"  ";
        fout<<x<<"  ";
    }

    cout<<"\n\nKet qua tren man hinh cung da ghi ket qua ra tep kq-bai30.txt";

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Queue::Queue():F(-1),R(-1)
{

}

void Queue::insert(int x)
{
    //1.Kiem tra day
    if(F==0 && R==size-1 || R+1==F)
    {
        cout<<"Hang doi da day!";
        return;
    }

    //2.Tang R len 1
    if(R == -1) F = R = 0;
    else if(R == size-1) R = 0;
    else R++;

    //3.Dua x vao hang doi tai vi tri R
    Q[R] = x;
}

int Queue::remove()
{
    //1.Kiem tra rong
    if(F == -1)
    {
        cout<<"Hang doi da rong!";
        return 1;
    }

    //2.Giu lai phan tu dau hang doi (loi truoc)
    int tg = Q[F];

    //3.Tang F len 1
    if(F==R) F = R = -1;
    else if(F==size-1) F = 0;
    else F++;

    //4.Tra ve phan tu dau hang doi da loai bo
    return tg;
}
bool Queue::isEmpty()
{
    return F == -1;
}

