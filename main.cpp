#include <iostream>
#include <stack>
#include <list>
#define MAXHEIGHT 5

using namespace std;

void initTower(stack<int>* pStack){
    /*Function to initialize a stack as the first tower in the Tower of Hanoi problem.
     * Input: Pointer to an int stack
     * Output: Void
     * Requires: std::list, std::stack
     * Edited: 6:40 P.M 30-8-23 By Nicholas Pullara*/
    int j = MAXHEIGHT;       //Size of ring to put on the stack
    for(int i = 0; i < MAXHEIGHT; i++){
        pStack->push(j);
        j--;
    }
}

void solveHanoi(int curring, stack<int>* start, stack<int>* destination,  stack<int>* alternate){

    int temp;
    if (curring == 0 ){ return; }

    solveHanoi(curring - 1, start, alternate, destination);
    temp = start->top();
    cout << temp << "\n";
    start->pop();
    destination->push(temp);
    solveHanoi(curring - 1, alternate, destination, start);



}
int main() {
    stack<int> tower1, tower2, tower3;


    initTower(&tower1);

    solveHanoi(MAXHEIGHT, &tower1, &tower3, &tower2);

    while(!tower3.empty()){
        int temp = tower3.top();
        cout << temp << endl;
        tower3.pop();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
