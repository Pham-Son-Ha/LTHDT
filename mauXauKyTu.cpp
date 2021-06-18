/*
Nhập vào một số nguyên dương, đưa ra xâu ký tự số hex tương ứng.
*/
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

//===chuong trinh chinh===
int main()
{
    //Khai bao bien
    unsigned n,thuong,du;
    char soHex[9]=" "; //khoi tao bang xau rong
    char chuSoHex[16][2]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

    //Nhap so nguyen duong
    cout<<"Nhap vao 1 so nguyen duong: ";cin>>n;

    //Chuyen sang he hex
    thuong=n;
    while(thuong)
    {
        du = thuong%16;
        thuong/=16;

        //Chuyen so du thanh chu so hex roi noi vao xau soHex
        strcat(soHex,chuSoHex[du]);
    }

    //Dao xau de duoc so hex dung
    int length=strlen(soHex);
    char tg;

    for(int i=0;i<length/2;i++)
    {
        tg = soHex[i];
        soHex[i] = soHex[length-1-i];
        soHex[length-1-i] = tg;
    }

    //Dua ra kq
    cout<<"So hex cua "<<n<<" la: "<<soHex;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===

