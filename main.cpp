//HUE 1.2

//ISBN: Berechnung der Pruefziffer

//Mattia Huber Oberfrank    01417215
//Marc Rives                XXXXXXXX


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


int main()
{
    string isbn;        //declare variables
    string isbn_raw;
    long int res;
    cout << "" << endl;     //obvious cout is obvious
    cout << "This algorithm provides the calculation of the checkdigit for incomplete ISBN-13 codes." << endl;
    cout << "" << endl;
    cout << "The code must contain exactly 12 digits." << endl;
    cout << "" << endl;
    cout << "Please enter the ISBN code without any spaces:" << endl;

    getline(cin,isbn);       //read ISBN from console

    isbn_raw = isbn;                //save original isbn for final output

    cout << "you entered:" << isbn_raw << endl;

    boost::erase_all(isbn, "-");        //erase all dashes

    //res = std::stoi (isbn);
    //cout << "res:" << res << endl;// string to integer

    //istringstream (isbn) >> res;

    stringstream ss;
    ss << isbn;
    ss >> res;
    cout << "res:" << res << endl;



    int size = trunc(log10(res)) + 1 ;

    cout << "length:" << size << endl;



    //int array[12];

}