#include "Graph.hpp"

int main() {
  Graph<int>* graph = new Graph<int>();
  graph->AddVertex(0, 1);
  graph->AddVertex(1, 5);
  const auto ids = graph->GetAllVertexIDs();
  for (const auto& id: ids) {
    std::cout << id << "\n";
  }
  graph->AddEdge(0, 1, 5.5);
  graph->AddEdge(1, 0, 3.3);
  graph->printGraph();
}