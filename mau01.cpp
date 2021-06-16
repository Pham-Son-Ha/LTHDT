/*
Bài 01(lthdtbai01.cpp): Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Ba cạnh a,b,c đọc vào
từ tệp văn bản "tamgiac.txt". Đưa kết quả ra màn hình, đồng thời ghi ra tệp văn bản "ketqua-lthdtbai01.txt".
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<math.h>

using namespace std;

//===chuong trinh chinh===
int main()
{
    //Khai bao tep vao, ra
    ifstream fin("tamgiac.txt");
    ofstream fout("ketqua-lthdtbai01.txt");

    //Khai bao bien
    float a,b,c;

    //Doc vao 3 canh tam giac tu tep
    fin>>a>>b>>c;

    //Kiem tra va tinh dt, cv
    if(a+b>c && a+c>b && b+c>a)
    {
        cout<<"Tam giác có 3 cạnh là: ";
        printf("a = %0.1f; b = %0.1f; c = %0.1f",a,b,c);

        //Tinh chu vi
        float cv = a+b+c;

        //Tinh dien tich
        float p = cv/2;
        float dt = sqrt(p*(p-a)*(p-b)*(p-c));

        //Dua ra man hinh
        printf("\nDiện tích tam giác là: %0.1f",dt);
        printf("\nChi vi tam giác là: %0.1f",cv);

        //Ghi ra tep
        fout<<"Tam giác có 3 cạnh là: "<<"a = "<<a<<"; b = "<<b<<"; c = "<<c;
        fout<<"\nDiện tích tam giác là: "<<dt;
        fout<<"\nChu vi tam giác là: "<<cv;
    }
    else
    {
        cout<<"\n3 số trên tệp không phải 3 cạnh tam giác.";

        //Ghi ra tep
        fout<<"\n3 số trên tệp không phải 3 cạnh tam giác.";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
