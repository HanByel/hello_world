#include <stdio.h>
#include <iostream>

using namespace std;

int SizeOfDtoB(int Decimal){
    int SizeDtoB=0;
    while(1){
        if(Decimal<=1)  break;
        Decimal = Decimal / 2;
        SizeDtoB++;
    }
    return SizeDtoB;
}

main(){
    int Decimal;
    cin >> Decimal;
    if(typeof(Decimal)!=int){

    }
    int cycle = SizeOfDtoB(Decimal);
    int *Binary = new int[cycle];
    char Binary_String[cycle];

    for(int i=0; i<=cycle;i++){
        Binary[i] = Decimal % 2;
        Decimal = Decimal / 2;
        sprintf(&Binary_String[i],"%d",Binary[i]);
    }
    cout << Binary_String <<endl;
}
