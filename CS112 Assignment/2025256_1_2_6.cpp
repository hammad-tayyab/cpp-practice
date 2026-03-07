//TAsk 2 pattern (6)
#include <iostream>
#include <cmath>
using namespace std;
// prints a single row
void PrintCol(int col, int max, int hashPos, int starLimit)
{
    if (col > max) return;   //end of row
    int dist = abs(col);     // distance from center anchor |
    if (col == 0)
        cout<<"|";
    else if (dist == hashPos)
        cout<< "#";
    else if (dist < hashPos)
    {
        // print stars 
        if (dist <= starLimit && dist < hashPos - 2)
            cout << "*";
        else
            cout << ".";
    }
    else
        cout << " ";
    cout << " ";
    PrintCol(col + 1, max, hashPos, starLimit);
}
void PrintPattern2(int n, int rowsLeft)
{
    if (rowsLeft < 1) return;
    int level = n - rowsLeft;    // current row number from the top
    int base = n + 2;    //maximum width of the pattern.
    int hashPos = base + level;     //distance from the center | to print the #
    int starLimit = level * 3;   //how many * stars are printed near the center
    int max = base + (n - 1);   //maximum column indexx
    // print current row
    PrintCol(-max, max, hashPos, starLimit);
    cout << endl;
    if (rowsLeft > 1)
    {
        PrintPattern2(n, rowsLeft - 1);
        // print again while returning
        PrintCol(-max, max, hashPos, starLimit);
        cout << endl;
    }
}
int main()
{
    PrintPattern2(5, 5);
    cout << endl;
    PrintPattern2(6, 6);
    return 0;
}