UndirectedGraphNode* clone(UndirectedGraphNode* node, 
map<UndirectedGraphNode*, UndirectedGraphNode*>& mp) {
    if(!node || mp.count(node) > 0)
            return mp[node];
    UndirectedGraphNode *cl = new UndirectedGraphNode(node -> label);
    mp[node] = cl;
    for(int i = 0; i < node -> neighbors.size(); i++) {
        cl -> neighbors.push_back(clone(node -> neighbors[i], mp));
    }
    return cl;
}
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    return clone(node, mp);
}
