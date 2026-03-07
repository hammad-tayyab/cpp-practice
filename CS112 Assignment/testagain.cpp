#include <iostream>
#include <cmath>
using namespace std;

void PrintCol(int col, int max_width, int leftHash, int starsInRow)
{
    if (col > max_width) return;

    int dist = abs(col);

    // 1. Padding: If current column is outside the hashtag boundary, print space
    if (dist > leftHash) {
        cout << "  "; 
    }
    // 2. Hashtag
    else if (dist == leftHash) {
        cout << "# ";
    }
    // 3. Center Divider
    else if (col == 0) {
        cout << "| ";
    }
    // 4. Inside the Hashtags: Stars or Dots
    else if (dist < leftHash) {
        if (dist <= starsInRow)
            cout << "* ";
        else
            cout << ". ";
    }

    PrintCol(col + 1, max_width, leftHash, starsInRow);
}

void PrintPattern2(int n, int rowsLeft)
{
    if (rowsLeft < 1) return;

    int level = n - rowsLeft;           
    int leftHash = (n + 2) + level;     
    int starsInRow = (level == 0) ? 0 : (level * 2); 
    
    // Fixed max width based on the middle row to ensure vertical alignment
    int max_width = (n + 2) + (n - 1);

    // Print top half + middle
    PrintCol(-max_width, max_width, leftHash, starsInRow);
    cout << endl;

    if (rowsLeft > 1) {
        PrintPattern2(n, rowsLeft - 1);

        // Print bottom half (backtracking)
        PrintCol(-max_width, max_width, leftHash, starsInRow);
        cout << endl;
    }
}

int main()
{
    PrintPattern2(5, 5); 
    return 0;
}