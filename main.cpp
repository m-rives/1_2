//HUE 1.2

//ISBN: Berechnung der Pruefziffer

//Mattia Huber Oberfrank    01417215
//Marc Rives                01517985
//David Fürhabter           11831250


#include <string>
#include <vector>
#include <iostream>
#include <ostream>


using namespace std;

int res(vector<int> vecISBN) {

    int i, res = 0, mod;

    for (i = 0; i < 12; i++) {
        res = res + (vecISBN[i] * (i + 1));
    }

    mod = (res % 11);
    //cout << "modulo:" << mod << endl;
    return mod;
}

int length(string isbn) {

    int isbn_length = isbn.length();
    return isbn_length;
}

int intToAscii(int modulo) {

    return '0' + modulo;
}

void add_check(char modu, string isbn_raw) {

    if (isbn_raw.length() == 15) {

        isbn_raw.push_back('-');
    }
    isbn_raw.push_back(modu);
    cout << "ISBN with check digit:" << isbn_raw << endl;
}


int main() {
    string isbn;        //declare variables
    string isbn_raw;

    cout << "" << endl;     //obvious cout is obvious
    cout << "This algorithm provides the calculation of the checkdigit for incomplete ISBN-13 codes." << endl;
    cout << "" << endl;
    cout << "The code must contain exactly 12 digits." << endl;
    cout << "" << endl;
    cout << "Please enter the ISBN code without any spaces:" << endl;

    getline(cin, isbn);       //read ISBN from console

    isbn_raw = isbn;                //save original isbn for final output

    vector<int> vecISBN;
    for (int i = 0; i < isbn.length(); ++i) {
        auto ctmp = isbn.at(i);
        if (std::isdigit(ctmp)) {
            vecISBN.push_back(std::stol(&ctmp));
        }
    }
    int isbn_length = vecISBN.size();

    while ((isbn_length < 12 || isbn_length > 12) ||
           ((isbn[0] != '9' || isbn[1] != '7' || !(isbn[2] == '9' || isbn[2] == '8')))) {     //check all wrong inputs

        cout << "isbn code is wrong size or does not meet the required criteria for the first 3 digits" << endl;
        cout << "Please enter the ISBN code without any spaces:" << endl;

        getline(cin, isbn);       //read ISBN from console
        isbn_raw = isbn;
        isbn_length = length(isbn);

    }

    int modulo = res(vecISBN);                     //calculation of the check digit

    char modu = intToAscii(modulo);             //conversion of check digit to char

    if(modulo == 10){
        modu = 'X';
    }
    add_check(modu, isbn_raw);
}