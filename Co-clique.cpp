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

    //co-clique

    //below is a code for generating a code for the solution much more lower :)

    {/*std::vector<std::string> qwe = { "a", "b", "c", "d","e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o" };
    for (int i = 1; i < 13; i++) {
        std::cout << "for(int " << qwe[i] << " = " << qwe[i - 1] << " + 1; " << qwe[i] << " < N; " << qwe[i] << "++) {\n";
        std::cout << "\t if (" << qwe[i] << " != 10 && " << qwe[i] << " != 14 && " << qwe[i] << " != 22 && " << qwe[i] << " != 23 && " << qwe[i] << " != 24 && " << qwe[i] << " != 32 && " << qwe[i] << " != 39 && " << qwe[i] << " != 42 && " << qwe[i] << " != 12 && " << qwe[i] << " != 15 && " << qwe[i] << " != 41 && " << qwe[i] << " != 46 && " << qwe[i] << " != 47 && " << qwe[i] << " != 18 && " << qwe[i] << " != 19 && " << qwe[i] << " != 25 && " << qwe[i] << " != 37 && " << qwe[i] << " != 26 && " << qwe[i] << " != 51) {" << std::endl;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = i + 1; j < 13; j++) { std::cout << "dist[" << qwe[i] << "][" << qwe[j] << "] + "; }
    }*/
    }

    for (int a = 0; a < N; a++) {
        if (a != 10 && a != 14 && a != 22 && a != 23 && a != 24 && a != 32 && a != 39 && a != 42 && a != 12 && a != 15 && a != 41 && a != 46 && a != 47 && a != 18 && a != 19 && a != 25 && a != 26 && a != 37 && a != 51) {
            for (int b = a + 1; b < N; b++) {
                if (b != 10 && b != 14 && b != 22 && b != 23 && b != 24 && b != 32 && b != 39 && b != 42 && b != 12 && b != 15 && b != 41 && b != 46 && b != 47 && b != 18 && b != 19 && b != 25 && b != 37 && b != 26 && b != 51) {
                    for (int c = b + 1; c < N; c++) {
                        if (c != 10 && c != 14 && c != 22 && c != 23 && c != 24 && c != 32 && c != 39 && c != 42 && c != 12 && c != 15 && c != 41 && c != 46 && c != 47 && c != 18 && c != 19 && c != 25 && c != 37 && c != 26 && c != 51) {
                            for (int d = c + 1; d < N; d++) {
                                if (d != 10 && d != 14 && d != 22 && d != 23 && d != 24 && d != 32 && d != 39 && d != 42 && d != 12 && d != 15 && d != 41 && d != 46 && d != 47 && d != 18 && d != 19 && d != 25 && d != 37 && d != 26 && d != 51) {
                                    for (int e = d + 1; e < N; e++) {
                                        if (e != 10 && e != 14 && e != 22 && e != 23 && e != 24 && e != 32 && e != 39 && e != 42 && e != 12 && e != 15 && e != 41 && e != 46 && e != 47 && e != 18 && e != 19 && e != 25 && e != 37 && e != 26 && e != 51) {
                                            for (int f = e + 1; f < N; f++) {
                                                if (f != 10 && f != 14 && f != 22 && f != 23 && f != 24 && f != 32 && f != 39 && f != 42 && f != 12 && f != 15 && f != 41 && f != 46 && f != 47 && f != 18 && f != 19 && f != 25 && f != 37 && f != 26 && f != 51) {
                                                    for (int g = f + 1; g < N; g++) {
                                                        if (g != 10 && g != 14 && g != 22 && g != 23 && g != 24 && g != 32 && g != 39 && g != 42 && g != 12 && g != 15 && g != 41 && g != 46 && g != 47 && g != 18 && g != 19 && g != 25 && g != 37 && g != 26 && g != 51) {
                                                            for (int h = g + 1; h < N; h++) {
                                                                if (h != 10 && h != 14 && h != 22 && h != 23 && h != 24 && h != 32 && h != 39 && h != 42 && h != 12 && h != 15 && h != 41 && h != 46 && h != 47 && h != 18 && h != 19 && h != 25 && h != 37 && h != 26 && h != 51) {
                                                                    for (int i = h + 1; i < N; i++) {
                                                                        if (i != 10 && i != 14 && i != 22 && i != 23 && i != 24 && i != 32 && i != 39 && i != 42 && i != 12 && i != 15 && i != 41 && i != 46 && i != 47 && i != 18 && i != 19 && i != 25 && i != 37 && i != 26 && i != 51) {
                                                                            for (int j = i + 1; j < N; j++) {
                                                                                if (j != 10 && j != 14 && j != 22 && j != 23 && j != 24 && j != 32 && j != 39 && j != 42 && j != 12 && j != 15 && j != 41 && j != 46 && j != 47 && j != 18 && j != 19 && j != 25 && j != 37 && j != 26 && j != 51) {
                                                                                    for (int k = j + 1; k < N; k++) {
                                                                                        if (k != 10 && k != 14 && k != 22 && k != 23 && k != 24 && k != 32 && k != 39 && k != 42 && k != 12 && k != 15 && k != 41 && k != 46 && k != 47 && k != 18 && k != 19 && k != 25 && k != 37 && k != 26 && k != 51) {
                                                                                            for (int l = k + 1; l < N; l++) {
                                                                                                if (l != 10 && l != 14 && l != 22 && l != 23 && l != 24 && l != 32 && l != 39 && l != 42 && l != 12 && l != 15 && l != 41 && l != 46 && l != 47 && l != 18 && l != 19 && l != 25 && l != 37 && l != 26 && l != 51) {
                                                                                                    for (int m = l + 1; m < N; m++) {
                                                                                                        if (m != 10 && m != 14 && m != 22 && m != 23 && m != 24 && m != 32 && m != 39 && m != 42 && m != 12 && m != 15 && m != 41 && m != 46 && m != 47 && m != 18 && m != 19 && m != 25 && m != 37 && m != 26 && m != 51) {
                                                                                                            if (dist[a][b] + dist[a][c] + dist[a][d] + dist[a][e] + dist[a][f] + dist[a][g] + dist[a][h] + dist[a][i] + dist[a][j] + dist[a][k] + dist[a][l] + dist[a][m] + dist[b][c] + dist[b][d] + dist[b][e] + dist[b][f] + dist[b][g] + dist[b][h] + dist[b][i] + dist[b][j] + dist[b][k] + dist[b][l] + dist[b][m] + dist[c][d] + dist[c][e] + dist[c][f] + dist[c][g] + dist[c][h] + dist[c][i] + dist[c][j] + dist[c][k] + dist[c][l] + dist[c][m] + dist[d][e] + dist[d][f] + dist[d][g] + dist[d][h] + dist[d][i] + dist[d][j] + dist[d][k] + dist[d][l] + dist[d][m] + dist[e][f] + dist[e][g] + dist[e][h] + dist[e][i] + dist[e][j] + dist[e][k] + dist[e][l] + dist[e][m] + dist[f][g] + dist[f][h] + dist[f][i] + dist[f][j] + dist[f][k] + dist[f][l] + dist[f][m] + dist[g][h] + dist[g][i] + dist[g][j] + dist[g][k] + dist[g][l] + dist[g][m] + dist[h][i] + dist[h][j] + dist[h][k] + dist[h][l] + dist[h][m] + dist[i][j] + dist[i][k] + dist[i][l] + dist[i][m] + dist[j][k] + dist[j][l] + dist[j][m] + dist[k][l] + dist[k][m] + dist[l][m] == 0) {
                                                                                                                std::cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << ' ' << e + 1 << ' ' << f + 1 << ' ' << g + 1 << ' ' << h + 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << ' ' << l + 1 << ' ' << m + 1 << std::endl;
                                                                                                            }                                                                                                                     
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

