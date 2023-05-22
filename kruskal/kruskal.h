#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <bits/stdc++.h>

using namespace std;

typedef struct edge Edge;
typedef struct Node node;

struct edge {
    int src;
    int destino;
    int peso;
};


struct Node{
    int destino;
    int peso;
    node* next;
};


class Grafo {
    int vertices;
    vector <node*> adj;
public:
    Grafo(int vertice);
    void adcAresta(int vertc1, int vertc2, int peso);
    void Kruskal(Grafo grafo, const char* output, bool solution);
};

#endif