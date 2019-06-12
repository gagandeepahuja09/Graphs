/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
map<UndirectedGraphNode*, UndirectedGraphNode*> mp; 
 
UndirectedGraphNode *cloneG(UndirectedGraphNode *node) { 
    if(!node || mp.count(node) > 0)
            return mp[node];
    UndirectedGraphNode *clone = new UndirectedGraphNode(node -> label);
    mp[node] = clone;
    for(int i = 0; i < node -> neighbors.size(); i++) {
        clone -> neighbors.push_back(cloneG(node -> neighbors[i]));
    }
    return clone; 
} 

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    mp.clear();
    return cloneG(node);
}

