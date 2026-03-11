//#include <iostream>
//#include <string>
//using namespace std;
//class Student
//{
//	private:
//		string name;
//		int* grades;
//		int TotalMarks;
//	public:
//		Student()
//		{
//			name = "Unknown";
//			grades = new int[3];
//			for(int i=0; i<3; ++i)
//				grades[i] = -1;
//			TotalMarks =0;
//		}
//		Student(string name)
//		{
//			this->name = name;
//			grades = new int[3];
//			for(int i=0; i<3; ++i)
//				grades[i] = -1;
//			TotalMarks =0;
//		}
//		Student(const Student &other)
//		{
//			// SHALLOW COPY PROBLEM - do NOT rely on default compiler copy:
//			// Student s2 = s1; without our copy constructor would copy
//			// the pointer address only. Both would point to SAME array.
//			// Result 1: changing one object's grades corrupts the other.
//			// Result 2: when one is destroyed, delete[] frees that memory.
//			// The other object is now a dangling pointer — crash!
//			//
//			// DEEP COPY SOLUTION:
//			// We allocate a new array and copy values individually.
//			// Both objects are now fully independent.
//
//			name = other.name;           // ? copy FROM other
//			TotalMarks = other.TotalMarks; // ? copy FROM other
//			grades = new int[3];         // ? brand new memory for THIS object
//			for(int i = 0; i < 3; i++)
//				grades[i] = other.grades[i]; // ? copy actual values
//		}
//
//		~Student()
//		{
//			delete[] grades;
//			cout<<"destructor was called";
//		}
//		string getname()
//		{
//			return name;
//		}
//		int getMarks()
//		{
//			return TotalMarks;
//		}
//		int getgrade(int index)
//		{
//			return grades[index];
//		}
//		void setname(string name)
//		{
//			this->name =name;
//		}
//		void setmarks(int marks)
//		{
//			TotalMarks = marks;
//		}
//		void setgrade (int index, int value)
//		{
//			grades[index] = value;
//		}
//};
//void printGrades(Student& s, int index)
//{
//	if(index == 3)
//		{
//			cout<<"All grade are printed"<<endl;
//			return;
//		}
//	cout<<"Grade "<<index<<" : "<<s.getgrade(index)<<endl;
//	printGrades(s,index + 1);
//}
//
//int main()
//{
//	Student s1("tommy");
//	s1.setgrade(2,75);
//	s1.setgrade(0,75);
//	s1.setgrade(1,75);
//	printGrades(s1, 0);
//
//	return 0;
//}
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Library
//{
//	private:
//		string librarianName;
//		int* bookIDs;
//		int totalBooksIssued;
//
//	public:
//		// Default Constructor
//		Library()
//		{
//			librarianName = "Unknown";
//			bookIDs = new int[5];
//			for (int i = 0; i < 5; i++) bookIDs[i] = -1;
//			totalBooksIssued = 0;
//		}
//
//		// Parameterized Constructor
//		Library(string name)
//		{
//			librarianName = name;
//			bookIDs = new int[5];
//			for (int i = 0; i < 5; i++) bookIDs[i] = -1;
//			totalBooksIssued = 0;
//		}
//
//		Library(const Library& other)
//		{
//			librarianName = other.librarianName;
//			totalBooksIssued = other.totalBooksIssued;
//			bookIDs = new int[5];
//			for (int i = 0; i < 5; i++)
//				{
//					bookIDs[i] = other.bookIDs[i];
//				}
//		}
//
//		~Library()
//		{
//			delete[] bookIDs;
//			cout << "Destructor: " << librarianName << " session ended. Memory freed." << endl;
//		}
//
//		// Getters
//		string getLibrarianName()
//		{
//			return librarianName;
//		}
//		int getTotalIssued()
//		{
//			return totalBooksIssued;
//		}
//		int getBookID(int index)
//		{
//			return bookIDs[index];
//		}
//
//		// Setters
//		void setLibrarianName(string n)
//		{
//			librarianName = n;
//		}
//		void setBookID(int index, int id)
//		{
//			bookIDs[index] = id;
//		}
//		void setTotalIssued(int t)
//		{
//			totalBooksIssued = t;
//		}
//};
//
//void issueBooks(Library& lib, int round)
//{
//	// Base Case
//	if (round == 5)
//		{
//			cout << "\nAll 5 books issued!" << endl;
//			return;
//		}
//
//	cout << "\n--- Round " << round + 1 << " ---" << endl;
//
//	int flaggedID = -1;
//	if (round == 2)
//		{
//			cout << "*** Audit Mode Activated! ***" << endl;
//			{
//				Library auditor = lib; // Copy constructor called
//				int lastID = auditor.getBookID(round - 1);
//				flaggedID = lastID * 2;
//				cout << "Auditor saw last Book ID: " << lastID << endl;
//				cout << "Auditor flagged suspicious ID: " << flaggedID << endl;
//			} // Auditor destructor fires here
//		}
//
//	int id;
//	cout << "Librarian " << lib.getLibrarianName() << ", enter Book ID: ";
//	cin >> id;
//
//	if (round == 2)
//		{
//			if (id == flaggedID) cout << "⚠️ Suspicious book flagged by auditor!" << endl;
//			else cout << "Book cleared by auditor." << endl;
//		}
//
//	lib.setBookID(round, id);
//	cout << "Book [" << id << "] successfully issued at slot " << round + 1 << endl;
//
//	lib.setTotalIssued(lib.getTotalIssued() + 1);
//
//	// Recursive Call
//	issueBooks(lib, round + 1);
//}
//
//int main()
//{
//	Library lib("Sarah");
//
//	issueBooks(lib, 0);
//
//	cout << "\nFinal total books issued: " << lib.getTotalIssued() << endl;
//	cout << "Exiting main..." << endl;
//
//	return 0;

//}


#include <iostream>
using namespace std;

// Helper 1: prints n dots recursively
void printDots(int n) {
    if (n <= 0) return;      // base case
    cout << ". ";
    printDots(n - 1);        // one less dot
}

// Helper 2: prints n stars recursively
void printStars(int n) {
    if (n <= 0) return;      // base case
    cout << "* ";
    printStars(n - 1);       // one less star
}

// Helper 3: prints ONE complete row
void printRow(int stars, int n) {
    int dots = n - stars;    // remaining spaces = dots
    cout << "# ";
    printDots(dots);         // left dots
    printStars(stars);       // left stars
    cout << "| ";            // middle divider
    printStars(stars);       // right stars
    printDots(dots);         // right dots
    cout << "#" << endl;
}

// Main function — handles all rows
void PrintPattern2(int row, int n) {
    if (row > 2 * n - 1) return;  // base case: all rows done

    // Calculate stars for this row
    int stars;
    if (row <= n)
        stars = row - 1;          // going DOWN: 0,1,2,3...
    else
        stars = 2 * n - 1 - row;  // going UP: ...3,2,1,0

    printRow(stars, n - 1);
    PrintPattern2(row + 1, n);    // next row
}

int main() {
    PrintPattern2(1, 5);  // start at row 1
    return 0;
}