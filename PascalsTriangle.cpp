#include <iostream>
using namespace std;
long long fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}
int comb(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}
void printPascal(int totalRows, int currentRow, int currentCol) {

    if (currentRow >= totalRows) return;

    cout << comb(currentRow, currentCol) << " ";

    if (currentCol == currentRow) {
        cout << "\n";
        printPascal(totalRows, currentRow + 1, 0);
    } 
    else {
        printPascal(totalRows, currentRow, currentCol + 1);
    }
}
int main() {
    int n;
    cout << "Enter number of rows: ";
    cin>>n;
    printPascal(n, 0, 0);

    return 0;
}