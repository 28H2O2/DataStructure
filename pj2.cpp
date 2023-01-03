#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <algorithm>
#include <windows.h>
#include <numeric>
#include <sstream>
#include <iomanip>

#include "node.hpp"
#include "Canvas.cpp"
// #include "Coord_mono.cpp"
#include "Coord_gray.cpp"
#include "point.cpp"
using namespace std;



int main()
{
  Canvas *canvas_show = new Canvas("grayscale", 200, 200, "world_coord");
  Canvas *canvas = new Canvas("grayscale", 200, 200, "world_coord");
  // canvas->color(55);
  void Initial_Map(Map* map, Canvas* canvas, int method);
  // Map *map = new Map;
  // Initial_Map(map, canvas_show); 
  void Dijkstra(int start, int end, Map* map, Canvas* canvas, int method);
 

  cout << "Please choose a mode of transportation" << endl;
  cout << "You can inupt 0 means walking, input 1 means taking bus " << endl;
  int method;
  cin >> method;
  cout << "This is the entire map from HCY" << endl;
  // TODO 输出整个地图和路径 用Bresenham Algorithm 
  if(method == 0)
  {
    cout<<"Walking..."<<endl;
    Map *map = new Map(method);//new Map
    Initial_Map(map, canvas_show, method);
    int start, end;
    while(1){
      cout << "Please enter the START point number, input 10 means QUIT" << endl;
      cout << "You can choose from 0 to 9" << endl;
      cin >> start;
      if(start == 10)
        break;
      cout << "Great! Now please enter the END point number from 0 to 9" << endl;
      cin >> end;
      Dijkstra(start, end, map, canvas, method);
    }
    delete map;
  }
    
  else
  {
    cout << "Taking bus..." << endl;
    Map *map = new Map(method);//new Map 
    Initial_Map(map, canvas_show, method);
    int start, end;
    while(1){
      cout << "Please enter the START point number, input 10 means QUIT" << endl;
      cout << "You can choose from 0 to 9" << endl;
      cin >> start;
      if(start == 10)
        break;
      cout << "Great! Now please enter the END point number from 0 to 9" << endl;
      cin >> end;
      Dijkstra(start, end, map, canvas, method);
    }
    delete map;   
  }

  cout << "Bye!" << endl;

  delete canvas_show;
  delete canvas;
  

}


void Dijkstra(int start, int end, Map* map, Canvas* canvas, int method)//* 在该函数里面直接打印
{
  canvas->color(128 * method + 511);//* output w or b for not conflict
  void create_min(vector<int> &a, int k, int n, int l);//* minimum heap
  void EXTRACT_MIN(vector<int> & a, int& n, int k);
  // TODO 这个计算时间的代码位置需要写好之后调整一下
  LARGE_INTEGER t1, t2, tc;//* note the time 
  QueryPerformanceFrequency(&tc);
  QueryPerformanceCounter(&t1);

  vector<int> length;//* length of the start point
  for (int i = 0; i < 10; ++i)
  { // NOTE make a heap
    length.push_back(100000);//* MAX
  }
  vector<int> length_copy;//* can delete node for minimum
  for (int i = 0; i < 10; ++i)
  { // NOTE make a heap
    length_copy.push_back(100000);//* MAX
  }  
  vector<int> last;// what the last point is
  for (int i = 0; i < 10; ++i)
  {
    last.push_back(-1);//* NIL
  }
  vector<int> Q;//* vector of undiscovered points
  for (int i = 0; i < 10; ++i)
  {
    Q.push_back(i);
  }
  vector<int> S;//* vector of minimun
  // S.resize(10); //* S is empty
  length[start] = 0;//* Initial
  length_copy[start] = 0;
  while (S.size() < 10)
  {
    // NOTE 注意以下代码的时间复杂度
    auto minPosition = min_element(length_copy.begin(), length_copy.end());//* find the minimum
    int min = minPosition - length_copy.begin();
    for(int i = 0; i < 10; ++i)//* find the edge 
    {
      if(map->edge[min][i] == 0)
        continue;
      else
      {
        if(length[min] + map->edge[min][i] < length[i] )//* compare
        {
          length[i] = length[min] + map->edge[min][i];
          length_copy[i] = length[min] + map->edge[min][i];
          last[i] = min;
        }
      }
      
    }
    length_copy[min] = 100000;
    // auto iter = std::remove(length_copy.begin(), length_copy.end(), *minPosition);
    // length_copy.erase(iter, length_copy.end());
    S.push_back(min);
  }
  int flag = end;
  while(flag != start)
  {
    // cout << map->node_x[flag] << " " << map->node_y[flag] << endl;
    canvas->line(map->node_x[flag], map->node_y[flag], map->node_x[last[flag]], map->node_y[last[flag]]);

    flag = last[flag];
  }
  canvas->dot(map->node_x[start], map->node_y[start], start);
  canvas->dot(map->node_x[end], map->node_y[end], end);

  QueryPerformanceCounter(&t2);
  double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
  cout <<" "<<time << " " << endl;

  canvas->printresults();
  canvas->clear();
  cout <<"Running Time = "<<time << endl;

  string str = to_string(time);
  
  Canvas *view = new Canvas("grayscale", 150, 100, "world_coord");
  view->color(255);
  view->printstr(0, 20, "TIME: ");
  view->printstr(50, 20, str);
  view->printresults();
  delete view;
}
 

void Initial_Map(Map* map, Canvas* canvas, int method)
{

  canvas->color(128 * method + 511);//* output w or b for not conflict

  for(int i = 0; i < 10; i++)
  {
    for(int j = i; j < 10; j++)
    {
      if(map->edge[i][j] == 0)
        continue;
      else
        canvas->line(map->node_x[i], map->node_y[i], map->node_x[j], map->node_y[j]);
    }
  }
  // canvas->dot(map->node_x[0], map->node_y[0], 10);//* 0 specifical
  for(int i = 0; i < 10; i++)
  {
    canvas->dot(map->node_x[i], map->node_y[i], i);
  }

  canvas->printresults();
  canvas->clear();


}




/*
 *
 *数字
 *权值之和
 *中间经过的点
*/