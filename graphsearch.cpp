#include <iostream>
#include <vector>
#include <queue>
#include "graphsearch.h"

using namespace std;

void depthfirstsearch(Graph g, int s, vector <int> &p)
{
    cout << "Steps of depth-first search" << endl;
    int n = g.get_nodecount();

    //initialise array p
    p.clear();
    p.insert(p.begin(), n, -1);
    p[s] = s;

    cout << "Initialising: p[" << s << "]=" << s << endl;

    // start recursive depth-first search from start node s
    subtreesearch(g, s, p);

    cout << endl;
    return;
}

// recursive subtree-search used in depth-first search
// algorithm as stated in documents of lecture
void subtreesearch(Graph g, int i, vector <int> &p)
{
    cout << "Start tree search at node " << i << endl;

    // loop over outgoing edges of current node
    for (int j : g.get_edges(i)) {
        cout << "Following edge (" << i << ", " << j << "): ";

        // if current node was not visited before, visit it immediately
        if (p[j] == -1) {
            cout << "Node " << j << " not visited before; ";
            p[j] = i;
            cout << "p[" << j << "]=" << p[j] << endl;
            subtreesearch(g, j, p);
        }
        else
            cout << "Node " << j << " visited before, no change" << endl;
    }

    cout << "Tree search at node " << i << " completed" << endl;

    return;
}

/*
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
*/