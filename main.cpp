#include <iostream>
#include <stack>
#include <list>


using namespace std;

void initTower(stack<int>* pStack, int MAXHEIGHT){
    /*Function to initialize a stack as the first tower in the Tower of Hanoi problem.
     * Input: Pointer to an int stack, int MAXHEIGHT the size of Hanoi problem
     * Output: Void
     * Requires: std::list, std::stack
     * Edited: 3:26 P.M 26-10-23 By Nicholas Pullara*/
    int j = MAXHEIGHT;       //Size of ring to put on the stack
    for(int i = 0; i < MAXHEIGHT; i++){
        pStack->push(j);
        j--;
    }
}

void solveHanoi(int curring, stack<int>* start, stack<int>* destination,  stack<int>* alternate){
    /*Function to solve the Tower of Hanoi problem.
     * Input: Int problem size, Pointer to start stack, destination stack, alternate stack
     * Output: Void
     * Requires: std::list, std::stack
     * Edited: 3:26 P.M 26-10-23 By Nicholas Pullara*/
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
    int MAXHEIGHT;
    cout << "Enter problem Size: "; 
    cin >> MAXHEIGHT;
    initTower(&tower1, MAXHEIGHT);

    solveHanoi(MAXHEIGHT, &tower1, &tower3, &tower2);

    while(!tower3.empty()){
        int temp = tower3.top();
        cout << temp << endl;
        tower3.pop();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
