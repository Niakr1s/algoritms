#include "connection.h"

namespace graphs {

Connection::Connection(int with, double length)
    : connected_with_(with), length_(length) {}

int Connection::connectedId() const { return connected_with_; }

bool Connection::isConnectedWith(int node) const {
  return connected_with_ == node;
}

double Connection::length() const { return length_; }

ConnectionPath::ConnectionPath() {}

ConnectionPath::ConnectionPath(const Connection &connection)
    : connections_{connection} {}

void ConnectionPath::insertConnection(const Connection &connection) {
  connections_.push_back(connection);
}

double ConnectionPath::distance() const {
  double res = 0;
  for (auto &connection : connections_) {
    res += connection.length();
  }
  return res;
}

const std::vector<Connection> &ConnectionPath::connections() const {
  return connections_;
}

std::ostream &operator<<(std::ostream &out, const ConnectionPath &cp) {
  for (auto &connection : cp.connections_) {
    out << connection.connectedId() << ">";
  }
  return out;
}

}  // namespace graphs
