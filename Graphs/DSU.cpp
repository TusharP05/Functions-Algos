//Disjoint Set Union
//Tushar Parakh
#include<bits/stdc++.h>
using namespace std;

class disjointSet {
    vector<int> parent, rank, size;

public:
    // Constructor to initialize the disjoint set
    disjointSet(int n) {
        rank.resize(n+1, 0); // Resize rank array with n+1 elements, initialized to 0
        parent.resize(n+1); // Resize parent array with n+1 elements
        size.resize(n+1); // Resize size array with n+1 elements
        for(int i = 0; i <= n; i++) {
            parent[i] = i; // Initialize each element in parent array to its index (initially each node is its own parent)
            size[i] = 1; // Initialize size of each set to 1 (initially each set has only one element)
        }
    }

    // Find Ultimate Parent Function
    int findParent(int node) {
        if(parent[node] == node) // If node is its own parent
            return node; // Return node as ultimate parent
        return parent[node] = findParent(parent[node]); // Path compression and recursive call to find ultimate parent
    }
    
    // Union by Rank Function
    void unionByRank(int u, int v) {
        int ult_u = findParent(u); // Find ultimate parent of node u
        int ult_v = findParent(v); // Find ultimate parent of node v
        if(ult_u == ult_v) // If both nodes belong to the same set
            return; // No need to union, already in the same set
        else if(rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u; // Attach smaller ranked set under larger ranked set
        }
        else if(rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v; // Attach smaller ranked set under larger ranked set
        }
        else { // If both sets have the same rank
            parent[ult_u] = ult_v; // Attach one set under the other
            rank[ult_v]++; // Increment rank of the new ultimate parent
        }
    }

    // Union by Size Function
    void unionBySize(int u, int v) {
        int ult_u = findParent(u); // Find ultimate parent of node u
        int ult_v = findParent(v); // Find ultimate parent of node v
        if(ult_u == ult_v) // If both nodes belong to the same set
            return; // No need to union, already in the same set
        else if(size[ult_u] > size[ult_v]) {
            parent[ult_v] = parent[ult_u]; // Attach smaller size set under larger size set
            size[ult_u] += size[ult_v]; // Update size of the larger set
        }
        else {
            parent[ult_u] = ult_v; // Attach smaller size set under larger size set
            size[ult_v] += size[ult_u]; // Update size of the larger set
        }
    }
};

int main() {
    // Example graph: {0, 1}, {1, 2}, {3, 4}, {4, 5}
    disjointSet ds(5); // Create a disjoint set with 6 nodes (0 to 5)

    // Performing unions based on ranks
    ds.unionByRank(0, 1); // Unioning nodes 0 and 1
    ds.unionByRank(1, 2); // Unioning nodes 1 and 2

    // Performing unions based on sizes
    ds.unionBySize(3, 4); // Unioning nodes 3 and 4
    ds.unionBySize(4, 5); // Unioning nodes 4 and 5

    // Finding ultimate parents after unions
    cout << "Ultimate parent of node 0: " << ds.findParent(0) << endl;
    cout << "Ultimate parent of node 2: " << ds.findParent(2) << endl;
    cout << "Ultimate parent of node 3: " << ds.findParent(3) << endl;
    cout << "Ultimate parent of node 5: " << ds.findParent(5) << endl;

    return 0;
}
