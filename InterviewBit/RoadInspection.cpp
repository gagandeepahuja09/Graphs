/*
Road Inspection

Martial is a civil engineer. The king of Berland has handed Martial the job of constructing roads in his newly acquired country, Kerland. Kerland has total K unconnected villages numbered [1, 2, ..., K] which are to be connected. Unfortunately, Martial is not very skilled and starts by picking up two random villages and constructing road between them. So, the king has also hired another guy Paul to keep a check on the construction. From time to time, Paul goes for inspection and picks up two random villages to check if they are yet connected.

You have to help Paul to check if the two villages are connected.

Note:

    Roads are bidirectional.
    There can be case where Martial or Paul picks village i and village j such that: i = j or i and j already have a road between them.

Input Format:

Integer A : Number of villages K as mentioned in the problem.

vector<vector<int> > B: Each entry of B contains three numbers: (type, village_1, village_2)
If type is 0: Martial has picked the villages for construction of roads.
If type is 1: Paul is inspecting the villages to check for connectivity.
Entries are in chronological order

Output Format: A vector of answers to inspections. Whenever the villages are inspected, push 1 if they are connected and 0 otherwise.

Constraints: 1 <= K <= 1000000 1 <= Number of constructions + Number of inspections <= 100000

Example:

Sample Input
A = 4
B = [[0, 1, 2], [0,2,3], [1,1,3], [0,3,4], [0,4,5], [1,1,6]]

Sample Output: 
[1, 0]
*/

int findCluster(int u, vector<int>& parent) {
    if(parent[u] == -1)
        return u;
    int root = findCluster(parent[u], parent);
    parent[u] = root;
    return root;
}

void dunion(int u, int v, vector<int>& parent) {
    u = findCluster(u, parent);
    v = findCluster(v, parent);
    parent[v] = u;
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> ret;
    vector<int> parent(1000005, -1);
    for(int i = 0; i < B.size(); i++) {
        if(B[i][0] == 0) {
            int u = B[i][1], v = B[i][2];
            int x = findCluster(u, parent);
            int y = findCluster(v, parent);
            if(y != x)
                dunion(u, v, parent);
        }
        else {
            int u = B[i][1], v = B[i][2];
            u = findCluster(u, parent);
            v = findCluster(v, parent);
            if(u == v)
                ret.push_back(1);
            else
                ret.push_back(0);
        }
    }
    return ret;
}

