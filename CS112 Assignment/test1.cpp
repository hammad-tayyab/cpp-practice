#include <iostream>
using namespace std;

// returns the character to print at row r, column c for size n
char charAt(int r, int c, int n)
{
    int rows  = 2 * n + 1;
    int width = 4 * n + 3;

    int midRow    = n;
    int midCol    = 2 * n + 1;     // column of vertical line
    int leftCx    = n;             // center of left diamond
    int rightCx   = 3 * n + 2;     // center of right diamond

    int d = (r > midRow) ? (r - midRow) : (midRow - r); // |r-midRow|

    if (c == midCol)        // vertical middle line
        return '|';

    auto classify = [&](int cx) -> char {
        int t = (c > cx ? c - cx : cx - c) + d;  // |c-cx| + |r-midRow|
        if (t == n)  return '#';  // boundary
        if (t <  n)  return '*';  // inside
        return ' ';               // outside
    };

    char fromLeft  = classify(leftCx);
    char fromRight = classify(rightCx);

    if (fromLeft  != ' ') return fromLeft;
    if (fromRight != ' ') return fromRight;
    return ' ';
}

// recursively print columns in a single row
void printCols(int r, int c, int n, int width)
{
    if (c == width) {
        cout << '\n';
        return;
    }
    cout << charAt(r, c, n);
    printCols(r, c + 1, n, width);
}

// recursively print all rows
void printRows(int r, int n, int totalRows, int width)
{
    if (r == totalRows) return;
    printCols(r, 0, n, width);
    printRows(r + 1, n, totalRows, width);
}

// required function
void PrintPattern2(int n, int /*m*/)
{
    if (n <= 0) return;
    int totalRows = 2 * n + 1;
    int width     = 4 * n + 3;
    printRows(0, n, totalRows, width);
}

// demo main (you can change or remove this)
int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    PrintPattern2(a, b);
    return 0;
}