/*
RomanCalculator.cpp
Jul 18, 2016
Mohammed
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <string>
//#include <sstream>

using namespace std;

int digitValue(char);
long int RomToDec(char roman_Number[10]);
void dec2romanstr(int num);

int main()
{
	long int DecNumber1;
	long int DecNumber2;
	long int ReDec;

	char Number1[10];
	scanf("%s",Number1);

    char Number2[10];
    scanf("%s",Number2);

    cout <<"Number1 is "<<  Number1 << endl;
	cout <<"Number2 is "<<  Number2 << endl;

	// convert Roman to decimal
	DecNumber1=RomToDec(Number1);
//	printf("Number1 decimal value is : %ld",DecNumber1); cout << endl;
	DecNumber2=RomToDec(Number2);
//	printf("Number2 decimal value is : %ld",DecNumber2); cout << endl;

	// addition
	ReDec=DecNumber1+DecNumber2;
    cout <<"Number1 + Number2 = ";
	dec2romanstr(ReDec);cout << endl;

	// subtraction
	ReDec=DecNumber1-DecNumber2;
	if((DecNumber1-DecNumber2) <=0)
	{
		cout <<"Roman Numerals cannot express zero or negative numbers." << endl;
	}
	else
	{
	    cout <<"Number1-Number2 = ";
		dec2romanstr(ReDec);cout << endl;
	}
return 0;
}

////////////////////////////////////////
void dec2romanstr(int num){
    int del[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; // Key value in Roman counting
    char * sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    char res[64] = "\0";         //result string
    int i = 0;                   //
    while (num){                 //while input number is not zero
        while (num/del[i]){      //while a number contains the largest key value possible
            strcat(res, sym[i]); //append the symbol for this key value to res string
            num -= del[i];       //subtract the key value from number
        }
        i++;                     //proceed to the next key value
    }
    puts(res);
}

////////////////////////////////////////

///////////////////////////////////////
int digitValue(char c){

    int value=0;

    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1;
    }

    return value;
}
////////////////////////////////////////

///////////////////////////////////////
long int RomToDec(char roman_Number[10]){

	    int i=0;
	    long int number =0;

	    while(roman_Number[i]){

	         if(digitValue(roman_Number[i]) < 0){
	             printf("Invalid roman digit : %c",roman_Number[i]);
	             return 0;
	         }

	         if((strlen(roman_Number) -i) > 2){
	             if(digitValue(roman_Number[i]) < digitValue(roman_Number[i+2])){
	                 printf("Invalid roman number");
	                 return 0;
	             }
	         }

	         if(digitValue(roman_Number[i]) >= digitValue(roman_Number[i+1]))
	             number = number + digitValue(roman_Number[i]);
	         else{
	             number = number + (digitValue(roman_Number[i+1]) - digitValue(roman_Number[i]));
	             i++;
	         }
	         i++;
	    }

    return number;
}
////////////////////////////////////////


