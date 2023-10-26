#include <iostream>
#include <stack>

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

void solveHanoi(int currentring, stack<int>* start, stack<int>* destination,  stack<int>* alternate){
    /*Function to solve the Tower of Hanoi problem.
     * Input: Int problem size, Pointer to start stack, destination stack, alternate stack
     * Output: Void
     * Requires: std::list, std::stack
     * Edited: 3:26 P.M 26-10-23 By Nicholas Pullara*/
    int temp;
    if (currentring == 0 ){ return; }

    solveHanoi(currentring - 1, start, alternate, destination);
    temp = start->top();

    //Uncomment me to see the steps! Warning: it's in address labels!
    //    cout << temp << " to " << destination << "\n";

    start->pop();
    destination->push(temp);
    solveHanoi(currentring - 1, alternate, destination, start);

}

int main() {
    const int problemsize = 5;

    stack<int> tower1, tower2, tower3;
    int MAXHEIGHT;
    cout << "Enter problem Size: "; 
    cin >> MAXHEIGHT;
    initTower(&tower1, MAXHEIGHT);

    solveHanoi(problemsize, &tower1, &tower3, &tower2);

    cout << "\n \n Tower 3:\n" ;
    while(!tower3.empty()){
        int temp = tower3.top();
        cout << temp << endl;
        tower3.pop();
    }
    return 0;
}
