#include "filter.h"

namespace links {

Filter::Filter() {}

bool Filter::insert(const Link& link) {
  if (isInAnyChain(link)) return false;

  links_.push_back(link);

  bool added = addLinkToChains();

  while (glueChains()) {
  }

  if (!added) {
    Chain chain;
    chain.insert(link);
    chains_.push_back(chain);
  }

  return true;
}

std::vector<Chain> Filter::getChains(const Link& link) {
  std::vector<Chain> res;
  for (auto chain : chains_) {
    if (chain.isLinked(link)) res.push_back(chain);
  }
  return res;
}

bool Filter::addLinkToChains() {
  bool updated = false;
  for (auto& link : links_) {
    if (isInAnyChain(link)) continue;
    for (auto& chain : chains_) {
      updated |= chain.insert(link);
    }
  }
  if (updated)
    return updated || addLinkToChains();
  else
    return false;
}

bool Filter::glueChains() {
  if (chains_.size() <= 1) return false;

  std::pair<decltype(std::begin(chains_)), decltype(std::begin(chains_))>
      to_glue{std::begin(chains_), std::begin(chains_)};
  for (auto i = std::begin(chains_); i != std::end(chains_); ++i) {
    for (auto j = i + 1; j != std::end(chains_); ++j) {
      if (i->gluableWith(*j)) {
        to_glue = {i, j};
        goto theEnd;
      }
    }
  }
theEnd:
  if (to_glue.first == std::begin(chains_) &&
      to_glue.second == std::cbegin(chains_))
    return false;

  Chain glued = to_glue.first->glueWith(*to_glue.second);

  chains_.erase(to_glue.second);
  chains_.erase(to_glue.first);

  chains_.push_back(glued);

  return true;
}

bool Filter::isInAnyChain(const Link& link) const {
  for (auto& chain : chains_) {
    if (chain.isLinked(link)) {
      return true;
    }
  }
  return false;
}

}  // namespace links
