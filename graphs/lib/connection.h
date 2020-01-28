#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <vector>

namespace graphs {

class Connection {
 public:
  Connection(int with, double length);

  int connectedId() const;
  bool isConnectedWith(int node) const;

  double length() const;

 private:
  int connected_with_;
  double length_;
};

class ConnectionPath {
 public:
  ConnectionPath();
  ConnectionPath(const Connection& connection);

  void insertConnection(const Connection& connection);

  template <class Iterator>
  void insertConnections(const Iterator& begin, const Iterator& end) {
    for (auto it = begin; it != end; ++it) {
      connections_.push_back(*it);
    }
  }

  double distance() const;

  const std::vector<Connection>& connections() const;

  friend std::ostream& operator<<(std::ostream& out, const ConnectionPath& cp);

 private:
  std::vector<Connection> connections_;
};

std::ostream& operator<<(std::ostream& out, const ConnectionPath& cp);

}  // namespace graphs

#endif  // CONNECTION_H
