/*
Bài 21(lthdtbai21.cpp): Tính tổng 2 ma trận nguyên: Cmxn = Amxn + Bmxn. Ma trận Amxn để trong
tệp văn bản 'matran-A.txt', ma trận Bmxn để trong tệp văn bản 'matran-B.txt'.
*/

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao lop ma tran
class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n;

    public:
        MaTran();
        MaTran operator+(const MaTran &mt2);

        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};

//===chuong trinh chinh===
int main()
{
    //Tao 3 doi tuong ma tran A,B,C
    MaTran A,B,C;

    //Tao doi tuong tep doc vao
    ifstream finA("matran-A.txt");
    ifstream finB("matran-B.txt");

    //Doc 2 ma tran A, B tu tep vao doi tuong ma tran
    finA>>A;
    finB>>B;

    //Cong 2 man tran
    C = A + B;

    //Dua ra cac ma tran
    cout<<"Ma tran A:\n"<<A;
    cout<<"\n\nMa tran B:\n"<<B;
    cout<<"\n\nMa tran C = A + B:\n"<<C;

    cout<<endl;
    return 0;
}

//===dinh nghia ham===
MaTran::MaTran():m(0),n(0)
{

}

MaTran MaTran::operator+(const MaTran &mt2)
{
    MaTran tong;

    //Kiem tra kich thuoc 2 ma tran
    if(m==mt2.m && n==mt2.n)
    {
        tong.m = m;
        tong.n = n;

        for(int i=0;i<tong.m;i++)
            for(int j=0;j<tong.n;j++)
                tong.a[i][j]= a[i][j] + mt2.a[i][j];
    }
    else cout<<"\nHai ma tran khong cung kich thuoc, khong cong duoc.";

    return tong;
}

ifstream& operator>>(ifstream &fin,MaTran &mt)
{
    //Doc vao kich thuoc ma tran
    fin>>mt.m>>mt.n;

    //Doc vao cac phan tu cua ma tran
    for(int i=0;i<mt.m;i++)
        for(int j=0;j<mt.n;j++)
            fin>>mt.a[i][j];

    return fin;
}

ostream& operator<<(ostream &cout,MaTran &mt)
{
    for(int i=0;i<mt.m;i++)
    {
        //Dua ra hang i
        for(int j=0;j<mt.n;j++)
            printf("%6d",mt.a[i][j]);

        //Xuong dong
        cout<<endl;
    }

    return cout;
}


