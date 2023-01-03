#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <queue>
#include <stack>
#include <windows.h>
#include <numeric>

#include "node.hpp"
#define MAX 1000000
using namespace std;

int nodes = 10;

int main()
{
  void Dijkstra(int start, int end, Map* map, int method);

  while(1){
    cout << "Please choose a mode of transportation" << endl;
    cout << "You can inupt 0 means walking, input 1 means taking bus, input 9 means QUIT " << endl;
    int method;
    cin >> method;
    if(method == 9)
      break;
    // cout << "This is the entire map from HCY" << endl;
    Map *map = new Map(method);//new Map 
    // Initial_Map(map, method);
    int start, end;
    cout << "Please enter the START point number" << endl;
    cout << "You can choose from 0 to 9" << endl;
    cin >> start;

    cout << "Great! Now please enter the END point number from 0 to 9" << endl;
    cin >> end;
    Dijkstra(start, end, map, method);
  }
  cout << "Bye!" << endl;


}




void Dijkstra(int start, int end, Map* map, int method)//* 在该函数里面直接打印
{
  //* priority queue
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> length_queue;
  vector<int> length;
  for (int i = 0; i < nodes; ++i)
    length.push_back(MAX);
  vector<int> visual;
  visual.resize(nodes);
  vector<int> last;//* The last vertices
  for (int i = 0; i < nodes; ++i)
    last.push_back(-1);

  //* beginning of query

  LARGE_INTEGER t1, t2, tc;//* note the time 
  QueryPerformanceFrequency(&tc);
  QueryPerformanceCounter(&t1);

  length[start] = 0;
  length_queue.push({0, start});
  while (!length_queue.empty())
  {
    int nearest = length_queue.top().second;//* find nearest
    length_queue.pop();//* EXTRACT_MIN

    if(visual[nearest])//* have found
      continue;
    visual[nearest] = 1;

    for(int i = 0; i < nodes; ++i)
    {
      if(!visual[i] && map->edge[i][nearest] != 0)//*if not found & edge exists
      {
        int new_length = length[nearest] + map->edge[i][nearest];
        if(new_length < length[i])  //* update
        {
          length[i] = new_length;
          length_queue.push({length[i], i});
          last[i] = nearest;
        }
      }
    }
  }
  QueryPerformanceCounter(&t2);
  double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
  cout <<"Time = "<< time << " seconds" << endl;

  //* end of query
  cout << "length = " << length[end] << endl;
  int flag = end;
  stack<int> output;//* reverse the order of the output
  while(flag != start)
  {
    output.push(flag);
    flag = last[flag];
  }
  cout << start;
  while(output.size() > 0)
  {
    cout << "->" << output.top();
    output.pop();
  }
  cout << endl;

}

/* NOTE
 *
 *数字
 *权值之和
 *中间经过的点
*/