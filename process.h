
#include <iomanip>
#include "inoutDate.h"
int CountYear(Date D1, Date D2){
     int SoNamNhuan = 0;
     for (int i = D1.y; i <= D2.y;i++){
        if((D1.y %4==0 && D1.y %100 != 0) || (D1.y % 400 ==0))
        SoNamNhuan +=1;
     }
   return SoNamNhuan; 
}
int TimeDate(Date D1, Date D2)
{
    int d1,m1,y1;
    int m31 =0 ,m30 = 0, m28 = 0, m29 = 0; // so thang co 30 ngay , so thang co 31 ngay
    Date temp;
    int time;
    d1=D2.d-D1.d;
    m1 = D2.m-D1.m;
    if ( m1 !=0){
    for ( int i = D1.m ; i < D2.m ;i++){
    if(i ==1 || i==3 || i==5 || i==7 || i==9 || i==11 )
        m31 += 1;
    if(i==4 || i==6 || i==8 || i==10 || i==12 )
        m30 +=1;
    if(i == 2 && CheckYear(D1) == true )
        m29 = 1;
    if(i == 2 && CheckYear(D1) == false )
        m28 = 1;
    }
    }
    m1 = m31*31 + m30*30 + m28 *28 +m29*29;
    y1=D2.y-D1.y;
    if(y1!=0)
    y1 = CountYear(D1,D2) * 366 + (y1-CountYear(D1,D2)) * 365;
    return  y1 + m1 + d1;
}
void select1(Date D1, Date D2){
    EnterDate(D1);
    EnterDate(D2);
    outDate(D1);
    std::cout<< " => ";
    outDate(D2);
    std::cout<< "   :  " <<TimeDate(D1,D2)<< " Ngay .";
}
void select2(){
    int ngay,thang,nam,b,b1,b2,b3,b4;
    std::string a;
    std::cout << " Moi nhap ngay, thang, nam :";
    std::cin >> ngay>>thang>>nam; 
    if (nam >= 1700 & nam <= 1799)
    b1 = 4;
    if (nam >= 1800 & nam <= 1899)
    b1 = 2;
    if (nam >= 1900 & nam <= 1999)
    b1 = 0;
    if (nam >= 2000 & nam <= 2099)
    b1 = 6;
    if (nam >= 2100 & nam <= 2199)
    b1 = 4;
    if (nam >= 2200 & nam <= 2299)
    b1 = 2;
    if (nam >= 2300 & nam <= 2399)
    b1 = 0;
    if (nam >= 2400 & nam <= 2499)
    b1 = 6;
    if (nam >= 2500 & nam <= 2599)
    b1 = 4;
    if (nam >= 2600 & nam <= 2699)
    b1 = 2;
    b2 = nam %100;
    b3 = b2 / 4 ;
    if ( b2 % 4 == 0){
        switch (thang){
        case 1 : b4 = 6;
        break;
        case 2 : b4 = 2;
        break;
        case 3 : b4 = 3;
        break;
        case 4 : b4 = 6;
        break;
        case 5 : b4 = 1;
        break;
        case 6 : b4 = 4;
        break;
        case 7 : b4 = 6;
        break;
        case 8 : b4 = 2;
        break;
        case 9 : b4 = 5;
        break;
        case 10 : b4 = 0;
        break;
        case 11 : b4 = 3;
        break;
        case 12 : b4 = 5;
        break;
    }}else{
        switch (thang){
        case 1 : b4 = 0;
        break;
        case 2 : b4 = 3;
        break;
        case 3 : b4 = 3;
        break;
        case 4 : b4 = 6;
        break;
        case 5 : b4 = 1;
        break;
        case 6 : b4 = 4;
        break;
        case 7 : b4 = 6;
        break;
        case 8 : b4 = 2;
        break;
        case 9 : b4 = 5;
        break;
        case 10 : b4 = 0;
        break;
        case 11 : b4 = 3;
        break;
        case 12 : b4 = 5;
        break;
    }
};
    b = b1 + b2 + b3 + b4 + ngay;
    b = b % 7 ;
    switch (b){
        case 0 : a = "Chu Nhat";
        break;
        case 1 : a = " Thu Hai";
        break;
        case 2 : a = " Thu Ba";
        break;
        case 3 : a = " Thu Tu";
        break;
        case 4 : a = " Thu Nam";
        break;
        case 5 : a = " Thu Sau";
        break;
        case 6 : a = " Thu Bay";
        break;
}
    std::cout<< " Ngay "<< ngay << " Thang "<<thang << " Nam " <<nam <<" la "<< a;

}
int  select3(){
    int month,year;
    std::cout<< " Nhap thang : ";
    std::cin>> month;
    std::cout<< " Nhap nam : ";
    std::cin>> year;
    if (month< 1 || month>12){
        std::cout<<"Thang khong hop le";
        return 1;
    }
    int top = 31;
    switch (month){
        case 4: case 6: case 9: case 11:
            top = 30;
            break;
        case 2:
            top = ( (year%4==0 && year%100 != 0) || (year % 400 ==0)) ? 29: 28;
            break;
    }

    int d = 1;
    int a = (14-month)/12;
    int y = year - a;
    int m = month+12*a-2;
    int dow = (d+y+y/4-y/100+y/400+(31*m)/12)%7;
    std::cout<< " LICH THANG " << month << " NAM " << year << std::endl;
    std::cout<< " ---------------------------------------"<<std::endl;
    std::cout << "  S  " << "  M  " << "  T  " << "  W  " << "  T  " << "  F  "<< "  S  " << std::endl;
    std::cout << " ======================================= "<<std::endl;
    for(int i=0;i<7;i++)
        if (i<dow)
            std::cout<<"     ";
        else
            std::cout <<" " << std::right <<std::setw(2)<< std::setfill('0') << d++ << "  ";
    std::cout<<std::endl;
     do{
       for(int i=0;i<7;i++)
        if(d<=top)
        std::cout <<" " << std::right <<std::setw(2)<< std::setfill('0') << d++ << "  ";
        std::cout<<std::endl;
    } while(d<=top);
    std::cout << " ======================================= ";
    return 0;
}
