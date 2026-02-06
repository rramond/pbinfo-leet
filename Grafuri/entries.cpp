#include <fstream>
#include <algorithm>
using namespace std;

struct Entry {
    int a, b, t;
};

Entry v[5005];
int nodes[10005];
int parent[10005], rankv[10005];

int findSet(int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int ra = findSet(a);
    int rb = findSet(b);
    if (ra == rb) return;

    if (rankv[ra] < rankv[rb])
        parent[ra] = rb;
    else if (rankv[ra] > rankv[rb])
        parent[rb] = ra;
    else {
        parent[rb] = ra;
        rankv[ra]++;
    }
}

int main() {
    ifstream fin("entries.in");
    ofstream fout("entries.out");

    int N;
    fin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        fin >> v[i].a >> v[i].b >> v[i].t;
        nodes[cnt++] = v[i].a;
        nodes[cnt++] = v[i].b;
    }

    sort(nodes, nodes + cnt);
    cnt = unique(nodes, nodes + cnt) - nodes;

    for (int i = 0; i < cnt; i++) {
        parent[i] = i;
        rankv[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        int a = lower_bound(nodes, nodes + cnt, v[i].a) - nodes;
        int b = lower_bound(nodes, nodes + cnt, v[i].b) - nodes;

        if (v[i].t == 1)
            unionSet(a, b);
        else
            fout << (findSet(a) == findSet(b)) << "\n";
    }
    

    return 0;
}
