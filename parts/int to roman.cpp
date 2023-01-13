#include <iostream>
#include <unordered_map>
#include <map>
#include <string.h>
using namespace std;


int main()
{
    unordered_map<int, string>NumToRoman;
    NumToRoman = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}};
    
    int Total;
    string RomanAnswer;
    cout << "neter number: ";
    
    cin >> Total;
    
   
    while(true){
        if(Total >= 100){
            cout << NumToRoman[100];
            Total -= 100;
        }else if((Total > 89) && (Total <= 99)){
            cout << NumToRoman[90];
            Total -= 90;
        }else if((Total > 49) && (Total <= 89)){
            cout << NumToRoman[50];
            Total -= 50;
        }else if((Total > 39) && (Total <= 49)){
            cout << NumToRoman[40];
            Total -= 40;
        }else if((Total > 9) && (Total <= 39)){
            cout << NumToRoman[10];
            Total -= 10;
        }else if(Total == 9){
            cout << NumToRoman[9];
            Total -= 9;
        }else if((Total >= 5) && (Total <= 8)){
            cout << NumToRoman[5];
            Total -= 5;
        }else if(Total == 4){
            cout << NumToRoman[4];
            Total -= 4;
        }else if((Total >= 1) && (Total < 4)){
            cout << NumToRoman[1];
            Total -= 1;
        }else if(Total != 0){
            continue;
        }else if(Total == 0){
            break;
        }
    }
    
    
    return 0;