#include "kruskal.h"
#include <bits/stdc++.h>

using namespace std;

Grafo::Grafo(int vertices) {
    this->vertices = vertices;
    for (int i = 0; i <= vertices; i++) {
        this->adj.push_back(NULL);
    }
}

void Grafo::adcAresta(int vertc1, int vertc2, int peso) {
    node* edge = (node*) malloc(sizeof(node));
    edge->destino = vertc2;
    edge->peso = peso;
    edge->next = adj[vertc1];
    adj[vertc1] = edge;
}

void Union(int x, int y, int parent[], int rank[]) {
    if (rank[x] >= rank[y]) {
        parent[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
        return;
    }
    parent[x] = y;
}

int Find(int x, int parent[], int rank[]) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x], parent, rank);
    }
    return parent[x];
}

bool compareEdges(Edge a, Edge b) {
    return (a.peso < b.peso);
}

int peso_total(vector<Edge> MST) {
    int total = 0;
    for (int i = 0; i < MST.size(); i++) {
        total += MST[i].peso;
    }
    return total;
}

vector<Edge> make_edges(vector<node*> g) {
    vector<Edge> edges;
    for (int i = 0; i < g.size(); i++) {
        node* current = g[i];
        while (current != NULL) {
            Edge new_edge;
            new_edge.src = i;
            new_edge.destino = current->destino;
            new_edge.peso = current->peso;
            edges.push_back(new_edge);
            current = current->next;
        }
    }
    return edges;
}

void Grafo::Kruskal(Grafo grafo, const char* output, bool solution) {
    vector<Edge> MST;
    int v = grafo.vertices;
    vector<Edge> sorted_edges = make_edges(grafo.adj);
    sort(sorted_edges.begin(), sorted_edges.end(), compareEdges);
    int rank[v], parent[v];
    for (int i = 0; i <= v; i++){
        parent[i] = i;
        rank[v] = v;
    }

    for (int i = 0; i < sorted_edges.size(); i++) {
        int u = sorted_edges[i].src;
        int v = sorted_edges[i].destino;
        int c1 = Find(u, parent, rank);
        int c2 = Find(v, parent, rank);

        if (c1 != c2) {
            MST.push_back(sorted_edges[i]);
            Union(c1, c2, parent, rank);
        }
    }
    

    if (output) {
        ofstream output_file;
        output_file.open(output);
        if (solution) {
            for (int i = 0; i < MST.size(); i++) {  
                output_file << "(" << MST[i].src << "," << MST[i].destino << ") ";
            }
            output_file << endl;
        } else {
            output_file << peso_total(MST) << endl;
        }
        output_file.close();
    } else {
        if (solution) {
            for (int i = 0; i < MST.size(); i++) {  
                cout << "(" << MST[i].src << "," << MST[i].destino << ") ";
            }
            cout << endl;
        } else {
            cout << peso_total(MST) << endl;
        }
    }
}