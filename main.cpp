//HUE 2.1

//Calculation of random birthdays in a given group

//Mattia Huber Oberfrank    01417215
//Marc Rives                01517985
//David Fürhabter           11831250

//comments only at the edited parts of the code; graph.cpp


#include <iostream>
#include <string>
#include "graph.h"
#include "user_io.h"

using namespace std;

int main (int argc, char *argv[])
{
  bool directed = userinput_yesno ("Directed graph? ");
  string infilename = userinput ("Input file for graph (ENTER for empty): ");
  Graph g (0, false);
  if (infilename == "") {
    Graph newg (userinput_int ("Node count:"), directed);
    g = newg;
  }
  else {
    g = readgraphfromfile (infilename, directed);
  }
  while (true) {
    printgraph (cout, g);
    string inputline = userinput ("(i)nsert/(r)emove edge/(q)uit?");
    if (inputline.substr (0, 1) == "q") break;
    else if (inputline.substr (0, 1) == "i") {
      cout << "Insert edge" << endl;
      int i = userinput_int ("Enter first node: ");
      int j = userinput_int ("Enter second node:");
      cout << "Edge " << i << "--" << j << " ";
      if (g.insert_edge (i, j)) cout << "inserted";
      else cout << "could not be inserted";
      cout << endl;
    }
    else if (inputline.substr (0, 1) == "r") {
      cout << "Remove edge" << endl;
      int i = userinput_int ("Enter first node: ");
      int j = userinput_int ("Enter second node:");
      cout << "Edge " << i << "--" << j << " ";
      if (g.remove_edge (i, j)) cout << "removed";
      else cout << "could not be removed";
      cout << endl;
    }
    else cout << "Input not recognised" << endl;
  }
  string outfilename = userinput ("Output file for graph: ");
  writegraphtofile (outfilename, g);
  return 0;
}
