#include <iostream>
#include <string>
#include "graph.h"
#include "graphsearch.h"
#include "user_io.h"

using namespace std;

int main (int argc, char *argv[])
{
  // Collect input for graph initialisation
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
  cout << endl;
  // Loop for entering modifications of initial graph
  cout << "Modify graph by user input" << endl;
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
  cout << endl;

  // Breadth-first search
  int s = userinput_int ("Start node for depth-first search:");
  vector <int> p, d;
  depthfirstsearch (g, s, p);
  cout << "Result of depth-first search: " << endl;
  cout << "p = (";
  for (int i=0; i<p.size(); ++i) {
    if (i>0) cout << ", ";
    cout << p [i];
  }
  cout << ")" << endl;
  return 0;
}
