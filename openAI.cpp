#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N = 110;

// 邻接矩阵存储图
int g[N][N];

// dis[i]表示源点到i的最短路径长度
int dis[N];

// vis[i]表示节点i是否被访问过
bool vis[N];

int n, m;

// 使用优先队列优化的Dijkstra算法
void Dijkstra(int s)
{
  // 初始化dis数组
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  // cout << dis[1] << endl;
  // 定义小根堆
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, s});

  while (!q.empty())
  {
    // 取出距离最近的节点
    int u = q.top().second;
    q.pop();

    // 如果节点已经访问过，则跳过

    if (vis[u])
      continue;
    vis[u] = true;

    // 更新其他未访问过的节点的距离
    for (int v = 1; v <= n; v++)
    {
      // 如果节点v未访问过，且存在边(u, v)
      if (!vis[v] && g[u][v] != 0)
      {
        // 更新节点v的距离
        int new_dis = dis[u] + g[u][v];
        if (new_dis < dis[v])
        {
          dis[v] = new_dis;
          q.push({dis[v], v});
        }
      }
    }
  }
}

int main()
{
  cin >> n >> m;

  // 输入图
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    g[u][v] = w;
  }

  int s;
  cin >> s;

  // 调用Dijkstra算法
  Dijkstra(s);

  // 输出源点到其他节点的最短路径
  for (int i = 1; i <= n; i++)
  {
    cout << dis[i] << " ";
  }

  return 0;
}