#ifndef CHAIN_H
#define CHAIN_H

#include <deque>
#include <iostream>

#include "link.h"

namespace links {

class Chain {
 public:
  Chain();

  bool insert(const Link& link);
  bool isLinked(const Link& link) const;
  inline bool isEmpty() const { return links_.empty(); }

  bool gluableWith(const Chain& rhs) const;
  Chain glueWith(const Chain& rhs) const;
  Chain reversed() const;

  const std::deque<Link>& links() const;

  friend std::ostream& operator<<(std::ostream& out, const Chain& chain);

 private:
  std::deque<Link> links_;

  bool insertInNonEmpty(const Link& link);
};

std::ostream& operator<<(std::ostream& out, const Chain& chain);

}  // namespace links

#endif  // CHAIN_H
