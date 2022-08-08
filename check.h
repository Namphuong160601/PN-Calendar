#include <iostream>
struct Date{
    int d;
    int m;
    int y;
};
bool CheckDate(Date D)
{
    //kiem tra ngay thang nam >0
    if(D.m>0 && D.y>0 && D.d>0)
    {  //Neu thang 2
        if(D.m==2)
        {   //kiem tra nam nhuan hay ko, neu la nam nhuan thi chia het cho 400 
            if((D.y/4==0))
            {
                if(D.d<=29)
                    return true;
                else
                    return false;
            }
            else
            {
                if(D.d<29)
                    return true;
                else
                    return false;
            }  
        }
        //thang 1,3,5,7,9,11 ko dc lon hon 31 ngay
        if(D.m==1 || D.m==3 || D.m==5 || D.m==7 || D.m==9 || D.m==11)
        {
            if(D.d>31)
                return false;
            else
                return true;
        }  
        //thang 4,6,8,10,12 ko dc lon hon 30 ngay
        if(D.m==4 || D.m==6 || D.m==8 || D.m==10 || D.m==12)
        {
            if(D.d>30)
                return false;
            else
                return true;
        }  
   
    }
    else
        return false;
}
bool CheckYear(Date D){
    if  ((D.y %4==0 && D.y %100 != 0) || (D.y % 400 ==0))
    return true;
    else 
    return false;
}