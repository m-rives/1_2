#include <iostream>
#include <vector>
#include <queue>
#include "graphsearch.h"

using namespace std;

// Breadth-first search in a graph, with start node s
// Return results in vectors p (for parent nodes) and d (for distances)
// Write out steps to cout
void breadthfirstsearch (Graph g, int s, vector <int> &p, vector <int> &d)
{
  cout << "Steps of depth-first search" << endl;
  int n = g.get_nodecount ();
  // Initialise arrays p and d, and FIFO queue for nodes to be processed
  p.clear (); p.insert (p.begin(), n, -1);
  d.clear (); d.insert (d.begin(), n, -1);
  queue <int> q;
  p[s] = s;
  d[s] = 0;
  q.push (s);
  cout << "Initialising: d[" << s << "]=0, p[" << s << "]=" << s << endl;
  // Main loop
  int i = q.front();
  while (!q.empty()) {

    cout << "Processing node " << i << " from queue" << endl;
    // Loop over outgoing edges of current node
    for (int j : g.get_edges (i)) {
      cout << "Following edge (" << i << ", " << j << "): ";
      if (p[j] == -1) {
        cout << "Node " << j << " not visited before; ";
        d[j] = d[i] + 1;
        p[j] = i;
        q.push (j);
        cout << "d[" << j << "]=" << d[j] << ", "
             << "p[" << j << "]=" << p[j] << ", "
             << "appending node " << j << " to queue" << endl;
            i++;
      }
      else {
        cout << "Node " << j << " visited before, no change" << endl;
      }
    }
    q.pop ();
  }
  cout << endl;
  return;
}

