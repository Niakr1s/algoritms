#include "link.h"

namespace links {

Link::Link() {}

Link::Link(int left, int right) : left_(left), right_(right) {}

int Link::left() const { return left_; }

int Link::right() const { return right_; }

Link Link::reversed() const { return Link(right_, left_); }

bool Link::operator==(const Link &rhs) const {
  return left_ == rhs.left_ && right_ == rhs.right_;
}

std::istream &operator>>(std::istream &in, Link &link) {
  return in >> link.left_ >> link.right_;
}

std::ostream &operator<<(std::ostream &out, const Link &link) {
  return out << "Link(" << link.left_ << "," << link.right_ << ")";
}

}  // namespace links
