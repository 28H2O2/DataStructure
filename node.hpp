//* define nodes(initial)
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Map
{
public:
  Map();
  Map(int method);
  vector<int> node_x;
  vector<int> node_y;
  vector<vector<int>> edge; //length of edge

private:
  int method;
};

Map::Map(int method):method(method)
{
  node_x.resize(8); 
  node_x[0] = 0;
  node_x[1] = 30;
  node_x[2] = 90;
  node_x[3] = 20;
  node_x[4] = 150;
  node_x[5] = 80;
  node_x[6] = 70;
  node_x[7] = 170;
  node_x[8] = 120;
  node_x[9] = 190;
  node_y.resize(8); 
  node_y[0] = 0;
  node_y[1] = 10;
  node_y[2] = 10;
  node_y[3] = 90;
  node_y[4] = 70;
  node_y[5] = 120;
  node_y[6] = 180;
  node_y[7] = 20;
  node_y[8] = 130;
  node_y[9] = 190;


  edge.resize(10);
  for (int i = 0; i < 10; ++i)
  {
    edge[i].resize(10);
  }

  if(method == 0)//* walking
  {
    edge[0][1] = 10;
    edge[0][3] = 85;
    edge[1][0] = 10;
    edge[1][2] = 36;
    edge[1][3] = 82;
    edge[1][5] = 146;
    edge[2][1] = 36;
    edge[2][4] = 72;
    edge[2][5] = 122;
    edge[2][7] = 65;
    edge[2][9] = 424;
    edge[3][0] = 85;
    edge[3][1] = 82;
    edge[3][5] = 45;
    edge[3][6] = 106;
    edge[4][2] = 72;
    edge[4][5] = 74;
    edge[4][7] = 29;
    edge[4][8] = 45;
    edge[4][9] = 160;
    edge[5][1] = 146;
    edge[5][2] = 122;
    edge[5][3] = 45;
    edge[5][4] = 74;
    edge[5][6] = 37;
    edge[5][8] = 17;
    edge[6][3] = 106;
    edge[6][5] = 37;
    edge[6][9] = 145;
    edge[7][2] = 65;
    edge[7][4] = 29;
    edge[7][9] = 291;
    edge[8][4] = 45;
    edge[8][5] = 17;
    edge[8][9] = 85;
    edge[9][2] = 424;
    edge[9][4] = 160;
    edge[9][6] = 145;
    edge[9][7] = 291;
    edge[9][8] = 85;
    //* others' values are 0    
  }
  else//* taking bus
  {
    edge[0][1] = 3;
    edge[0][3] = 9;
    edge[1][0] = 3;
    edge[1][2] = 6;
    edge[1][3] = 9;
    edge[1][5] = 12;
    edge[2][1] = 6;
    edge[2][4] = 8;
    edge[2][5] = 11;
    edge[2][7] = 8;
    edge[2][9] = 20;
    edge[3][0] = 9;
    edge[3][1] = 9;
    edge[3][5] = 6;
    edge[3][6] = 10;
    edge[4][2] = 8;
    edge[4][5] = 8;
    edge[4][7] = 5;
    edge[4][8] = 6;
    edge[4][9] = 12;
    edge[5][1] = 12;
    edge[5][2] = 11;
    edge[5][3] = 6;
    edge[5][4] = 8;
    edge[5][6] = 6;
    edge[5][8] = 4;
    edge[6][3] = 10;
    edge[6][5] = 6;
    edge[6][9] = 12;
    edge[7][2] = 8;
    edge[7][4] = 5;
    edge[7][9] = 17;
    edge[8][4] = 6;
    edge[8][5] = 4;
    edge[8][9] = 9;
    edge[9][2] = 20;
    edge[9][4] = 12;
    edge[9][6] = 12;
    edge[9][7] = 17;
    edge[9][8] = 9;    
  }
}


// node_x[0] = 0; 

// vector<vector<int>> edge;


