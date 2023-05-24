#include "kruskal.h"
#include "../utils/utils.h"
#include "main.h"

using namespace std;

int main(int argc, char** argv) {
    Argument args;
    bool param = get_arguments(argc, argv, &args);
    if (param) {
        if (args.help) {
            help_arguments("O algoritmo de Kruskal encontra a AGM do grafo, com complexidade é O(|E| log|V|)", true);
        } else if (args.input) {
            Grafo grafo = read_graph_file(args.input);
            grafo.Kruskal(grafo, args.output, args.solution);
        } else {
            Grafo grafo = read_graph_file("graph.in");
            grafo.Kruskal(grafo, args.output, args.solution);
        }
    }
    return 0;
}