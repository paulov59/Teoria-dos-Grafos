#include "../utils/utils.h"

using namespace std;

int main(int argc, char** argv) {
    Argument args;
    bool param = get_arguments(argc, argv, &args);
    if (param) {
        if (args.help) {
            help_arguments("O algoritmo de Prim encontra a AGM (Árvore geradora mínima) do grafo, com complexidade O(|E| log|V|).");
        } 
    }
    return 0;
}