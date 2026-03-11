//# include <iostream>
//using namespace std;

//void col(int row, int n)
//{
//
//	if(n>row) return;
//	cout<<n<<" ";
//	col(row,n+1);
//}
//void PrintPattern3(int row, int n)
//{
//	if(row > n)
//	{
//		return;
//	}
//	col(row,1);
//	cout<<endl;
//	PrintPattern3(row+1,n);
//	col(row-1,1);
//	cout<<endl;
//
//}
//
//
//
//int main()
//{
//	PrintPattern3(1, 5);
//	return 0;
//}
#include <iostream>
using namespace std;

void Col(int row, int n, int limit) {
	if(n > limit) return;
	if(row >= n) cout << "* ";
	else cout << ". ";
	Col(row, n+1, limit);
}

void Col2(int row, int n, int limit) {
	if(n > limit) return;
	if(n <= row) cout << ". ";
	else cout << "* ";
	Col2(row, n+1, limit);
}

void PrintPattern4(int row, int n) {
	if(row > n) return;
	Col(row, 1, n);
	cout << endl;
	PrintPattern4(row+1, n);
	if(row < n) {
		Col2(n-row, 1, n);
		cout << endl;
	}
}

int main() {
	PrintPattern4(1, 5);
	return 0;
}

//
//#include <iostream>
//using namespace std;
//
//// Prints top half row: stars on left, dots on right
//void Col(int row, int n, int limit)
//{
//    if(n > limit) return;
//    if(row >= n) cout << "* ";
//    else cout << ". ";
//    Col(row, n+1, limit);
//}
//
//// Prints bottom half row: dots on left, stars on right
//void Col2(int row, int n, int limit)
//{
//    if(n > limit) return;
//    if(n <= row) cout << ". ";
//    else cout << "* ";
//    Col2(row, n+1, limit);
//}
//
//// Main recursive function
//void PrintPattern4(int row, int n)
//{
//    if(row > n) return;        // base case: all rows done
//
//    Col(row, 1, n);            // print top half row
//    cout << endl;
//    PrintPattern4(row+1, n);   // recurse down
//    if(row < n) {              // skip middle row on way back
//        Col2(row, 1, n);       // print bottom half row
//        cout << endl;
//    }
//}
//
//int main()
//{
//    PrintPattern4(1, 5);
//    return 0;
//}