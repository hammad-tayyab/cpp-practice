//Task 2 (4) Pattern
#include <iostream>
using namespace std;

void printSpaces(int count) //helping function
{
    if (count <= 0) return;
    cout << " ";
    printSpaces(count - 1);
}

void PrintPattern1(int start, int end) {
    //midpoint
    int mid = (1 + end) / 2; 

    // base case to stop at the midpoint
    if (start == mid) {
        cout << "*" << endl;
        return;
    }

    // Top half: spaces based on distance to the midpoint
    printSpaces(mid - start);
    cout << "*" << endl;

    PrintPattern1(start + 1, end);

    // Bottom half (backward substitution)
    printSpaces(mid - start);
    cout << "*" << endl;
}

int main() {
    PrintPattern1(1, 10);// calling the function
    return 0;
}