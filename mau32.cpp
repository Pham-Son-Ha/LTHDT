/*
Bài 32(lthdtbai32.cpp): Cho tệp văn bản chứa dãy số nguyên "lthdtbai32-daysonguyen.txt",
trên tệp không có thông tin về số phần tử của dãy số. Đọc dãy số từ tệp văn bản,
lưu dãy số trong danh sách liên kết đơn theo đúng thứ tự trên tệp. Đưa dãy số trong DSLKD ra màn hình.
Tìm xem trong dãy số có phần tử nào bằng x không. Xóa một phần tử có giá trị bằng x.
*/
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop danh sach lien ket don (DSLKD)
class SList
{
    private:
        struct node
        {
            int infor;
            node *link;
        } *F;

    public:
        SList();
        ~SList();
        void lastInsert(int x);
        void display();
        bool search(int x);
        bool remove(int x);
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong DSLKD
    SList SL;

    //Tao 1 doi tuong tep doc vao
    ifstream fin("lthdtbai32-daysonguyen.txt");

    //Khai bao bien
    int x;

    //Doc day so nguyen tu tep dua vao DSLKD
    while(fin>>x) SL.lastInsert(x);

    cout<<"Day so nguyen trong DSLKD la:\n";
    SL.display();

    //Tim kiem
    cout<<"\n\nNhap vao gia tri x can tim: ";
    cin>>x;

    if(SL.search(x)) cout<<"\n"<<x<<" co trong DSLKD.";
    else cout<<"\n"<<x<<" khong co trong DSLKD.";

    //Xoa x
    if(SL.remove(x))
    {
        cout<<"\n\nDSLKD sau khi xoa "<<x<<" la:\n";
        SL.display();
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
SList::SList():F(NULL)
{

}

SList::~SList()
{
    while(F)
    {
        node *P=F;
        F = F->link;
        delete P;
    }
}

void SList::lastInsert(int x)
{
    //1.Tao nut nho moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao cuoi DSLKD
    if(F==NULL) F = N;
    else
    {
        //Tim den nut cuoi cung last
        node *last=F;
        while(last->link) last = last->link;

        //Noi nutt moi vao sau nut cuoi
        last->link = N;
    }
}

void SList::display()
{
    node *P=F;

    while(P)
    {
        cout<<P->infor<<"  ";
        P = P->link;
    }
}

bool SList::search(int x)
{
    node *P=F;

    //Tim nut co phan tu bang x
    while(P)
        if(P->infor==x) return 1;
        else P = P->link;

    //Khi khong tim thay
    return 0;
}

bool SList::remove(int x)
{
    //Tim nut nut M co phan tu bang x
    node *M=F;

    while(M)
        if(M->infor==x) break;
        else M = M->link;

    //Truong hop khong tim thay
    if(M==NULL) return 0;

    //Truong hop co phan tu bang x
    //1.Ngat ket noi voi nut M
    if(M==F) F = F->link;
    else
    {
        //Tim den nut truoc M
        node *P=F;
        while(P->link != M) P = P->link;

        //Noi nut truoc M voi nut sau M
        P->link = M->link;
    }

    //2.Huy nut M va tra ve 1 (da xoa)
    delete M;

    return 1;
}


