# include <iostream>
# include <string>
using namespace std;
struct Classroom {
	string className;
	float student[5];
	int totalStudent = 5;
};
void inputClassData(Classroom *c);
float calculateAverage(Classroom c);
void displayClassInfo(Classroom c);
int main() {
	Classroom Class;
	inputClassData(&Class);
	displayClassInfo(Class);
	return 0;
}
void inputClassData(Classroom *c) {
	cout <<"Enter class name: ";
	cin >>c->className;
	for (int i=0; i<5; i++) {
		cout<<"Enter the marks of student "<<i+1<<" :";
		cin>>c->student[i];
	}
}
float calculateAverage(Classroom c) {
	float total;
	for (int i = 0; i<5; i++) {
		total+=c.student[i];
	}
	float avg = total/c.totalStudent;
	return avg;
}
void displayClassInfo(Classroom c) {
	cout <<"\n====Info====\n";
	cout <<"Class Name : "<<c.className<<endl;
	for(int i = 0; i <5; i++) {
		cout<<"Student "<<i+1<<" Marks : "<<c.student[i]<<endl;
	}
	cout <<"The avg marks of the class :"<<calculateAverage(c);
}

