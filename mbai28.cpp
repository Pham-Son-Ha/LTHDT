/*
Bài 28(lthdtbai28.cpp): Nhập vào một số nguyên dương, đưa ra số nhị phân tương ứng.
Y/c trong chương trình có sử dụng ngăn xếp để chuyển từ số thập phân sang nhị phân.
Ngăn xếp sử dụng cấu trúc lưu trữ kế tiếp.
*/
#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao lop
class Stack
{
    private:
        enum {size=32};
        int S[size];
        int T;

    public:
        Stack();
        void push(int x);
        int pop();
        bool isEmpty();
};

//===chuong trinh chinh===
int main()
{
    //Tao 1 doi tuong ngan xep
    Stack s;

    //Khai bao bien
    int n,thuong;

    //Nhap
    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;

    //Chuyen he 10 sang he 2
    thuong=n;
    while(thuong)
    {
        s.push(thuong%2);
        thuong/=2;
    }

    printf("So nhi phan cua %d la: ",n);
    while(!s.isEmpty()) cout<<s.pop();

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
Stack::Stack():T(-1)
{

}

void Stack::push(int x)
{
    //1.Kiem tra ngan xep day
    if(T==size-1)
    {
        cout<<"Ngan xep da day!";
        return;
    }

    //2.Tang T len 1 va dua x vao ngan xep tai vi tri T
    S[++T] = x;
}

int Stack::pop()
{
    //1.Kiem tra ngan xep rong
    if(T==-1)
    {
        cout<<"Ngan xep da rong!";
        return 1;
    }

    //2.Tra ve phan tu dinh va giam T di 1
    return S[T--];
}

bool Stack::isEmpty()
{
    return T == -1;
}
