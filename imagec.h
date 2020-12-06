/* CLASS FOR MULTI-CHANNEL IMAGES */
/* Version: 2019-10-22-PAD
   (c) Martin Welk 2011--2019
       UMIT, Hall/Tyrol, Austria
*/
/* Available for use in the course
     Programming/Algorithms/Data Structures
   at UMIT, Hall/Tyrol 
*/

/* Derived from Version 2019-09-26-CVIS */

// Image class supporting simple pixel access for reading and writing
// values via overloaded () operator such as 
//    myimage (i, j) to access pixel (i, j) of a grey-value image, or
//    myimage (i, j, cc) to access channel cc of pixel (i, j)
//        in a multi-channel (such as colour) image
// Images can be read from and written to pgm/ppm/pnm files 
// (format with binary data blocks, magic numbers P5, P6)
//
// This version provides
//  - assignment operator overload (operator=)
//  - copy constructor
//  - const-awareness (i.e. a const Image can be used)

#ifndef IMAGEC_H
#define IMAGEC_H
#include <string>

using namespace std;

class Image {
  private:
    double *p;  // address of array that stores intensities
    int nx, ny; // image size in x and y directions
    int nc;     // number of (colour) channels
    bool readpnm (const string filename);  
                // read image file of pgm/ppm/pnm type (8-bit binary format)
    double upixel (const int i, const int j, const int cc) const;
    double& upixel (const int i, const int j, const int cc);
                // "fast" pixel access (w/o range check)
                // non-const version returns reference (allows writing)
  public:
    Image (const int nx, const int ny, const int nc=1);  
                // constructor for empty image of size (nx, ny)
                // with nc channels (fully supported: nc=1 and nc=3)
                // initialised with intensity 0 (Black) 
    Image (const string filename);
                // constructor that reads image from file
    ~Image ();  // destructor, frees memory
    bool writepnm (const string filename) const;
                // write image to pgm file (nc==1) or ppm file (nc==3)
                // Other values of nc are not supported
    int sizex () const;
                // getter for image size in x direction
    int sizey () const;
                // getter for image size in y direction
    int noc () const;
                // getter for number of channels
    double pixel(int i, int j, const int cc=0) const;
    double& pixel(int i, int j, const int cc=0);
                // pixel access with range check
                // access to pixels outside the image domain is redirected
                // to the nearest inside pixel
                // non-const version returns reference (allows writing)
    double operator() (const int i, const int j, const int cc=0) const;
    double& operator() (const int i, const int j, const int cc=0);
                // pixel access in "function syntax": e.g.
                // myimage (3, 5) for grey-value images or
                // myimage (3, 5, 1) for green channel in an rgb image
    Image (const Image&);
                // Copy constructor
    Image& operator= (const Image&);
                // Assignment operator
};

#endif // #ifndef IMAGEC_H
