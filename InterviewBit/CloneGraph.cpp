/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp; 
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(!node)
        return node;
    if(mp[node])
        return mp[node];
    UndirectedGraphNode* cl = new UndirectedGraphNode(node -> label);
    mp[node] = cl;
    for(int i = 0; i < node -> neighbors.size(); i++) {
        cl -> neighbors.push_back(cloneGraph(node -> neighbors[i]));
    }
    return cl;
}

