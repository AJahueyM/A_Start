#include <iostream>
#include <vector>
#include "Node.h"
#include <cmath>
#include "Utils.h"
#include "AStar.h"
using namespace std;

vector<vector<Node>> maze;
const int sizeX = 7;
const int sizeY = 5;

void addNeighbors(Node& node){
    int x = node.getX();
    int y = node.getY();

    if(y - 1 >= 0 && !node.getIsWall(Up))
        node.addNeighbor(&maze[y-1][x]);
    if(y + 1 < maze.size() && !node.getIsWall(Down))
        node.addNeighbor(&maze[y+1][x]);
    if(x + 1 < maze[0].size() && !node.getIsWall(Right))
        node.addNeighbor(&maze[y][x+1]);
    if(x - 1 >= 0 && !node.getIsWall(Left))
        node.addNeighbor(&maze[y][x-1]);
}

void updateWalls(){
    for(int y = 0; y < maze.size(); ++y){
        for(int x = 0; x < maze[0].size() ; ++x){
            Node &node = maze[y][x];

            if(y - 1 >= 0 && node.getIsWall(Up))
                maze[y-1][x].setWall(Down, true);
            if(y + 1 < maze.size() && node.getIsWall(Down))
                maze[y+1][x].setWall(Up, true);
            if(x + 1 < maze[0].size() && node.getIsWall(Right))
                maze[y][x+1].setWall(Left, true);
            if(x - 1 >= 0 && node.getIsWall(Left))
                maze[y][x-1].setWall(Right, true);
        }
    }
}
int main(){

    for(int i = 0; i < sizeY; ++i){
        vector<Node> row;
        for(int j = 0; j < sizeX; ++j){
            row.emplace_back(Node(j, i));
        }
        maze.emplace_back(row);
    }
    maze[0][0].setWall(Down, true);

    updateWalls();

    for(vector<Node>& row : maze){
        for(Node& column : row){
            addNeighbors(column);
        }
    }

    Coord start(0,1);
    Coord end(0,0);
    cout << "START: " << "x= " << start.getX() << " y= " << start.getY() << endl;
    cout << "END: " << "x= " << end.getX() << " y= " << end.getY() << endl;

   for(Coord coord : AStar::getPath( start, end, maze).getPath()){
       cout << "X:" << coord.getX() << "\tY:" << coord.getY() << endl;
   }

}