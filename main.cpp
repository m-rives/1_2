//HUE 1.2

//ISBN: Berechnung der Pruefziffer

//Mattia Huber Oberfrank    01417215
//Marc Rives                XXXXXXXX


#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;


int main()
{
    string isbn;        //declare variables
    string isbn_raw;
    int res;
    cout << "" << endl;     //obvious cout is obvious
    cout << "This algorithm provides the calculation of the checkdigit for incomplete ISBN-13 codes." << endl;
    cout << "" << endl;
    cout << "The code must contain exactly 12 digits." << endl;
    cout << "" << endl;
    cout << "Please enter the ISBN code without any spaces:" << endl;

    getline(cin,isbn);       //read ISBN from console

    isbn_raw = isbn;                //save original isbn for final output

    cout << "isbn_raw:" << isbn_raw << endl;
    boost::erase_all(isbn, "-");        //erase all dashes
    cout << "isbn:" << isbn << endl;

    res = std::stoi (isbn);             // string to integer
    cout << "integer res:" << res << endl;

    //cout << "1st pos res" << res << endl;

}