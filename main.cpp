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

int main()
{
    int K, n, m = 365, Z = 0;

    cout << "" << endl;
    cout << "Please enter the amount of people you would like to simulate: " << endl;
    cin >> n;
    //cout << "" << endl;
    //cout << "Please enter the amount of days in a year you would like to simulate (Earth:265; Mars:670; Saturn:24475): " << endl;
    //cin >> m;
    cout << "" << endl;
    cout << "Please enter the amount of groups you would like to simulate: " << endl;
    cin >> K;



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
    double mean = ((std::accumulate(amount.begin(), amount.end(), 0.0))/(K*n))*100;
    cout << "On average " << mean << "% of "<< n << " people in the given " << K << " Groups have their Birthdays on the same day." <<endl;
    int sum = (std::accumulate(amount.begin(), amount.end(), 0.0));
    cout << "There were " << sum << " matching cases." <<endl;
}