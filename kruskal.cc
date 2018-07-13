/**Brian Lee
 * 3620101
 * CMPSC 130B Prog2
 * Implementation file for
 * Kruskal's Algorithm
 **/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <float.h>
#include "kruskal.h"

using namespace std;

int compareInOrder(const void* a, const void* b)
{
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    
    if(e1->first == e2->first)
    {
        return (e1->second - e2->second);
    }
    else
    {
        return (e1->first - e2->first);
    }
}

int compareWeight(const void* a, const void* b)
{
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return (e1->weight - e2->weight);
}

double getDistance(Vertex a, Vertex b)
{
    double x = (b.xCoor - a.xCoor);
    double y = (b.yCoor - a.yCoor);
    x = x * x;
    y = y * y;
    double d = (x + y);
    return sqrt(d);
}

vector<Edge> kruskal(vector<Edge> graph, vector<Vertex> verts)
{
    //Sort graph by weight
    Edge temp[graph.size()];
    for(int i = 0; i < graph.size(); ++i)
    {
        temp[i] = graph.at(i);
    }
    qsort(temp, graph.size(), sizeof(Edge), compareWeight);
    for(int i = 0; i < graph.size(); ++i)
    {
        graph.at(i) = temp[i];
    }
    
    //Check sorted graph
    /*
    cout << "Sorted Graph: " << endl;
    for(int i = 0; i < graph.size(); ++i)
    {
        cout << graph.at(i).weight << " " << graph.at(i).first << " ";
        cout << graph.at(i).second << endl;
    }*/
    
    //Go through the vector of edges and select the ones with smallest weight
    //That connect the graphs
    vector<Edge> mst;
    int a, b;
    for(int i = 0; i < graph.size(); ++i)
    {
        //For each edge, check if the vertices are a part of a set
        a = graph.at(i).first;
        b = graph.at(i).second;
        if(!verts.at(a).inMST || !verts.at(b).inMST)
        {
            //If not, the edge is in the MST
            mst.push_back(graph.at(i));
            
            //Update vertices' sets and bools
            if(!verts.at(a).inMST && !verts.at(b).inMST)
            {
                //If they are both not in a set, then their set is the smaller number
                verts.at(a).inMST = true;
                verts.at(b).inMST = true;
                verts.at(b).set = verts.at(a).set;
            }
            else if(!verts.at(a).inMST)
            {
                //If only a is not in the set, since a is smaller, the set b is a part of
                //defaults to the value of a
                verts.at(a).inMST = true;
                int tempSet = verts.at(b).set;
                for(int x = 0; x < verts.size(); ++x)
                {
                    if(verts.at(x).set == tempSet)
                    {
                        verts.at(x).set = verts.at(a).set;
                    }
                }
            }
            else
            {
                //Only b is not in the set. Since a is smaller, and already in a set
                //b's set is the set a is a part of.
                verts.at(b).inMST = true;
                verts.at(b).set = verts.at(a).set;
            }
        }
        else
        {
            //If the vertices are in a set, check if it's the same set
            if(verts.at(a).set != verts.at(b).set)
            {
                //If they are not, add the edge
                mst.push_back(graph.at(i));
                
                //Update the set variable for all vetrices in the set of the
                //second vertex
                int temp = verts.at(b).set;
                for(int j = 0; j < verts.size(); ++j)
                {
                    if(verts.at(j).set == temp)
                    {
                        verts.at(j).set = verts.at(a).set;
                    }
                }
            }
        }
        
        //Check if all vertices are in the same set.
        
        int check = verts.at(0).set;
        bool sameSet = true;
        for(int c = 0; c < verts.size(); ++c)
        {
            if(verts.at(c).set != check)
            {
                sameSet = false;
            }
        }
        if(sameSet)
        {
            break;
        }
        
    }
    
    return mst;
}

void print(vector<Edge> graph)
{
    //Sort graph by vertices
    Edge temp[graph.size()];
    for(int i = 0; i < graph.size(); ++i)
    {
        temp[i] = graph.at(i);
    }
    qsort(temp, graph.size(), sizeof(Edge), compareInOrder);
    for(int i = 0; i < graph.size(); ++i)
    {
        graph.at(i) = temp[i];
    }
    
    //cout << "MST: " << endl;
    
    //Print edges
    for(int i = 0; i < graph.size(); ++i)
    {
        cout << graph.at(i).first << " " << graph.at(i).second << endl;
    }
}