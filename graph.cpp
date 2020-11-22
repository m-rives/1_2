#include "graph.h"
#include <fstream>
#include <cstdio>

using namespace std;

// Constructor; node count or directedness cannot be changed later
// Graph is constructed with empty edge set
Graph::Graph (int nodecount, bool directed) 
    : nodecount (nodecount), directed (directed)
{
  adjlist = vector <list <int>> (nodecount);
}

// Getter method
bool Graph::is_directed () const
{
  return directed;
}

// Getter method
int Graph::get_nodecount () const
{
  return nodecount;
}

// Check whether node exists
bool Graph::is_node (int i) const
{
  if (i < 0 || i >= nodecount) return false;
  return true;
}

// Getter method for outgoing edges from a node
list <int> Graph::get_edges (int i) const
{
  if (! is_node (i)) return {};
  return adjlist [i];
}

// Check whether edge exists
bool Graph::is_edge (int i, int j) const
{
  if (! is_node (i)) return false;
  for (auto k : adjlist [i]) {
    if (j == k) return true;
  }
  return false;
}

// Insert (directed or undirected) edge
// Return value indicates whether an edge was inserted successfully
bool Graph::insert_edge (int i, int j)
{
  // Check if both nodes exist; otherwise do nothing
  if (! is_node (i)) return false;
  if (! is_node (j)) return false;
  // Check if edge already exists; if so, do nothing
  if (is_edge (i, j)) return false;
  // Find insertion position in adjacency list of node i
  auto k = adjlist [i].begin (); // Iterator
  while (k != adjlist [i].end () && *k < j) {
    ++k;
  }
  // Insert node j at appropriate position in node i's adjacency list
  adjlist [i].insert (k, j);
  // For a directed graph we're done ...
  if (directed) return true;
  // ... but for an undirected graph repeat the same for node j
  // Find insertion position in adjacency list of node j
  k = adjlist [j].begin (); // Iterator
  while (k != adjlist [j].end () && *k < i) {
    ++k;
  }
  // Insert node i at appropriate position in node j's adjacency list
  adjlist [j].insert (k, i);
  return true;
}

// Delete (directed or undirected) edge
// Return value indicates whether an edge was removed successfully
bool Graph::remove_edge (int i, int j)
{
  // If edge does not exist, do nothing
  if (! is_edge (i, j)) return false;
  // Find edge in outgoing adjacency list of node i
  auto k = adjlist [i].begin ();
  while (*k < j) {
    ++k;
  }
  // Remove edge
  adjlist [i].erase (k);
  // For a directed graph we're done ...
  if (directed) return true;
  // ... but for an undirected graph repeat the same for node j
  // Find edge in outgoing adjacency list of node j
  k = adjlist [j].begin ();
  while (*k < i) {
    ++k;
  }
  // Remove edge
  adjlist [j].erase (k);
  return true;
}

// Print graph to output stream (human-readable)
void printgraph (ostream &os, Graph g)
{
  int n = g.get_nodecount();
  bool directed = g.is_directed();
  // Write number of nodes
  if (directed) os << "Directed"; else os << "Undirected";
  os << " graph with " << n << " nodes; edge set:" << endl;
  // Write edges, one per line;
  // for undirected graphs, only edges {i, j} with i<=j are written
  for (int i=0; i<n; ++i)
    for (int j : g.get_edges (i)) {
      if (directed) os << "  " << i << "->" << j << endl;
      else if (j >= i) os << "  " << i << "--" << j << endl;
    }
  return;
}

// Read directed or undirected graph from file
Graph readgraphfromfile (string infilename, bool directed)
{
  // Open input file; return empty graph if this fails
  ifstream infile (infilename, ios::in);
  if (! infile.good ()) {
    Graph retval (0, directed);
    return retval;
  }
  // Read number of nodes (first line of input file) and initialise graph
  string inputline;
  getline (infile, inputline);
  int n = 0;
  sscanf (inputline.c_str(), "%d", &n);
  Graph retval (n, directed);
  // Read edges, one from each subsequent line of the input file
  do {
    getline (infile, inputline);
    // Stop if input file is exhausted
    if (infile.eof()) break;
    int i, j;
    // Read two node numbers; skip input line if no two numbers are found
    int count = sscanf (inputline.c_str(), "%d %d", &i, &j);
    if (count < 2) continue;
    // Insert edge (includes check of node validity)
    retval.insert_edge (i, j);
  } while (true);
  infile.close();
  return retval;
}

