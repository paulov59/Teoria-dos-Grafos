#ifndef BELLMAN_H
#define BELLMAN_H

#include <bits/stdc++.h> 
using namespace std;

typedef struct Node node;

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
    void Bellman_Ford(Grafo grafo, int inicial, const char* output);
};

void printArr(int dist[], int n);


#endif