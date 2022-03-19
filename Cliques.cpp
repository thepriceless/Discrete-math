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
            dist[i][j] = 0;
        }
    }
    for (int i = 0; i < 194; i++) {
        fin >> start >> end;
        dist[start - 1][end - 1] = 1;
        dist[end - 1][start - 1] = 1;
    }

    //clique-4
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    if (dist[a][b] && dist[a][c] && dist[a][d] && dist[b][c] && dist[b][d] && dist[c][d]) {
                        std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
                    }
                }
            }
        }
    }

    //clique-5
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    for (int e = 0; e < N; e++) {
                        if (dist[a][b] && dist[a][c] && dist[a][d] && dist[a][e] && dist[b][c] && dist[b][d] && dist[b][e] && dist[c][d] && dist[c][e] && dist[d][e]) {
                            std::cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << std::endl;
                        }
                    }
                }
            }
        }
    }
}
