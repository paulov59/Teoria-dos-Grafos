#include "bellman.h"
#include "../utils/utils.h"
#include "main.h"

using namespace std;


int main(int argc, char** argv) {
    Argument args;
    bool param = get_arguments(argc, argv, &args);
    if (param) {
        if (args.help) {
            help_arguments("O Algoritmo de Bellman-Ford é um algoritmo de busca de caminho mínimo em um grafo orientado e ponderado, podendo inclusive ter pesos negativo.", false);
        } else if (args.input) {
            Grafo grafo = read_graph_file(args.input);
            if (args.initial != -1) {
                grafo.Bellman_Ford(grafo, args.initial, args.output);
            } else {
                grafo.Bellman_Ford(grafo, 1, args.output);
            }
        } else {
            Grafo grafo = read_graph_file("graph.in");
            if (args.initial != -1) {
                grafo.Bellman_Ford(grafo, args.initial, args.output);
            } else {
                grafo.Bellman_Ford(grafo, 1, args.output);
            }
        }
    }
    return 0;
}