#include "bellman.h"
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

void Grafo::Bellman_Ford(Grafo grafo, int inicial, const char* output) {
    int v = grafo.vertices;
    vector<node*> arestas = grafo.adj;
    int e = arestas.size();
    vector<int> distancias;

    for (int i = 0; i <= v; i++) {
        distancias.push_back(INT_MAX);
    }
    distancias[inicial] = 0;

    for (int i = 1; i < v; i++) {
        for (int j = 1; j <= v; j++) {
            node* vizinhos = arestas[j];
            while(vizinhos != NULL) {
                if (distancias[j] + vizinhos->peso < distancias[vizinhos->destino] && distancias[j] != INT_MAX) {
                    distancias[vizinhos->destino] = distancias[j] + vizinhos->peso;
                }
                vizinhos = vizinhos->next;
            }
        }
    }

    for (int j = 0; j <= v; j++) {
        node* vizinhos = arestas[j];
        while(vizinhos != NULL) {
            int d = vizinhos->destino;
            int w = vizinhos->peso;
            vizinhos = vizinhos->next;
            if (distancias[j] + w < distancias[d] && distancias[j] != INT_MAX) {
                printf("Ciclo negativo detectado!\n");
                break;
            }
        }
    }
    
    if (output) {
        ofstream output_file;
        output_file.open(output);
        for (int i = 1; i < distancias.size(); i++) {
            output_file << i << ":" << distancias[i] << " ";
        }
        output_file.close();
    } else {
        for (int i = 1; i < distancias.size(); i++) {
            cout << i << ":" << distancias[i] << " ";
        }
        cout << endl;
    }
}
