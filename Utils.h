#ifndef UTIL
#define UTIL
#include <vector>
using namespace std;

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

enum Direction {
	Up,
	Down,
	Left,
	Right
};
#endif