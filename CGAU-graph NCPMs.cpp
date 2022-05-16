#include <iostream>
#include <vector>
struct Pair {
    int first;
    int second;

    void Sort() {
        if (first > second) {
            std::swap(first, second);
        }
    }

    void Cout() {
        std::cout << first << ' ' << second << '\n';
    }
};

bool Compare(Pair a, Pair b) {
    if ((a.first < b.first && b.first < a.second && a.second < b.second) || (b.first < a.first && a.first < b.second && b.second < a.second)) {
        return false;
    }
    if (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second) {
        return false;
    }
    return true;
}

bool Full_Compare(std::vector<Pair>& pairs) {
    for (int i = 0; i < pairs.size(); ++i) {
        for (int j = i + 1; j < pairs.size(); ++j) {
            if (!Compare(pairs[i], pairs[j])) { return false; }
        }
    }
    return true;
}

int main() {
    std::vector<int> C = { 1, 9, 12, 18 };
    std::vector<int> G = { 2, 10, 11, 17 };
    std::vector<int> A = { 4, 5, 8, 13, 16, 19 };
    std::vector<int> U = { 3, 6, 7, 14, 15, 20 };

    Pair temp;

    std::vector<Pair> CG_pairs;
    std::vector<Pair> AU_pairs;
    for (int c = 0; c < 4; ++c) {
        for (int g = 0; g < 4; ++g) {
            if ((G[g] - C[c]) % 2 != 0) {
                temp.first = C[c];
                temp.second = G[g];
                temp.Sort();
                CG_pairs.push_back(temp);
            }
        }
    }

    for (int a = 0; a < 6; ++a) {
        for (int u = 0; u < 6; ++u) {
            if ((A[a] - U[u]) % 2 != 0) {
                temp.first = A[a];
                temp.second = U[u];
                temp.Sort();
                AU_pairs.push_back(temp);
            }
        }
    }

    int arrangements = 0;
    std::vector<Pair> picked;

    for (int i = 0; i < CG_pairs.size(); ++i) {
        for (int j = i + 1; j < CG_pairs.size(); ++j) {
            for (int k = j + 1; k < CG_pairs.size(); ++k) {
                for (int l = k + 1; l < CG_pairs.size(); ++l) {
                    for (int a = 0; a < AU_pairs.size(); ++a) {
                        for (int b = a + 1; b < AU_pairs.size(); ++b) {
                            for (int c = b + 1; c < AU_pairs.size(); ++c) {
                                for (int d = c + 1; d < AU_pairs.size(); ++d) {
                                    for (int e = d + 1; e < AU_pairs.size(); ++e) {
                                        for (int f = e + 1; f < AU_pairs.size(); ++f) {
                                            picked.clear();
                                            picked.push_back(CG_pairs[i]);
                                            picked.push_back(CG_pairs[j]);
                                            picked.push_back(CG_pairs[k]);
                                            picked.push_back(CG_pairs[l]);
                                            picked.push_back(AU_pairs[a]);
                                            picked.push_back(AU_pairs[b]);
                                            picked.push_back(AU_pairs[c]);
                                            picked.push_back(AU_pairs[d]);
                                            picked.push_back(AU_pairs[e]);
                                            picked.push_back(AU_pairs[f]);
                                            if (Full_Compare(picked)) {
                                                ++arrangements;
                                                for (int np = 0; np < picked.size(); ++np) {
                                                    picked[np].Cout();
                                                }
                                                std::cout << '\n';
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

    std::cout << arrangements;
}
