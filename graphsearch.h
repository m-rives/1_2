#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H
#include <vector>
#include "graph.h"

using namespace std;

// Breadth-first search in a graph, with start node s
// Return results in vectors p (for parent nodes) and d (for distances)
// Write out steps to cout
void breadthfirstsearch (Graph g, int s, vector <int> &p, vector <int> &d);

void depthfirstsearch(Graph g, int s, vector <int> &p);

// recursive subtree-search used in depth-first search
void subsearch(Graph g, int i, vector <int> &p);
#endif // #ifndef GRAPHSEARCH_H
