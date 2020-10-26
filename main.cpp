//HUE 1.2

//ISBN: Berechnung der Pruefziffer

//Mattia Huber Oberfrank    01417215
//Marc Rives                01517985


#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ostream>
#include <sstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <cmath>
#include <stdlib.h>

using namespace std;

vector<int> calc_check (string isbn){

    int isbn_length = isbn.length();
    vector<int> arr(isbn_length, 0);
    int i;

    for (i = 0; i < 12; i++) {          //conversion from str to vec/arr

        arr[i] = arr[i] * 10 + (isbn[i] - 48);
    }

    return arr;
}

int res (vector<int> arr){

    int i, res = 0,mod;
    for (i = 0; i < 12; i++){
        res = res+(arr[i] * (i+1));
    }

    mod = (res % 11);
    //cout << "modulo:" << mod << endl;
    return mod;
}

int length(string isbn){

    int isbn_length = isbn.length();
    return isbn_length;
}

int intToAscii(int modulo) {

    return '0' + modulo;
}

void add_check (char modu, string isbn_raw){

    if(isbn_raw.length() == 15){

        isbn_raw.push_back('-');
    }
    isbn_raw.push_back(modu);
    cout << "ISBN with check digit:" << isbn_raw << endl;
}



int main()
{
    string isbn;        //declare variables
    string isbn_raw;

    cout << "" << endl;     //obvious cout is obvious
    cout << "This algorithm provides the calculation of the checkdigit for incomplete ISBN-13 codes." << endl;
    cout << "" << endl;
    cout << "The code must contain exactly 12 digits." << endl;
    cout << "" << endl;
    cout << "Please enter the ISBN code without any spaces:" << endl;

   getline(cin,isbn);       //read ISBN from console

   isbn_raw = isbn;                //save original isbn for final output
   boost::erase_all(isbn, "-");        //erase all dashes

   int isbn_length = length(isbn);

   while ((isbn_length < 12 || isbn_length > 12)||((isbn[0] != '9' || isbn[1] != '7' || !(isbn[2] == '9' || isbn[2] == '8')))){     //check all wrong inputs

       cout << "isbn code is wrong size or does not meet the required criteria for the first 3 digits" << endl;
       cout << "Please enter the ISBN code without any spaces:" << endl;

       getline(cin,isbn);       //read ISBN from console
       isbn_raw = isbn;
       boost::erase_all(isbn, "-");        //erase all dashes
       isbn_length = length(isbn);

   }


    vector<int> arr = calc_check(isbn);        //convert string to array

    int modulo = res(arr);                     //calculation of the check digit

    char modu = intToAscii(modulo);             //conversion of check digit to char

    add_check(modu, isbn_raw);              //

}