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

#include "imagec.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Getter for image size in x direction
int Image::sizex () const {
  return nx;
}

// Getter for image size in y direction
int Image::sizey () const {
  return ny;
}

// Getter for number of channels
int Image::noc () const {
  return nc;
}

// "Fast" pixel access (w/o range check; private)
double Image::upixel (const int i, const int j, const int cc) const {
  return (p [nc*(i+nx*j)+cc]);
}

// "Fast" pixel access (w/o range check; private)
// Non-const version returns reference (allows writing)
double& Image::upixel (const int i, const int j, const int cc) {
  return (p [nc*(i+nx*j)+cc]);
}

// Pixel access with range check
// Access to pixels outside the image domain is redirected
// to the nearest inside pixel
double Image::pixel (int i, int j, const int cc) const {
  if (i<0) i=0;
  if (i>=nx) i=nx-1;
  if (j<0) j=0;
  if (j>=ny) j=ny-1;
  return upixel (i, j, cc);
}

// Pixel access with range check
// Access to pixels outside the image domain is redirected
// to the nearest inside pixel
// Non-const version returns reference (allows writing)
double& Image::pixel (int i, int j, const int cc) {
  if (i<0) i=0;
  if (i>=nx) i=nx-1;
  if (j<0) j=0;
  if (j>=ny) j=ny-1;
  return upixel (i, j, cc);
}

// Pixel access in "function syntax" -- wrapper for pixel ()
double Image::operator() (const int i, const int j, const int cc) const {
  return pixel (i, j, cc);
}

// Pixel access in "function syntax" -- wrapper for pixel ()
// Non-const version returns reference (allows writing)
double& Image::operator() (const int i, const int j, const int cc) {
  return pixel (i, j, cc);
}

// Read image file of pgm/ppm/pnm type (8-bit binary format; private)
bool Image::readpnm (const string filename) {
  ifstream infile (filename.c_str(), ios::in | ios::binary);
  string s;
  stringstream ss (stringstream::in | stringstream::out);
  if (!infile.good()) return false;
  getline (infile, s);
  if (s.size()<2) return false;
  if (s.at(0)!='P' || (s.at(1)!='5' && s.at(1)!='6')) return false;
  if (s.at(1)=='5') nc = 1; else nc = 3;
  do {
    getline (infile, s);
  } while (s.size()>=1 && s.at(0)=='#');
  ss << s;
  ss >> nx >> ny;
  ss.sync();
  ss.clear();
  getline (infile, s);
  int r;
  ss << s;
  ss >> r;
  ss.sync();
  ss.clear();
  if (r>255) return false;
  p = new double [nx*ny*nc];
  for (int j=0; j<ny; ++j)
    for (int i=0; i<nx; ++i) 
      for (int cc=0; cc<nc; ++cc) {
        unsigned char c;
        infile.get ((char&) c);
        upixel (i, j, cc) = (double) c;
      }
  infile.close();
  return true;
}

// Write image to pgm file (nc==1) or ppm file (nc==3)
// Other values of nc are not supported
bool Image::writepnm (const string filename) const {
  ofstream outfile (filename.c_str(), ios::out | ios::binary);
  string s;
  if (!outfile.good()) return false;
  if (nc==1)
    outfile << "P5" << endl;
  else if (nc==3)
    outfile << "P6" << endl;
  outfile << "# writepnm MW 20160105" << endl;
  outfile << nx << " " << ny << endl;
  outfile << "255" << endl;
  for (int j=0; j<ny; ++j)
    for (int i=0; i<nx; ++i) 
      for (int cc=0; cc<nc; ++cc) {
        double v = upixel (i, j, cc);
        unsigned char c;
        if (v < 0.0) c = 0;
        else if (v > 255.0) c = 255;
        else c = (unsigned char) (v + 0.5);
        outfile.put (c);
      }
  outfile.close();
  return true;
}

// Constructor for empty image of size (nx, ny)
// with nc channels (fully supported: nc=1 and nc=3)
// initialised with intensity 0 (Black)
Image::Image (const int nx, const int ny, const int nc) {
  this -> nx = nx;
  this -> ny = ny;
  this -> nc = nc;
  p = new double [nx*ny*nc];
  for (int i=0; i<nx*ny*nc; ++i) p[i] = 0.0;
  return;
}

// Assignment operator overload
Image& Image::operator= (const Image& source) {
  if (this == &source) return *this;
  if (p!=nullptr) delete p;
  p = nullptr;
  nx = source.nx;
  ny = source.ny;
  nc = source.nc;
  p = new double [nx*ny*nc];
  for (int i=0; i<nx*ny*nc; ++i)
    p[i] = source.p[i];
  return *this;
}

// Copy constructor
Image::Image (const Image& source) {
  nx = source.nx;
  ny = source.ny;
  nc = source.nc;
  p = new double [nx*ny*nc];
  for (int i=0; i<nx*ny*nc; ++i)
    p[i] = source.p[i];
  return;
}

// Constructor that reads image from file
Image::Image (const string filename) {
  int l;
  string s;
  l = filename.size();
  if (l >= 4) {
    s = filename.substr (l-4, 4);
    if (s != ".pgm" && s != ".pnm" && s != ".ppm" &&
        s != ".PGM" && s != ".PNM" && s != ".PPM") {
      clog << "Image::Image (filename): Warning: "
           << "Reading into Image object from a "
           << "file without pgm/ppm/pnm ending" << endl;
    }
    if (readpnm (filename)) return;
  }
  nx = 0;
  ny = 0;
  nc = 1;
  p = nullptr;
  return;
}

// Destructor, frees memory
Image::~Image () {
  if (p!=nullptr) delete p;
  p = nullptr;
  nx = 0;
  ny = 0;
  nc = 1;
  return;
}

