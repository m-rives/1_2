//HUE 3.1

//Mattia Huber Oberfrank    01417215
//Marc Rives                01517985
//David Fuerhapter           11831250

//comments only at the edited parts of the code;

#include <iostream>
#include <cmath>
#include "user_io.h"
#include "imagec.h"
#include <vector>

using namespace std;

// function that calculates the limit cycle of a series and outputs it as pgm file
void iterFuncMap(int it_calc, int it_disp, double r_min, double r_max, double x_min, double x_max, int nx, int ny, string outfilename) {

    // create image object
    Image image(nx, ny);

    // set all pixels to white
    for (int i = 0; i < image.sizex(); ++i)
        for (int j = 0; j < image.sizey(); ++j)
            image(i, j) = 255;

    // calculate all values of parameter r stacked in vector rvec
    vector<double> rvec(image.sizex());
    double a = (r_max - r_min) / (rvec.size() - 1);
    for (int i = 0; i < rvec.size(); ++i)
        rvec[i] = a * i + r_min;

    // loop over image width/iterations
    for(int i = 0; i < image.sizex(); ++i)
    {
        // start value
        double x_k = 0.1;

        // calculate series without output
        for (int k = 1; k < it_calc; ++k)
            x_k = rvec.at(i) * x_k * (1 - x_k);

        // calculate series with parameters for the displayable output
        for (int k = it_calc; k < it_calc + it_disp; ++k)
        {
            x_k = rvec.at(i) * x_k * (1 - x_k);

            // check if current x_k is inside the drawing parameters
            if (x_k >= x_min && x_k <= x_max)
            {
                // calculate percentage of current x_k from x_min to x_max
                double perc = (x_k - x_min) / (x_max - x_min);

                // scale percentage with height
                double scaled = perc * image.sizey();

                // subtract scaled value from image height to mirror horizontally
                int j = image.sizey() - scaled;

                // set concerning pixel to black if inside the parameters
                image(i, j) = 0;
            }
        }
    }

    // write image to output and print if it was successful
    if (image.writepnm(outfilename))
        cout << endl << "Image was written successfully into " << outfilename << endl;
    else
        cout << endl << "Image could not be written successfully." << endl;




}


int main (int argc, char *argv[])
{
    // Greeting
    cout << "Computation of iterated function maps" << endl;

    // Obtain user input:
    // interations for calculation/display
    int it_calc = userinput_int ("Number of iterations before display:");
    int it_disp = userinput_int ("Number of iterations to display:");

    // range of parameter r
    double r_min = userinput_double ("Drawing range start (parameter):     ");
    double r_max = userinput_double ("Drawing range end   (parameter):     ");

    // range of x to display
    double x_min = userinput_double ("Drawing range start (iterated values):");
    double x_max = userinput_double ("Drawing range end   (iterated values):");

    // image size
    int nx = userinput_int ("Width of output image:");
    int ny = userinput_int ("Height of output image:");

    // output file name
    string outfilename = userinput ("Name of output image:");

    /*
    // debug values
    int it_calc = 10000;
    int it_disp = 1000;
    double r_min = 3.53;
    double r_max = 3.9;
    double x_min = 0.87;
    double x_max = 0.9;
    int nx = 800;
    int ny = 800;
    string outfilename = "outtest.pgm";
    */

    // call function that does everything
    iterFuncMap(it_calc,it_disp,r_min,r_max,x_min,x_max,nx,ny,outfilename);

    return 0;
}

