/*Bài 29(lthdtbai29.cpp): Nhập vào một số nguyên dương, đưa ra số hex tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang hex.
Ngăn xếp sử dụng cấu trúc lưu trữ phân tán.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop ngan xep
class Stack
{
    private:
        struct node
        {
            char infor;
            node *link;
        } *T;

    public:
        Stack(); //hàm tạo
        ~Stack(); //Ham Huy
        void push(char x); //Bo sung 1 phan tu vao ngan xep
        char pop(); //Loai bo phan tu khoi ngan xep
        bool isEmpty(); //Kiem tra ngan xep rong
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong ngan xep
    Stack s;

    //Khai bao bien
    int n,thuong,du;

    cout<<"Nhap vao so nguyen duong he 10: ";
    cin>>n;

    //Chuyen sang he 16
    thuong=n;
    while(thuong)
    {
        du = thuong%16;
        thuong /= 16;

        //Chuyen so du thanh chu so he 16 roi day vao ngan xep
        if(du<10) s.push(du+48);
        else s.push(du+55);
    }

    //Dua ra so hex
    cout<<"So hex cua "<<n<<" la: ";
    while(!s.isEmpty()) cout<<s.pop();

    cout<<endl;
    return 0;
}
//==dinh nghia ham===
Stack::Stack():T(NULL)
{

}

Stack::~Stack()
{
    while(T)
    {
        node *P=T;
        T = T->link;
        delete P;
    }
}

void Stack::push(char x)
{
    //1.Tao nut moi chua x
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao tren nut T
    N->link = T;

    //3.Cho T tro sang nut moi
    T = N;
}

char Stack::pop()
{
    //1.Kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngan xep da rong!";
        return 1;
    }

    //2.Giu lai nut dinh
    node *P = T;
    char tg = T->infor;

    //3.Cho T tro xuong nut ben duoi
    T = T->link;

    //4.Huy nut dinh va tra ve phan tu nut dinh da loai bo
    delete P;
    return tg;
}

bool Stack::isEmpty()
{
    return T==NULL;
}


