//
//  main.cpp
//  Roman2Decimal
//
//  Created by Vinod Gupta on 2/5/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>

#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> roman_to_int;

void init(){
    roman_to_int['I'] = 1;
    roman_to_int['V'] = 5;
    roman_to_int['X'] = 10;
    roman_to_int['L'] = 50;
    roman_to_int['C'] = 100;
    roman_to_int['D'] = 500;
    roman_to_int['M'] = 1000;
}

int convertRomanToNumber(const char *roman)
{
    
    int i = 0;
    int number = 0;
    int prev_number = 0;
    while (roman[i] != '\0')
    {
        int val = roman_to_int[roman[i]];
        
        number += val;
        
        if (prev_number && val > prev_number)
        {
            number -= (prev_number * 2);
        }
        prev_number = val;
        ++i;
    }
    return number;
}

int main(int argc, const char * argv[])
{
    init();
    string roman;
    while(1)
    {
        cout<<">>";
        getline(cin,roman);
        if(roman == "q" || roman == "Q")
            break;
        cout << convertRomanToNumber(roman.c_str())<<endl;
    }
    return 0;
}