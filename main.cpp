//HUE 1.1

//Calculation of random birthdays in a given group

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


int main()
{
    int K, n, m;

    cout << "" << endl;
    cout << "Please enter the amount of groups you would like to simulate: " << endl;
    cin >> K;
    cout << "" << endl;
    cout << "Please enter the amount of people you would like to simulate: " << endl;
    cin >> n;
    cout << "" << endl;
    cout << "Please enter the amount of days in a year you would like to simulate (Earth:265; Mars:670; Saturn:24475): " << endl;
    cin >> m;
    cout << "" << endl;

    vector <int> randomNumber(n,0);


    for (int i = 0; i < n; i++) {
        randomNumber[i] = (rand() % m) + 1;
        cout << randomNumber[i] << endl;
    }


    //getline(cin,isbn);


    //boost::erase_all(isbn, "-");        //erase all dashes

}