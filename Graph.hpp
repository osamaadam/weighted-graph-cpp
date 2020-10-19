#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <map>
#include <vector>
#include <limits>
#define INF std::numeric_limits<double>::max()


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
      std::string edges = "";
      const auto& vertexEdges = vertex.second->GetEdges();
      for (auto edgeIndex = 0; edgeIndex < (int)vertexEdges.size(); edgeIndex++) {
        if (edgeIndex == 0)
          edges += std::to_string(vertexEdges[edgeIndex]->GetDestID());
        else
          edges += ", " + std::to_string(vertexEdges[edgeIndex]->GetDestID());
      }
      std::cout << vertex.first << ": " << edges << "\n";
    }
  }

  std::vector<int> GetAllVertexIDs() const {
    std::vector<int> ids;
    for (const auto& vertex: vertices) {
      ids.push_back(vertex.first);
    }
    return ids;
  };


std::map<int, double> DijkstraSPF(int start_id) const
{ 
    // Create a set to store vertices that are being 
    // prerocessed 
    set< pair<double, int> > setds; //weight , id
  
    // Create a map for distances and initialize all 
    // distances as infinite (INF) , the key of the map is the vertex id 
    vector<int> keys ; 
    for(std::map<int,int>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
    keys.push_back(it->first);
    std::cout << "Key: " << it->first << std::endl();
    }
    std::map<int, double> dist;
    for(auto id: keys) {
    dist[id] = INF;
    }
  
    // Insert source itself in Set and initialize its 
    // distance as 0. 
    setds.insert(make_pair(0, start_id)); 
    dist[src] = 0; 
  
    /* Looping till all shortest distance are finalized 
       then setds will become empty */
    while (!setds.empty()) 
    { 
        // The first vertex in Set is the minimum distance 
        // vertex, extract it from set. 
        pair<double, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = tmp.second; 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                /*  If distance of v is not INF then it must be in 
                    our set, so removing it and inserting again 
                    with updated less distance.   
                    Note : We extract only those vertices from Set 
                    for which distance is finalized. So for them,  
                    we would never reach here.  */
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
   
  std::cout<<"Vertex   Distance from Source\n" ; 
  for(std::map<int,int>::iterator it = dist.begin(); it != dist.end(); ++it) {
  printf("%d \t\t %d\n", it->first, it->second); 
}
} 
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