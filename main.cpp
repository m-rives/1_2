#include <iostream>
#include <cmath>
#include "user_io.h"
#include "imagec.h"

using namespace std;

// Function to compute Mandelbrot/Julia iteration
// Performs maximum kmax iterations
// Iteration count at which iteration is detected as divergent (if <kmax)
// is computed, and divided by kmax for normalisation
double mandelbrot_value (double cr, double ci, int kmax)
{
  int k = 0;
  double zr = 0.0, zi = 0.0;
  // Iterate until |z|>2 or kmax is reached
  while (zr * zr + zi * zi <= 4.0 && k < kmax) {
    ++k;
    // Compute z*z+c in (zrnew, zinew) and copy back
    double zrnew = zr * zr - zi * zi + cr;
    double zinew = 2.0 * zr * zi + ci;
    zr = zrnew;
    zi = zinew;
  }
  // Scale final number of iterations by kmax; 1.0* avoids integer division!
  return 1.0 * k / kmax;
}

// Function to visualise the Mandelbrot function within a rectangular region;
// generates a (grey-value) Image object with the function values 
// rescaled to the grey-value range [0, 255]
Image mandelbrot_image (int nx,
                        double x0, double x1, double y0, double y1,
                        int k)
{
  // Determine height of output image
  int ny = 1 + (abs ((y1 - y0) / (x1 - x0)) * (nx - 1) + 0.5);
  // Initialise output (grey-value) image
  Image output (nx, ny);
  // Iterate over pixels
  for (int i=0; i<nx; ++i) {
    double x = x0 + (x1 - x0) * i / (nx - 1);
    for (int j=0; j<ny; ++j) {
      double y = y1 - (y1 - y0) * j / (ny - 1);
      // Call Mandelbrot function
      double mval = mandelbrot_value (x, y, k);
      // Output mval as grey-value only if iteration not completed;
      // otherwise leave pixel black (inside Mandelbrot set)
      if (mval < 1.0)
        output (i, j) = 255.0 * mandelbrot_value (x, y, k);
    }
  }
  return output;
}

int main (int argc, char *argv[])
{
  // Greeting
  cout << "Computation of Mandelbrot fractals" << endl;

  // Obtain user input for fractal computation
  int k = userinput_int ("Number of iterations:");

  // Obtain user inputs for plot range and output file name
  double cr_min = userinput_double ("Drawing range start (real part):     ");
  double cr_max = userinput_double ("Drawing range end   (real part):     ");
  double ci_min = userinput_double ("Drawing range start (imaginary part):");
  double ci_max = userinput_double ("Drawing range end   (imaginary part):");
  string outfilename = userinput ("Name of output image:");
  int nx = userinput_int ("Width of output image:");

  // Perform computation
  Image fractalimage = 
      mandelbrot_image (nx, cr_min, cr_max, ci_min, ci_max, k);
  fractalimage.writepnm (outfilename);

  return 0;
}

