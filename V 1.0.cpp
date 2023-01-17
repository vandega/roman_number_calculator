#include <iostream>
#include <unordered_map>
#include <map>
#include <string.h>
using namespace std;

string InputNumber, Piece, Calc, Past_move, Number_for_roman, Move_for_calculation;
int Sum = 0, TotalSum = 0;

int Roman_to_int(string InputNumber){
    
    unordered_map<string, int>RomanNum;
    RomanNum = {{"I", 1}, {"V", 5},{"X", 10}, {"L", 50}, {"C", 100}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}};
    
    unordered_map<string, int>ErrorNum;
    ErrorNum = {{"IIII", 1000}, {"VVVV", 1001}, {"XXXX", 1002}, {"CCCC", 1003}};
    
    if(Sum > 0){
        Sum = 0;
    }
    
    for(int j = 0; j < InputNumber.size(); j++){
            Piece = InputNumber.substr(j, 4);
            if(ErrorNum[Piece] > 999){
                cout << "declared error (not real roman num) \n try again >>: ";
                cin >> InputNumber;
                Roman_to_int(InputNumber);
            }
        }
        
        
        for(int i = 0; i < InputNumber.size(); i++){
        Piece = InputNumber.substr(i,2);

        if(RomanNum[Piece] == 4 ){
            Sum += 4;
            i++;
        }else if(RomanNum[Piece] == 9){
            Sum+= 9;
            i++;
        }else if(RomanNum[Piece] == 40){
            Sum += 40;
            i++;
        }else if(RomanNum[Piece] == 90){
            Sum += 90;
            i++;
        }else{
            Piece = InputNumber.substr(i,1);
            if(RomanNum[Piece] == 1){
                Sum += 1;
            }else if(RomanNum[Piece] == 5){
                Sum += 5;
            }else if(RomanNum[Piece] == 10){
                Sum += 10;
            }else if(RomanNum[Piece] == 50){
                Sum += 50;
            }else if(RomanNum[Piece] == 100){
                Sum += 100;
            }
        }
    }
    
    if(TotalSum == 0){
        TotalSum = Sum;
        Sum = 0;
    }

    return Sum;   
}

int Calculation(string Calc){

    if( Calc == "+"){
        TotalSum +=Sum;
    }else if(Calc == "-"){
        TotalSum -= Sum;
    }else if(Calc == "*"){
        TotalSum *= Sum;
    }else if(Calc == "/"){
        TotalSum /= Sum;
    }
    
    Past_move = Calc;
    
    return TotalSum;
}

void Int_to_roman(int TotalSum){
    
    unordered_map<int, string>NumToRoman;
    NumToRoman = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}};
    
    int Total;
    string RomanAnswer;
    cout << "answer is: ";
    Total = TotalSum;
    
   
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
    cout << "" <<endl;
}

void Algorithm(){
    
        cout << "enter the number: ";
        cin >> Number_for_roman;
        Roman_to_int(Number_for_roman);
    
    while(Number_for_roman != "exit"){
        // this comment are for controling values
        // cout << "sum -> " << Sum << endl;
        // cout << "Past_move -> " << Past_move << endl;
        // cout << "TotalSum -> " << TotalSum << endl;
        // cout << "---------------------------------" << endl;
        
        
        if(Number_for_roman == "exit"){
            break;
        }
        
        //here
        
        cout << "enter the move: ";
        cin >> Move_for_calculation;
        
        if(Move_for_calculation == "="){
            // Calculation(Past_move);
            Int_to_roman(TotalSum);
            
        }
        
        
        cout << "enter the number: ";
        cin >> Number_for_roman;
        Roman_to_int(Number_for_roman);
        
        Calculation(Move_for_calculation);
        
        
    }
    
}

int main()
{
    Algorithm();
    // Int_to_roman(243);
    
    return 0;
}
