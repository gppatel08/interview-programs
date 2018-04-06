/*
How to create a dynamic 2D array inside a class in C++ ?

  Suppose we want to create a class for Graph. 
  The class stores adjacency matrix representation of the graph. Therefore, our class structure would be something like below.

class Graph 
{
  int V; 
  int adj[V][V];  // This line doesn't work
   
  //Rest of the members
};
 
int main()
{

}
Output :

error: invalid use of non-static data
       member 'Graph::V'.

Even if we make V static, we get error “array bound is not an integer constant”

  C++ doesn’t allow to create an stack allocated array in a class whose size is not constant. 
  So we need to dynamically allocate memory. Below is a simple program to show how to dynamically allocate 2D array in a 
  C++ class using a class for Graph with adjacency matrix representation.
*/

/* C++ program to show how to allocate dynamic 2D array in a class using a Graph example. */
#include<bits/stdc++.h>
using namespace std;
 
// A Class to represent directed graph
class Graph
{
    int V;    // No. of vertices
 
    // adj[u][v] would be true if there is an edge from u to v, else false
    bool **adj;
 
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v)  { adj[u][v] = true; }
    void print();
};
 
/*
A note on call of memset(): 
---------------------------
  memset() is used separately for individual rows. 
  We can’t replace these calls with one call because rows are allocated at different addresses and 
  making a memset call like below would be disastrous.

       // Wrong!! (Rows of matrix at different addresses)
       memset(adj, false, V*V*sizeof(bool));
*/
Graph::Graph(int V)
{
    this->V = V;
 
    // Create a dynamic array of pointers
    adj = new bool* [V];
 
    // Create a row for every pointer
    for (int i=0; i<V; i++)
    {
       // Note : Rows may not be contiguous
       adj[i] = new bool[V];
 
       // Initialize all entries as false to indicate that there are no edges initially
       memset(adj[i], false, V*sizeof(bool));
    }
}
 

// Utility method to print adjacency matrix
void Graph::print()
{
   for (int u=0; u<V; u++)
   {
      for (int v=0; v<V; v++)
         cout << adj[u][v] << " ";
      cout << endl;
   }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    g.print();
 
    return 0;
}

/* OUTPUT:

0 1 1 0 
0 0 1 0 
1 0 0 1 
0 0 0 1

*/
