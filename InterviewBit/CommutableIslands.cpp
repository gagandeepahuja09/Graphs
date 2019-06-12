/*
Commutable Islands

There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Example : Input

         Number of islands ( n ) = 4
         1 2 1 
         2 3 4
         1 4 3
         4 3 2
         1 3 10

In this example, we have number of islands(n) = 4 . Each row then represents a bridge configuration. In each row first two numbers represent the islands number which are connected by this bridge and the third

integer is the cost associated with this bridge.

In the above example, we can select bridges 1(connecting islands 1 and 2 with cost 1), 3(connecting islands 1 and 4 with cost 3), 4(connecting islands 4 and 3 with cost 2). Thus we will have all islands connected with the minimum possible cost(1+3+2 = 6). In any other case, cost incurred will be more.
×
-->
*/

// Mst
#define pii pair<int, pair<int, int>>

int findCluster(int A, vector<int>& parent) {
    if(parent[A] == -1)
        return A;
    int root = findCluster(parent[A], parent);
    parent[A] = root;
    return root;
}

void unions(int c1, int c2, vector<int>& parent) {
    c1 = findCluster(c1, parent);
    c2 = findCluster(c2, parent);
    parent[c1] = c2;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pii> p;
    for(int i = 0; i < B.size(); i++) {
        p.push_back({ B[i][2], { B[i][0], B[i][1] } });
    }
    sort(p.begin(), p.end());
    vector<int> parent(A + 1, -1);
    int ans = 0;
    for(int i = 0; i < p.size(); i++) {
        int c1 = p[i].second.first, c2 = p[i].second.second;
        c1 = findCluster(c1, parent);
        c2 = findCluster(c2, parent);
        if(c1 == c2)
            continue;
        else {
            ans += p[i].first;
            unions(c1, c2, parent);
        }
    }
    return ans;
}

