#ifndef GRAPHSEARCH_H
#define GRAPHSEARCH_H
#include <vector>
#include "graph.h"

using namespace std;

// Breadth-first search in a graph, with start node s
// Return results in vectors p (for parent nodes) and d (for distances)
// Write out steps to cout
void breadthfirstsearch (Graph g, int s, vector <int> &p, vector <int> &d);

#endif // #ifndef GRAPHSEARCH_H
