#include "dijkstra.h"
#include <bits/stdc++.h>

typedef pair<int, int> Pair;

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

void Grafo::Dijkstra(Grafo grafo, int inicial, const char* output){
    int v = grafo.vertices;
    vector<node*> arestas = grafo.adj; 
    vector<int> vizinhos;
    vector<int> distancias;

    for (int i=0; i <= v; i++) {
        distancias.push_back(INF);
        vizinhos.push_back(-1);
    }

    priority_queue<pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> min_heap;

    distancias[inicial] = 0;
    min_heap.push(make_pair(distancias[inicial], inicial));

    while(min_heap.size() > 0) {
        int u = min_heap.top().second;
        min_heap.pop();
        node *current = arestas[u];
        while(current != NULL) {
            int peso = current->peso;
            int destino = current->destino;

            if(distancias[destino] > distancias[u] + peso) {
                distancias[destino] = distancias[u] + peso;
                vizinhos[destino] = u;
                min_heap.push(make_pair(distancias[destino], destino));
            }
            current = current->next;
        }
    }

    if (output) {
        ofstream output_file;
        output_file.open(output);
        for (int i = 1; i < distancias.size(); i++) {
            if (distancias[i] == INF) {
                output_file << i << ":" << "-1" << " ";
            } else {
                output_file << i << ":" << distancias[i] << " ";
            }
        }
        output_file.close();
    } else {
        for (int i = 1; i < distancias.size(); i++) {
            if (distancias[i] == INF) {
                cout << i << ":" << "-1" << " ";
            } else {
                cout << i << ":" << distancias[i] << " ";
            }
        }
        cout << endl;
    }
    
}