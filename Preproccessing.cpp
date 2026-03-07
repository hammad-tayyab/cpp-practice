//Task 1

// # include <iostream>
// #define PI 3.14
// using namespace std;
// int main(){
//     double radius = 5.0;
//     cout << "Area of circle is: " << PI * radius * radius << endl;
//     return 0;
// }


//Task 2

//# include <iostream>
//#define SQUARE(x)(x*x)
//using namespace std;
//
//int main(){
//	int size = 7;
//	cout<<"The area of the square of "<<size<<" is: "<<SQUARE(size);
//  return 0;
//}

//Task 3

# include <iostream>
# define DEBUG
using namespace std;
int main(){
	#ifdef DEBUG
	cout<<"Debugging is ON";
	#else
	cout<<"Debugging is OFF";
	#endif
	return 0;
}