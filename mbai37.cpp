/*
Bài 37(lthdtbai37.cpp): Tạo lớp đối tượng xâu ký tự có các đặc điểm giống như xâu ký tự
trong Pascal: Có thể khởi tạo đối tượng xâu bằng một hằng xâu; có thể gán hằng xâu hoặc
đối tượng xâu cho đối tượng xâu; có thể dùng phép toán + để nối xâu; có thể dùng các
phép toán so sánh để so sánh xâu; có thể dùng cin và cout để nhập vào và đưa ra đối tượng xâu.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//khai baso lop
class XKT
{
    private:
        enum {SIZE=100};
        char str[SIZE];

    public:
        XKT();//ham tao k doi so
        XKT(const char *s);//ham tao co doi so

        //ham ban
        friend void operator>>(istream &cin, XKT &s);
        friend void operator>>(ostream &cout, XKT &s);
};

//===Chuong trinh chinh===
int main()
{
    cout<<endl;
    return 0;
}
//===Dinh nghia ham===
