#include <iostream>
#include <stack>

using namespace std;

void initTower(stack<int>* pStack, int maxheight){
    /*Function to initialize a stack as the first tower in the Tower of Hanoi problem.
     * Input: Pointer to an int stack
     * Output: Void
     * Requires: std::stack
     * Edited: 6:10 P.M 12-10-23 By Nicholas Pullara
     * Proofed: By chatGPT 6:20 P.M. 12-10-23
     */
    for(int i = maxheight; i > 0; i--){
        pStack->push(i);
    }
}

void solveHanoi(int currentring, stack<int>* start, stack<int>* destination, stack<int>* alternate){

    /*Function to solve the Tower of Hanoi problem with recursion.
    * Input: int n (problem size), pointer to int stack start with n integers, pointer to int stack destination, pointer to int stack alternate
    * Output: Void
    * Requires: std::stack, std::iostream
    * Edited: 5:49 P.M 12-10-23 By Nicholas Pullara
    * Proofed: By chatGPT 6:20 P.M. 12-10-23
    */
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


    initTower(&tower1, problemsize);

    solveHanoi(problemsize, &tower1, &tower3, &tower2);

    cout << "\n \n Tower 3:\n" ;
    while(!tower3.empty()){
        int temp = tower3.top();
        cout << temp << endl;
        tower3.pop();
    }
    return 0;
}
