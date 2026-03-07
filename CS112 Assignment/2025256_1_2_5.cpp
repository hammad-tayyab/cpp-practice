//Task 2 (5) pattern (hollow diamond)
#include <iostream>
using namespace std;
//helping recursive func to print a row
void printRow(int col, int totalCols, int gapStart, int gapEnd)
{
    if(col > totalCols) // Base Case
    {
        cout<<endl;
        return;
    }
    //if current position is hollow
    if(col > gapStart && col <gapEnd)
        cout<<" ";
    else
        cout<<"*";
    printRow(col + 1, totalCols, gapStart, gapEnd); //recursive call
}
//function to control rows
void drawDiamond(int row, int n)
{
    if(row == 2*n) // Base Case
        return;
    int mid = n;
    //calculating distance from middle row
    int dist;
    if(row < mid)
        dist = mid - row;
    else
        dist = row - mid + 1;
    int totalCols = 2*n;
    //defining hollow region
    int gapStart = dist;
    int gapEnd = totalCols - dist + 1;
    printRow(1, totalCols, gapStart, gapEnd); //printing row func
    drawDiamond(row + 1, n); //recursive call
}
//main func
void printHollowDiamond(int n)
{
    if(n <= 0)
        return;
    drawDiamond(0, n); //function call
}
int main()
{
    int n;
    cout<< "Enter n: ";
    cin>>n;
    printHollowDiamond(n); //function call
    return 0;
}