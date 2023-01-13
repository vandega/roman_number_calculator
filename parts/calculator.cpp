cout << "moqmedeba: ";
    cin >> moqmedeba;
    
    if( moqmedeba == "+"){
        TotalSum += Sum;
    }else if(moqmedeba == "-"){
        TotalSum -= Sum;
    }else if(moqmedeba == "*"){
        TotalSum *= Sum;
    }else if(moqmedeba == "/"){
        TotalSum /= Sum;
    }else if(moqmedeba == "="){
        cout << "Total: " << TotalSum << endl;
    }
    Sum = 0;