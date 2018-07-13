/**Brian Lee
 * 3620101
 * CMPSC 130B Prog2
 * Header file for
 * Kruskal's Algorithm
 **/
#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
    double xCoor;
    double yCoor;
    int set;
    bool inMST;
    
    Vertex(): xCoor(0.0), yCoor(0.0), set(-1), inMST(false){}
    Vertex(double x, double y, int s, bool b): xCoor(x), yCoor(y), set(s), inMST(b){}
};

struct Edge
{
    int first;
    int second;
    double weight;
    
    Edge(): first(0), second(1), weight(0.0){}
    Edge(int f, int s, double w): first(f), second(s), weight(w){}
};

double getDistance(Vertex a, Vertex b);

vector<Edge> kruskal(vector<Edge> graph, vector<Vertex> verts);

void print(vector<Edge> graph);

#endif