class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return node;
    map<int, UndirectedGraphNode*> hist;
    return clone(node, hist);
  }

  UndirectedGraphNode *clone(UndirectedGraphNode *node, map<int, UndirectedGraphNode*>& hist) {
    auto cloned = new UndirectedGraphNode(node->label);
    hist[node->label] = cloned;
    for(auto c : node->neighbors) {
      if (hist.find(c->label) != hist.end()) {
        cloned->neighbors.push_back(hist[c->label]);
      } else {
        cloned->neighbors.push_back(clone(c, hist));
      }
    }
    return cloned;
  }
};
