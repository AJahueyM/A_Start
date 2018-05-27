#include <iostream>
#include <vector>
#include "Node.h"
#include <cmath>
using namespace std;

vector<vector<Node>> maze;
const int sizeX = 7;
const int sizeY = 5;

vector<Node*> openSet, closedSet;

vector<int> test;

template<class T>
void removeFromVector(vector<T> &vector, T element){
    for(int j = vector.size() - 1; j >= 0; --j){
        if(vector[j] == element){
            vector.erase(vector.begin() + j);
        }
    }
}

template <class T>
int countsOnVector(vector<T> & vector, T element){
    int counter = 0;
    for(T el : vector){
        if(element == el)
            counter++;
    }

    return counter;
}

void addNeighbors(Node& node){
    int x = node.getX();
    int y = node.getY();

    if(!node.getIsWall()){
        if(y + 1 < maze.size())
            node.addNeighbor(&maze[y+1][x]);
        if(y - 1 >= 0)
            node.addNeighbor(&maze[y-1][x]);
        if(x + 1 < maze[0].size())
            node.addNeighbor(&maze[y][x+1]);
        if(x - 1 >= 0)
            node.addNeighbor(&maze[y][x-1]);
    }
}

int heuristic(Node* a, Node* b){
    return abs(b->getX() - a->getX()) + abs(b->getY() - a->getY());
}

int main(){

    for(int i = 0; i < sizeY; ++i){
        vector<Node> row;
        for(int j = 0; j < sizeX; ++j){
            row.emplace_back(Node(j, i));
        }
        maze.emplace_back(row);
    }
    maze[0][1].setWall(true);
    maze[1][2].setWall(true);
    maze[2][0].setWall(true);
    maze[3][1].setWall(true);
    maze[2][3].setWall(true);
    maze[3][3].setWall(true);

    for(vector<Node>& row : maze){
        for(Node& column : row){
            addNeighbors(column);
        }
    }

    Node *start = &maze[0][0], *end = &maze[0][sizeX-1];

    cout << "X size: " << maze[0].size() << " Y size: " << maze.size() << endl;

    openSet.emplace_back(start);

    while(openSet.size() > 0){
        int lowestIndex = 0;
        for(int i = 0; i < openSet.size(); ++i){
            if(openSet[i]->getF() < openSet[lowestIndex]->getF()){
                lowestIndex = i;
            }
        }

        Node *current = openSet[lowestIndex];
        if(current == end){
            cout << "DONE" << endl;

            while(current->getPrevious() != nullptr){
                cout << current->getX() << " " << current->getY() << endl;
                current = current->getPrevious();
            }
            return 0;
        }
        
        closedSet.emplace_back(current);

        removeFromVector(openSet, current);


        vector<Node*> &neighbors = current->getNeighbors();

        for(Node* neighbor : neighbors){
            if(countsOnVector(closedSet, neighbor) == 0){
                int tempG = current->getG() + 1;

                if(countsOnVector(openSet, neighbor)>= 1){
                    if(tempG < neighbor->getG()){
                        neighbor->setG(tempG);
                    }
                }else{
                    neighbor->setG(tempG);
                    openSet.emplace_back(neighbor);
                }
                neighbor->setH(heuristic(neighbor, end));
                neighbor->setF( neighbor->getG() + neighbor->getH());
                neighbor->setPrevious(current);
            }
        }
    }
    cout << "No solution" << endl;

}