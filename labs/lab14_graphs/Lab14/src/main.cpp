#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>

using namespace std;

int main() {
    // Упр 1
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    vector<pair<int, int>> edges;
    int u, v;
    int maxVertex = 0;

    // Чтениерёбер
    while (inputFile >> u >> v) {
        edges.push_back(make_pair(u, v));
        maxVertex = max(maxVertex, max(u, v));
    }
    inputFile.close();

    int n = maxVertex; // количество вершин

    //Создание матрицы 
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));
    for (size_t i = 0; i < edges.size(); i++) {
        u = edges[i].first;
        v = edges[i].second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // для неориентированного графа
    }
    ofstream matrixFile("matrix.txt");

    // Вывод матрицы с номерами вершин 
    matrixFile << "   ";
    for (int j = 1; j <= n; j++)
        matrixFile << j << " ";
    matrixFile << "\n";

    // Вывод матрицы с номерами вершин слева
    for (int i = 1; i <= n; i++) {
        matrixFile << i << "  ";  // номер вершины
        for (int j = 1; j <= n; j++) {
            matrixFile << adjMatrix[i][j] << " ";
        }
        matrixFile << "\n";
    }
    matrixFile.close();

    cout << "Exercise 1 completed. Adjacency matrix saved to matrix.txt" << endl;

    // Упр2 
    vector<vector<int>> adjList(n + 1); // список смежности 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { // проверяем связь между вершиной и соседями 
            if (adjMatrix[i][j] == 1) {  
                adjList[i].push_back(j); //добавляем j в список
            }
        }
    }

    // Вывод списков смежности 
    ofstream listFile("adjlist.txt");
    for (int i = 1; i <= n; i++) {
        listFile << i << ": ";
        for (size_t j = 0; j < adjList[i].size(); j++) {
            listFile << adjList[i][j] << " ";
        }
        listFile << endl;
    }
    listFile.close();

    cout << "Exercise 2 completed. Adjacency lists saved to adjlist.txt" << endl;

    // Упр3
    ifstream listInput("adjlist.txt");
    if (!listInput.is_open()) {
        cerr << "Error: Cannot open adjlist.txt" << endl;
        return 1;
    }

    vector<pair<int, int>> reconstructedEdges;
    string line;

    while (getline(listInput, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        int vertex;
        char colon;
        iss >> vertex >> colon;

        int neighbor;
        while (iss >> neighbor) {
            // Добавляем ребро только 1раз
            if (vertex < neighbor) {
                reconstructedEdges.push_back(make_pair(vertex, neighbor));
            }
        }
    }
    listInput.close();

    // Вывод восстановленных рёбер в файл
    ofstream edgesFile("edges.txt");
    for (size_t i = 0; i < reconstructedEdges.size(); i++) {
        edgesFile << reconstructedEdges[i].first << " "
            << reconstructedEdges[i].second << endl;
    }
    edgesFile.close();

    cout << "Exercise 3 completed. Edges saved to edges.txt" << endl;
    cout << "All exercises completed successfully!" << endl;

    return 0;
}