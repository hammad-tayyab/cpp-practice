#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    float marks;
    int rollNo;
};

Student inputStudent();
void displayStudent(Student s); 

int main()
{
    Student s1 = inputStudent();
    displayStudent(s1);
    return 0;
}

Student inputStudent()
{
    Student s;
    cout << "\tEnter the details of the student\n";
    cout << "\tName: ";
    getline(cin, s.name); 
    cout << "\tMarks: ";
    cin >> s.marks;
    cout << "\tRoll no.: ";
    cin >> s.rollNo;

    return s; 
}

void displayStudent(Student s)
{
    cout << "\n\t==== Student Information ====";
    cout << "\n\tName: " << s.name;
    cout << "\n\tRoll No: " << s.rollNo;
    cout << "\n\tMarks: " << s.marks << endl;
}