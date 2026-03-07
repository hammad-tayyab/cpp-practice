//Task2 (3) (pascal triangle's value)
#include <iostream>
using namespace std;
//recursive function to return the value at given row and column
int pascal(int row , int col)
{
    if (col == 0 || col == row) // base case  (first and last element's value is 1)
    {
        return 1;
    }

    //recursive call returning the sum of the two values above it
    return pascal(row-1,col) + pascal(row-1,col-1);
}
int main()
{
    int r, c;
    cout<<"Enter the row index (0,1,2,3...): ";
    cin>>r;
    cout<<"Enter the column index (0,1,2,3...): ";
    cin>>c;
    //checking if the entered indexes are valid
    if (c>r || c<0)
    {
        cout<<"You have entered invalid indexes";
        return 0;
    }
    //calling the function
    cout<<"\nThe value for the index : "<<pascal(r,c);//result

    return 0;
}