#include "chain.h"

#include <algorithm>
#include <set>

namespace links {

Chain::Chain() {}

bool Chain::insert(const Link &link) {
  if (link.isSymmetric()) {
    return false;
  }
  if (links_.empty()) {
    links_.push_back(link);
    return true;
  }
  if (isLinked(link)) {
    return false;
  }
  if (insertInNonEmpty(link)) {
    return true;
  } else if (insertInNonEmpty(link.reversed())) {
    return true;
  }
  return false;
}

bool Chain::isLinked(const Link &link) const {
  bool left_in = false, right_in = false;
  for (auto &it : links_) {
    if (it.isIn(link.left())) left_in = true;
    if (it.isIn(link.right())) right_in = true;
  }
  return left_in && right_in;
}

bool Chain::gluableWith(const Chain &rhs) const {
  if (links_.empty() || rhs.links_.empty()) return true;

  return (links_.back() == rhs.links_.front()) ||
         (rhs.links_.back() == links_.front()) ||
         (links_.back() == rhs.reversed().links_.front()) ||
         (rhs.reversed().links_.back() == links_.front());
}

Chain Chain::glueWith(const Chain &rhs) const {
  if (!gluableWith(rhs)) throw std::runtime_error("not gluable");

  if (links_.empty()) return rhs;
  if (rhs.links_.empty()) return *this;

  auto glue = [](const Chain &left, const Chain &right) {
    Chain res(left);
    res.links_.pop_back();
    for (auto &link : right.links_) {
      res.links_.push_back(link);
    }
    return res;
  };

  if (links_.back() == rhs.links_.front()) {
    return glue(*this, rhs);
  } else if (links_.front() == rhs.links_.back()) {
    return glue(rhs, *this);
  } else if (Chain rhs_reversed = rhs.reversed();
             links_.back() == rhs_reversed.links_.front()) {
    return glue(*this, rhs_reversed);
  } else {
    return glue(rhs_reversed, *this);
  }
}

Chain Chain::reversed() const {
  Chain res;

  std::deque<Link> reversed_links;
  for (auto &link : links_) {
    reversed_links.push_front(link.reversed());
  }
  res.links_ = std::move(reversed_links);

  return res;
}

const std::deque<Link> &Chain::links() const { return links_; }

bool Chain::insertInNonEmpty(const Link &link) {
  if (links_.front().left() == link.right()) {
    links_.push_front(link);
    return true;
  } else if (links_.back().right() == link.left()) {
    links_.push_back(link);
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &out, const Chain &chain) {
  out << "Chain(";
  for (auto &link : chain.links_) {
    out << link << ",";
  }
  return out << ")";
}

}  // namespace links
