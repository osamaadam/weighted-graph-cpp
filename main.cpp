#include "Graph.hpp"

int main() {
  Graph<int>* graph = new Graph<int>();
  graph->AddVertex(0, 1);
  graph->AddVertex(1, 5);
  graph->AddVertex(2, 22);
  graph->AddVertex(3, 33);
  graph->AddVertex(4, 44);
  graph->AddVertex(5, 55);
  const auto ids = graph->GetAllVertexIDs();
  for (const auto& id: ids) {
    std::cout << id << "\n";
  }
  graph->AddEdge(0, 1, 5.5);
  graph->AddEdge(1, 0, 3.3);
  graph->AddEdge(1, 2, 2);
  graph->AddEdge(1, 5, 56);
  graph->printGraph();
}