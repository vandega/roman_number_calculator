#include <iostream>
#include <unordered_map>
#include <map>
#include <string.h>
using namespace std; // ar sheexoo arr asheexoo


int main()
{
    unordered_map<string, int>RomanNum;
    RomanNum = {{"I", 1}, {"V", 5},{"X", 10}, {"L", 50}, {"C", 100}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}};
    

    
    string InputNumber, piece;
    int Sum, i, lenght;
    
    // cout << "enter number:  ";
    // cin >> InputNumber;
    
    InputNumber = "CXLIX";
    Sum = 0;

    
    for(int i=0; i < InputNumber.size(); i++){
        piece = InputNumber.substr(i,2);
        // cout << piece << endl;
        if(RomanNum[piece] == 4 ){
            Sum += 4;
            i++;
        }else if(RomanNum[piece] == 9){
            Sum+= 9;
            i++;
        }else if(RomanNum[piece] == 40){
            Sum += 40;
            i++;
        }else if(RomanNum[piece] == 90){
            Sum += 90;
            i++;
        }else{
            piece = InputNumber.substr(i,1);
            if(RomanNum[piece] == 1){
                Sum += 1;
            }else if(RomanNum[piece] == 5){
                Sum += 5;
            }else if(RomanNum[piece] == 10){
                Sum += 10;
            }else if(RomanNum[piece] == 50){
                Sum += 50;
            }else if(RomanNum[piece] == 100){
                Sum += 100;
            }
        }
    }
    
    cout << Sum;
    
    
    
    return 0;
}

