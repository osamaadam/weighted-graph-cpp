#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <map>
#include <vector>

template <typename T>
class Graph {
 public:
  Graph() {
  }

  void AddVertex(int vId, T value) {
    vertices[vId] = new Vertex(vId, value);
  };

  void AddEdge(int start_id, int end_id, double cost = 0) {
    vertices[start_id]->AddEdge(end_id, cost);
  };

  const T& GetVertexData(int vertex_id) const {
    return vertices[vertex_id]->data;
  };

  void printGraph() {
    for (const auto& vertex: vertices) {
      for (const auto& edge: vertex.second->GetEdges()) {
        std::cout << vertex.first << ": " << edge->GetDestID() << "\n";
      }
    }
  }

  std::vector<int> GetAllVertexIDs() const {
    std::vector<int> ids;
    for (const auto& vertex: vertices) {
      ids.push_back(vertex.first);
    }
    return ids;
  };

  std::vector<int> DijkstraSPF(int start_id) const;

 private:
  class Vertex;
  std::map<int, Vertex*> vertices;

  class Edge {
   public:
    Edge(int end_id, double cost) : dest_id(end_id), cost(cost) {
    }

    const int GetDestID() {
      return dest_id;
    };

    const double GetCost() {
      return cost;
    };

   private:
    int dest_id;
    double cost;
  };

  class Vertex {
   public:
    Vertex(int id, T value) : id(id), data(value) {
    }

    void AddEdge(int end_id, double cost) {
      Edge* temp_edge = new Edge(end_id, cost);
      edges.push_back(temp_edge);
    }

    const T& GetData() {
      return data;
    };

    const std::vector<Edge*>& GetEdges() {
      return edges;
    };

   private:
    int id;
    T data;
    std::vector<Edge*> edges;
  };
};

#endif