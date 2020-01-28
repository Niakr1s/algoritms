#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <optional>
#include <set>
#include <vector>

#include "connection.h"

namespace graphs {

class Graph;

class Node {
 public:
  virtual ~Node() = default;

  Node(const Graph& graph);

  int id() const;

  void insert(const Connection& connection);
  std::vector<ConnectionPath> connectionPaths(int id,
                                              std::set<int> visited = {});

  bool isConnectedDirectly(int id);

  virtual std::string info() const = 0;

  friend std::ostream& operator<<(std::ostream& out, const Node& node);

 private:
  static int counter;
  int id_;
  const Graph& graph_;

  std::vector<Connection> connections_;
};  // namespace graphs

std::ostream& operator<<(std::ostream& out, const Node& node);

using NodePtr = std::shared_ptr<Node>;
using NodeWeakPtr = std::weak_ptr<Node>;

}  // namespace graphs

#endif  // NODE_H
