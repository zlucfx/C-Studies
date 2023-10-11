#include <iostream>
#include <vector>
#include <queue>
#include <climits>
struct Edge
{
    int to, weight;
};

std::vector<int> dijkstra(const std::vector<std::vector<Edge>> &graph, int start)
{

    std::vector<int> dist(graph.size(), INT_MAX);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();

        if (d_v != dist[v])
            continue;

        for (auto edge : graph[v])
        {
            if (dist[v] + edge.weight < dist[edge.to])
            {
                dist[edge.to] = dist[v] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    return dist;
}

int main()
{
    int n, m;
    std::cout << "Digite o número de vértices e arestas: ";
    std::cin >> n >> m;

    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cout << "Digite a aresta e o peso (u v w): ";
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start;
    std::cout << "Digite o vértice inicial: ";
    std::cin >> start;

    std::vector<int> dist = dijkstra(graph, start);

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            std::cout << "Não há caminho para o vértice " << i << "\n";
        else
            std::cout << "Distância do vértice inicial ao vértice " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
