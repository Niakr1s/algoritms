#ifndef LINK_H
#define LINK_H

#include <iostream>

namespace links {

class Link {
 public:
  Link();
  Link(int left, int right);

  int left() const;
  int right() const;

  inline bool isIn(int item) const { return item == left_ || item == right_; }
  inline bool isSymmetric() const { return left_ == right_; }

  Link reversed() const;

  bool operator==(const Link& rhs) const;

  friend std::istream& operator>>(std::istream& in, Link& link);
  friend std::ostream& operator<<(std::ostream& out, const Link& link);

 private:
  int left_, right_;
};

std::istream& operator>>(std::istream& in, Link& link);
std::ostream& operator<<(std::ostream& out, const Link& link);

}  // namespace links

#endif  // LINK_H
