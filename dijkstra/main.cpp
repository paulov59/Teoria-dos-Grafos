#include "dijkstra.h"
#include "../utils/utils.h"
#include "main.h"

using namespace std;

int main(int argc, char** argv) {
    Argument args;
    bool param = get_arguments(argc, argv, &args);
    if (param) {
        if (args.help) {
            help_arguments("O algoritmo de Dijkstra encontra o menor caminho entre dois vértices de um grafo.", false);
        } else if (args.input) {
            Grafo grafo = read_graph_file(args.input);
            if (args.initial != -1) {
                grafo.Dijkstra(grafo, args.initial, args.output);
            } else {
                grafo.Dijkstra(grafo, 1, args.output);
            }
        } else {
            Grafo grafo = read_graph_file("graph.in");
            if (args.initial != -1) {
                grafo.Dijkstra(grafo, args.initial, args.output);
            } else {
                grafo.Dijkstra(grafo, 1, args.output);
            }
        }
    }
    return 0;
}