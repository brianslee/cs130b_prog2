/**Brian Lee
 * 3620101
 * CMPSC 130B Prog2
 * Minimum Spanning Tree
 * Using Prim's or Kruskel's
 * Algorithm
**/
#include <iostream>
#include <vector>

#include "kruskal.h"
using namespace std;

int main()
{
    int numVert;
    double x, y;
    cout << "How many vertices: ";
    cin >> numVert;
    
    vector<Vertex> vertSet;
    for(int i = 0; i < numVert; ++i)
    {
        cout << "Input vertices: ";
        cin >> x >> y;
        //Create Vertices
        Vertex newVert(x, y, i, false);
        vertSet.push_back(newVert);
    }
    
    //cout << "VertSet Size: " << vertSet.size()  << endl;
    
    int numEdge;
    int first, sec;
    cout << "How many edges: ";
    cin >> numEdge;
    
    vector<Edge> edgeSet;
    if(numEdge == 0)
    {
        //Fully connected graph
        for(int i = 0; i < numVert; ++i)
        {
            for(int j = i + 1; j < numVert; ++j)
            {
                double dist = getDistance(vertSet.at(i), vertSet.at(j));
                Edge tE(i, j, dist);
                edgeSet.push_back(tE);
                //cout << tE.first << " " << tE.second << endl;
            }
        }
    }
    else
    {
        for(int i = 0; i < numEdge; ++i)
        {
            cout << "Input edges: ";
            cin >> first >> sec;
            //Create Edges
            double tempD = getDistance(vertSet.at(first), vertSet.at(sec));
            Edge inputE(first, sec, tempD);
            edgeSet.push_back(inputE);
            //cout << inputE.first << " " << inputE.second << endl;
        }
    }
    
    //Find MST
    vector<Edge> graph = kruskal(edgeSet, vertSet);
    
    //Output MST
    print(graph);
    
    return 0;
}