#ifndef FILTER_H
#define FILTER_H

#include <vector>

#include "chain.h"
#include "link.h"

namespace links {

class Filter {
 public:
  Filter();

  bool insert(const Link& link);
  std::vector<Chain> getChains(const Link& link);
  inline const std::vector<Chain>& getChains() const { return chains_; }

 private:
  std::vector<Link> links_;
  std::vector<Chain> chains_;

  bool addLinkToChains();
  bool glueChains();

  bool isInAnyChain(const Link& link) const;
};

}  // namespace links

#endif  // FILTER_H
