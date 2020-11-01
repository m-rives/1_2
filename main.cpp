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
#include <cmath>
#include <numeric>
#include <stdlib.h>

using namespace std;

vector <int> calc (int K, int n, int m){
    int Z = 0;
    vector <int> amount(K,0);
    vector <int> randomNumber(n,0);
    for(int j =0; j < K; j++) {

        for (int i = 0; i < n; i++) {
            randomNumber[i] = (rand() % m) + 1;

        }
        sort(randomNumber.begin() , randomNumber.end());
        for (int c = 0; c < randomNumber.size(); c++){

            while (randomNumber[c] == randomNumber[c+1]){
                Z++;
                c++;

            }

        }
        //cout << Z << endl;
        cout << "For group " << j+1 << " there are " << Z << " matching birthdays." << endl;
        amount.push_back(Z);
        Z = 0;

    }
    for(int h = 0; h < amount.size(); h++ ){

        if (amount[h] != 0){
            amount[h] = 1;
        }
    }
    return amount;
}

int main()
{
    int K, n;
    int m = 365;

            cout << "" << endl;
    cout << "Please enter the amount of people you would like to simulate: " << endl;
    cin >> n;
    cout << "" << endl;
    cout << "Please enter the amount of groups you would like to simulate: " << endl;
    cin >> K;
    vector <int> amount = calc(K,n,m);

    double mean = ((std::accumulate(amount.begin(), amount.end(), 0.0))/(K*n))*100;
    cout << "On average " << mean << "% of "<< n << " people in the given " << K << " Groups have their Birthdays on the same day." <<endl;
    int sum = (std::accumulate(amount.begin(), amount.end(), 0.0));
    cout << "There were " << sum << " matching cases." <<endl;
    cout << "" << endl;

    int KK;
    int mm;
    cout << "Please enter the amount of groups you would like to simulate: " << endl;
    cin >> KK;
    char choice;
    cout << "Enter M for Mars; S for Saturn" << endl;
    cin >> choice;
    if (choice = 'M'){
        mm = 670;
    }
    if (choice = 'S'){
        mm = 22475;
    }
    double ZM = (KK/2);
    double sum2 = 0.0;
    int nn = 5;
    vector <int> randomNumber2(nn,0);
    vector <int> amount2(KK,0);

    while (sum2 < (ZM +1)) {
        nn++;

        //cout << sum2 << endl;
        //cout << ZM << endl;
        //cout << nn << endl;
        vector <int> amount2 = calc (KK,nn,mm);
        sum2 = ((std::accumulate(amount2.begin(), amount2.end(), 0.0)));
        cout << "" << endl;
        cout << nn << " people are neeede to fulfill the 50% requirement." << endl;
    }
}