#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void dfs(const unordered_map<char, vector<char>>& graph, char node, unordered_set<char>& visited, char end) {
    visited.insert(node);  
    cout << node << " ";  

  
    if (node == end) {
        cout << "\nDa den dinh dich " << end << " trong qua trinh tim kiem theo DFS!" << endl;
        return;
    }

   
    for (char neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {  
            dfs(graph, neighbor, visited, end);  
        }
    }
}


void inputGraph(unordered_map<char, vector<char>>& graph) {
    int n, m;
    cout << "Nhap so luong dinh: ";
    cin >> n;
    
    cout << "Nhap so luong canh: ";
    cin >> m;

  
    cout << "Nhap cac canh (dinh dau, dinh cuoi): \n";
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        graph[u].push_back(v);  
        graph[v].push_back(u); 
    }
}

int main() {
    unordered_map<char, vector<char>> graph;  

  
    inputGraph(graph);

    
    char start_node, end_node;
    cout << "Nhap dinh xuat phat: ";
    cin >> start_node;
    cout << "Nhap dinh ket thuc: ";
    cin >> end_node;

 
    unordered_set<char> visited;

    
    cout << "DFS traversal: ";
    dfs(graph, start_node, visited, end_node);  

    return 0;
}

