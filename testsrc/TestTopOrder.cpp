// Tester for PA1 TopOrder

#include "TestGraph.hpp"
#include "TopOrder.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);

    Graph<char> g;
    
    if (!buildGraph(g, input)) {
        std::cerr << "Unable to build graph, please check graph format" << std::endl;
        exit(1);
    }

    std::list<char> topOrderList = top_order(g);

    std::cout << "Result of Topological Ordering: [ ";
    for (auto it = topOrderList.begin(); it != topOrderList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
