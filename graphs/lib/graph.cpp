#include "graph.h"

#include <assert.h>

//#include "connection.h"

namespace graphs {

Graph::Graph() {}

int Graph::insertNode(NodePtr node) {
  nodes_[node->id()] = node;
  return node->id();
}

NodePtr Graph::operator[](int id) const { return nodes_.at(id); }

void Graph::addConnection(int node1, int node2, double length) {
  assert(length >= 0);

  nodes_[node1]->insert(Connection(node2, length));
  nodes_[node2]->insert(Connection(node1, length));
}

}  // namespace graphs
