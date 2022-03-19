#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>

int main() {
    const int N = 52; // Количество вершин в графе
    const int INF = 1000000; // Бесконечность
    int dist[N][N]; // Дистанции в графе
    int e[N]; // Эксцентриситет вершин
    std::set<int> c; // Центр графа
    int rad = INF; // Радиус графа
    int diam; // Диаметр графа

    std::ifstream fin;
    std::ofstream fout;
    fin.open("inputedges.in");
    fout.open("inputedges.out");
    int start, end;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) { dist[i][j] = 100000; }
            else { dist[i][j] = 0; }
        }
    }
    for (int i = 0; i < 194; i++) {
        fin >> start >> end;
        dist[start - 1][end - 1] = 1;
        dist[end - 1][start - 1] = 1;
    }

    // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < N; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Нахождение эксцентриситета
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] != INF) { e[i] = std::max(e[i], dist[i][j]); }         
        }
    }

    // Нахождение диаметра и радиуса
    for (int i = 0; i < N; i++) {
        if (e[i] > 3) { rad = std::min(rad, e[i]); }
        std::cout << e[i] << ' ' << i << '\n';
        diam = std::max(diam, e[i]);
    }

    for (int i = 0; i < N; i++) {
        if (e[i] == rad) {
            c.insert(i);
        }
    }
}
