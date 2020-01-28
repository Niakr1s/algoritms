#include "node.h"

#include "graph.h"

namespace graphs {

Node::Node(const Graph &graph) : id_(counter++), graph_(graph) {}

int Node::id() const { return id_; }

void Node::insert(const Connection &connection) {
  connections_.push_back(connection);
}

std::vector<ConnectionPath> Node::connectionPaths(int id,
                                                  std::set<int> visited) {
  std::vector<ConnectionPath> res;

  if (id == id_ || std::find(std::begin(visited), std::end(visited), id_) !=
                       std::end(visited)) {
    return res;
  }

  visited.insert(id_);

  for (auto &connection : connections_) {
    if (connection.connectedId() == id) {
      res.push_back(ConnectionPath{connection});
    } else {
      auto next_node = graph_[connection.connectedId()];
      auto next_connection_paths = next_node->connectionPaths(id, visited);
      for (auto &next_connection_path : next_connection_paths) {
        if (!next_connection_path.connections().empty() &&
            next_connection_path.connections().back().isConnectedWith(id)) {
          ConnectionPath path{connection};
          path.insertConnections(std::begin(next_connection_path.connections()),
                                 std::end(next_connection_path.connections()));
          res.push_back(path);
        }
      }
    }
  }

  return res;
}

bool Node::isConnectedDirectly(int id) {
  for (auto &connection : connections_) {
    if (connection.connectedId() == id) {
      return true;
    }
  }
  return false;
}

int Node::counter = 0;

std::ostream &operator<<(std::ostream &out, const Node &node) {
  return out << node.info();
}

}  // namespace graphs
