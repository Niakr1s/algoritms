#ifndef GRAPH_H
#define GRAPH_H

#include <map>

#include "node.h"

namespace graphs {

class Graph {
 public:
  Graph();

  int insertNode(NodePtr node);

  NodePtr operator[](int id) const;

  void addConnection(int node1, int node2, double length);

 private:
  std::map<int, NodePtr> nodes_;
};

}  // namespace graphs

#endif  // GRAPH_H
