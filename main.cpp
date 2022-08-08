#include "process.h"
using namespace std;
int main(){
    int select; 
    Date D1,D2;
    cout << "------------ CHUONG TRINH TINH NGAY  -------------"<<endl; 
    cout << " 1. Tinh so ngay."<<endl;
    cout << " 2. Tinh thu."<<endl;
    cout << " 3. In lich thang."<<endl;
    cout << " 0. Thoat."<<endl;
    cout << " Xin moi nhap lua chon :  "<<endl;
    select:
    cin >> select;
    switch (select){
        case 0:
        break;
        case 1:
        select1(D1,D2);
        break;
        case 2:
        select2();
        break;
        case 3:
        select3();
        break;
        default:
        cout<< "Xin moi chon lai :";
        goto select;
    }
    return 0;
}