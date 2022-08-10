#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void Kruskal()
{
    int point_count, vector_count;
    cout << "Введите количество точек: ";
    cin >> point_count;
    cout << "Введите количество ребер: ";
    cin >> vector_count;
    vector < pair < int, pair<int, int> > > g; // вес - вершина 1 - вершина 2
    cout << "Введите в формате начальная точка-конечная точка-вес" << endl;
    int weight, point1, point2;
    for (int i = 0; i < vector_count; i++) {
        cin >> point1 >> point2 >> weight; //ввод с клавиатуры
        g.push_back(make_pair(weight, make_pair(point1, point2))); //запись в вектор

    }
    vector < pair<int, pair<int, int> > > result;
    sort(g.begin(), g.end()); //сортировка
    vector<int> tree_id(point_count);
    for (int i = 0; i < point_count; ++i)
        tree_id[i] = i;
    for (int i = 0; i < vector_count; ++i)
    {
        int point1 = g[i].second.first, point2 = g[i].second.second, weight = g[i].first;
        if (tree_id[point1] != tree_id[point2])
        {
            result.push_back(make_pair(weight, make_pair(point1, point2)));
            int old_id = tree_id[point2], new_id = tree_id[point1];
            for (int j = 0; j < point_count; ++j) if (tree_id[j] == old_id) tree_id[j] = new_id;
        }
    }
    int sum_weight = 0;
    cout << "Ребра графа с минимальным весом:" << endl;
    cout << "  Вес\tНачальная точка\tКонечная точка" << endl;
    for (pair<int, pair<int, int> > val : result) {
        cout << setw(6) << val.first << "\t" << setw(11) << val.second.first + 1 << "\t" << setw(12) << val.second.second + 1 << endl;
        sum_weight += val.first;
    }
    cout << "Остов минимального веса: " << sum_weight << endl;
}
void Prim() {
    // входные данные
    int n = 8;
    vector < vector<int> > g;
    const int INF = 1000000000; 
    g.push_back({ INF,  6 , INF,  1 , INF, 10,  INF , INF });
    g.push_back({ 6 , INF,  12 ,  1 ,  1 , INF, INF,  INF });
    g.push_back({ INF,  12 , INF, INF,  1 , INF, INF, 1 });
    g.push_back({ 1 ,  1 , INF, INF, 4,  1 ,  7 , INF });
    g.push_back({ INF,  1 ,  1 , 4, INF, INF,  5 ,  8 });
    g.push_back({ 10, INF, INF,  1 , INF, INF,  5 , INF });
    g.push_back({ INF , INF, INF,  7 ,  5 ,  5 , INF,  2 });
    g.push_back({ INF,  INF , 1, INF,  8 , INF,  2 , INF });

    // алгоритм
    cout << "Ребра:" << endl;
    int result_weight = 0;
    vector<bool> used_points(n);
    vector<int> min_weight_e_of_point(n, INF), finish_point_of_min_e(n, -1);
    min_weight_e_of_point[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used_points[j] && (v == -1 || min_weight_e_of_point[j] < min_weight_e_of_point[v]))
                v = j;
        used_points[v] = true;
        if (finish_point_of_min_e[v] != -1) {
            cout << v + 1 << " >>> " << finish_point_of_min_e[v] + 1 << endl;
            result_weight += g[v][finish_point_of_min_e[v]];
        }

        for (int to = 0; to < n; ++to)
            if (g[v][to] < min_weight_e_of_point[to]) {
                min_weight_e_of_point[to] = g[v][to];
                finish_point_of_min_e[to] = v;
            }
    }
    cout << "Остов минимального веса: " << result_weight;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Kruskal();
    Prim();
    return 0;
}
