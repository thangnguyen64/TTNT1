#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

void bfs(const unordered_map<char, vector<char>>& graph, char start, char end) {
    unordered_set<char> visited;  
    queue<char> q;  

    visited.insert(start);  
    q.push(start);  

    cout << "BFS traversal: ";

    while (!q.empty()) {
        char node = q.front();  
        q.pop(); 
        cout << node << " ";  

        
        if (node == end) {
            cout << "\nDa den dinh dich " << end << " trong qua trinh tim kiem theo BFS!" << endl;
            return;
        }

        
        for (char neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {  
                visited.insert(neighbor);  
                q.push(neighbor);  
            }
        }
    }

    cout << "\nKhong the den dich " << end << " tu dinh " << start << endl;
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

 
    bfs(graph, start_node, end_node);  

    return 0;
}

