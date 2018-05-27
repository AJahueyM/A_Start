#include "Node.h"

Node::Node(int x, int y){
    f = 0;
    this->x = x;
    this->y = y;
}

void Node::setF(int f){
    this->f = f;
}

void Node::setH(int h){
    this->h = h;
}

void Node::setG(int g){
    this->g = g;
}

void Node::setX(int x){
    this->x = x;
}

void Node::setY(int y){
    this->y = y;
}

void Node::setPrevious(Node* previous){
    this->previous = previous;
}

void Node::setWall(bool wall){
    this->isWall = wall;
}

int Node::getF() const{
    return f;
}

int Node::getH() const{
    return h;
}

int Node::getG() const{
    return g;
}

int Node::getX() const{
    return x;
}

int Node::getY() const{
    return y;
}

bool Node::getIsWall(){
    return isWall;
}

Node* Node::getPrevious(){
    return previous;
}

void Node::addNeighbor(Node* neighbor){
    neighbors.emplace_back(neighbor);
}

vector<Node*>& Node::getNeighbors(){
    return neighbors;
}


