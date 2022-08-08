#include "check.h"
void EnterDate(Date &D)
{
    do
    {     
        std::cout<<"\nNhap vao ngay thang nam:\n";
        std::cout<<"Nhap ngay: ";
        std::cin>>D.d;
        std::cout<<"Nhap thang: ";
        std::cin>>D.m;
        std::cout<<"Nhap nam: ";
        std::cin>>D.y;
        if(CheckDate(D)==false)
            std::cout<<"\n Ban da nhap sai, moi ban nhap lai: ";
        else
            break;
    }while(true);
}
void outDate(Date D)
{
    std::cout<<" Ngay "<<D.d<<" thang "<<D.m<<" nam "<< D.y;
}