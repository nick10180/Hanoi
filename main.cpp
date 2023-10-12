#include <iostream>
#include <stack>
#include <list>
#define MAXHIGHT  5

using namespace std;

void initTower(stack<int>* pStack){
    /*Function to initialize a stack as the first tower in the Tower of Hanoi problem.
     * Input: Pointer to an int stack
     * Output: Void
     * Requires: std::list, std::stack
     * Edited: 6:40 P.M 30-8-23 By Nicholas Pullara*/
    int j = MAXHIGHT;       //Size of ring to put on the stack
    for(int i = 0; i < MAXHIGHT; i++){
        pStack->push(j);
        j--;
    }
}

void solveHanoi(int curring, int start, int alternate, int destination, const list<stack<int>*>& stacklist){

    if (curring == 0 ){ return; }

    solveHanoi(curring - 1, start, alternate, destination, stacklist);

    solveHanoi(curring - 1, alternate, destination, start, stacklist);



}
int main() {
    stack<int> tower1, tower2, tower3;

    list<stack<int>*> Hanoi {&tower1, &tower2, &tower3};

    initTower(&tower1);

    solveHanoi(MAXHEIGHT, 0, 1, 2, Hanoi);

    while(!tower1.empty()){
        int temp = tower1.top();
        cout << temp << endl;
        tower1.pop();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
