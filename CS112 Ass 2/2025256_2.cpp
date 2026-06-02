#include <iostream>
#include <string>
using namespace std;
//enum for grades
enum GradeLevel {
	A_PLUS, A, B_PLUS, B, C_PLUS, C, D, F, GRADE_NOT_ASSIGNED
};
// fucntoin to convert marks in enum grade
GradeLevel marksToGrade(int marks) {
	if (marks >= 90) return A_PLUS;
	if (marks >= 85) return A;
	if (marks >= 80) return B_PLUS;
	if (marks >= 70) return B;
	if (marks >= 65) return C_PLUS;
	if (marks >= 60) return C;
	if (marks >= 50) return D;
	return F;
}
// converting the grade enum into readable grade
const char* gradeToString(GradeLevel g) {
	switch (g) {
		case A_PLUS:
			return "A+";
		case A:
			return "A";
		case B_PLUS:
			return "B+";
		case B:
			return "B";
		case C_PLUS:
			return "C+";
		case C:
			return "C";
		case D:
			return "D";
		case F:
			return "F";
		default:
			return "Not Assigned";
	}
}
//---------------------------------------------------------------
//class of Grades
class Grade {
	private:
		int marks;
		GradeLevel grade;

	public:
		Grade() : marks(-1), grade(GRADE_NOT_ASSIGNED) {} //defualt constructor
		Grade(int m) : marks(m), grade(marksToGrade(m)) {} //parameterized constructor
		//getters
		int getMarks() const {
			return marks;
		}
		GradeLevel getGrade() const {
			return grade;
		}
		//setters
		void setMarks(int m) {
			marks = m;
			grade = marksToGrade(m);
		}

		void display() const {
			if (marks == -1)
				cout << "  Marks: N/A  | Grade: Not Assigned\n";
			else
				cout << "  Marks: " << marks << " | Grade: " << gradeToString(grade) << "\n";
		}
};
//declaring before hand so that i could easlily pass reference to the classes
class Student;
class Teacher;
class Course;
//---------------------------------------------------------------------
//Person class
class Person {
	protected:
		string name;
		int age;
		string address;

	public:
		Person() : age(0) {} //defualt contructor
		Person(const string& n, int a, const string& addr): name(n), age(a), address(addr) {}
		// Getters
		const string& getName() const {
			return name;
		}
		int getAge() const {
			return age;
		}
		const string& getAddress() const {
			return address;
		}
		// Setters
		void setName(const string& n) {
			name = n;
		}
		void setAge(int a) {
			age = a;
		}
		void setAddress(const string& a) {
			address = a;
		}
		virtual void display() const {
			cout << "  Name   : " << name    << "\n";
			cout << "  Age    : " << age     << "\n";
			cout << "  Address: " << address << "\n";
		}

		virtual ~Person() {} //virtual destructor so that the derived classes destructor also works
};
// ----------------------------------------------------------
//Course class
class Course {
	private:
		string name;
		string code;
		Teacher* teacher;           // pointer to assigned teacher
		Student** enrolledStudents; // dynamic array of currently enrolled students
		int enrolledCount;
		Student** droppedStudents;  // dynamic array of dropped students
		int droppedCount;
		Grade* grades;

	public:
		Course() : teacher(nullptr), enrolledCount(0), droppedCount(0) {
			enrolledStudents = new Student*[100];
			grades = new Grade[100];
			droppedStudents = new Student*[100];
		}

		Course(const string& n, const string& c)
			: name(n), code(c), teacher(nullptr), enrolledCount(0), droppedCount(0) {
			enrolledStudents = new Student*[100];
			grades  = new Grade[100];
			droppedStudents  = new Student*[100];
		}

		~Course() {
			delete[] enrolledStudents;
			delete[] grades;
			delete[] droppedStudents;
		}

		// Getters
		const string& getName()          const {
			return name;
		}
		const string& getCode()          const {
			return code;
		}
		Teacher*      getTeacher()       const {
			return teacher;
		}
		int           getEnrolledCount() const {
			return enrolledCount;
		}
		Student*      getEnrolled(int i) const {
			return enrolledStudents[i];
		}
		Grade&        getGrade(int i) {
			return grades[i];
		}

		// Setters
		void setName(const string& n) {
			name = n;
		}
		void setCode(const string& c) {
			code = c;
		}
		void setTeacher(Teacher* t) {
			teacher = t;
		}

		// Returns true if this student is already enrolled
		bool isEnrolled(Student* s) const {
			for (int i = 0; i < enrolledCount; i++)
				if (enrolledStudents[i] == s) return true;
			return false;
		}

		// Add a student to the course
		bool enrollStudent(Student* s) {
			if (isEnrolled(s)) {
				cout << " ! Student already enrolled." << endl;
				return false;
			}
			if (enrolledCount >= 100) {
				cout << " ! Course is full." << endl;
				return false;
			}
			enrolledStudents[enrolledCount] = s;
			grades[enrolledCount] = Grade();  // no marks yet
			enrolledCount++;
			return true;
		}

		// Remove a student from the course
		bool dropStudent(Student* s) {
			for (int i = 0; i < enrolledCount; i++) {
				if (enrolledStudents[i] == s) {
					droppedStudents[droppedCount++] = s;
					// shift everything left to fill the gap
					for (int j = i; j < enrolledCount - 1; j++) {
						enrolledStudents[j] = enrolledStudents[j + 1];
						grades[j] = grades[j + 1];
					}
					enrolledCount--;
					return true;
				}
			}
			cout << " ! Student not found in course." << endl;
			return false;
		}

		// Set marks for a specific student
		void assignMarks(Student* s, int marks) {
			for (int i = 0; i < enrolledCount; i++) {
				if (enrolledStudents[i] == s) {
					grades[i].setMarks(marks);
					return;
				}
			}
			cout << " ! Student not enrolled." << endl;
		}

		// Get the grade for a specific student
		Grade* getStudentGrade(const Student* s) {
			for (int i = 0; i < enrolledCount; i++)
				if (enrolledStudents[i] == s) return &grades[i];
			return nullptr;
		}

		// operator+ enrolls a student
		Course& operator+(Student* s) {
			enrollStudent(s);
			return *this;
		}

		// operator- drops a student
		Course& operator-(Student* s) {
			dropStudent(s);
			return *this;
		}

		friend ostream& operator<<(ostream& out, const Course& c);
		void display() const;

		// Show how many students got each grade in this course
		void displayGradeDistribution() const {
			int counts[9] = {0};
			for (int i = 0; i < enrolledCount; i++) {
				GradeLevel g = grades[i].getGrade();
				if (g != GRADE_NOT_ASSIGNED) counts[g]++;
			}
			const char* labels[] = {"A+","A","B+","B","C+","C","D","F"};
			cout << "  --- Grade Distribution for " << name << endl;
			for (int i = 0; i < 8; i++)
				cout << "  " << labels[i] << " : " << counts[i] << " student(s)" << endl;
		}

		// Returns index of the student with the highest marks
		int findTopStudentIndex() const {
			int topIdx = -1, topMarks = -1;
			for (int i = 0; i < enrolledCount; i++) {
				if (grades[i].getMarks() > topMarks) {
					topMarks = grades[i].getMarks();
					topIdx = i;
				}
			}
			return topIdx;
		}
};
//=================================================
//Student class inheritingn the person
class Student : public Person {
	private:
		string rollNo;
		string department;
		Course** enrolledCourses;
		int enrolledCount;
		int enrolledCapacity;
		Course** droppedCourses;
		int droppedCount;
		// resizing the courses by deleting the old and assigning the new increased memory
		void growCourses() {
			int newCap   = enrolledCapacity * 2;
			Course** tmp = new Course*[newCap];
			for (int i = 0; i < enrolledCount; i++) tmp[i] = enrolledCourses[i];
			delete[] enrolledCourses;
			enrolledCourses  = tmp;
			enrolledCapacity = newCap;
		}
	public:
		Student() : enrolledCount(0), enrolledCapacity(4), droppedCount(0) { //defualt constructor
			enrolledCourses = new Course*[enrolledCapacity];
			droppedCourses  = new Course*[20];
		}
		//parameterized consturctor with the person class as well
		Student(const string& n, int age, const string& addr,const string& roll, const string& dept): Person(n, age, addr), rollNo(roll), department(dept),enrolledCount(0), enrolledCapacity(4), droppedCount(0) {
			enrolledCourses = new Course*[enrolledCapacity];
			droppedCourses  = new Course*[20];
		}
		~Student() { //destructor deleting the dynamic memory
			delete[] enrolledCourses;
			delete[] droppedCourses;
		}
		// Getters
		string getRollNo() const {
			return rollNo;
		}
		string getDepartment() const {
			return department;
		}
		int getCourseCount() const {
			return enrolledCount;
		}
		Course* getCourse(int i) const {
			return enrolledCourses[i];
		}
		// Setters
		void setRollNo(const string& r) {
			rollNo = r;
		}
		void setDepartment(const string& d) {
			department = d;
		}
		// adding a course
		void addCourse(Course* c) {
			if (enrolledCount == enrolledCapacity) growCourses();
			enrolledCourses[enrolledCount++] = c;
		}
		// dropping a course
		void removeCourse(Course* c) {
			for (int i = 0; i < enrolledCount; i++) {
				if (enrolledCourses[i] == c) {
					droppedCourses[droppedCount++] = c;
					for (int j = i; j < enrolledCount - 1; j++)
						enrolledCourses[j] = enrolledCourses[j + 1];
					enrolledCount--;
					return;
				}
			}
		}
		//overloading the == operatoer to comparing the students (bonus quest)
		bool operator==(const Student& other) const {
			return rollNo == other.rollNo;
		}
		// overloading the << opertator to print a summary
		friend ostream& operator<<(ostream& out, const Student& s);
		void display() const override { //aas thsi fucntoin is also present in the base class
			cout << "  Roll No   : " << rollNo << endl;
			cout << "  Dept      : " << department << endl;
			Person::display(); //callin ght epersons display fucntion
			cout << "  Enrolled  : " << enrolledCount << " course(s)\n";
			cout << "  Dropped   : " << droppedCount  << " course(s)\n";
		}
		void viewEnrolledCourses() const {
			if (enrolledCount == 0) {
				cout << "  No enrolled courses."<<endl;
				return;
			}
			cout << "  Enrolled Courses:\n";
			for (int i = 0; i < enrolledCount; i++)
				cout << "    [" << i+1 << "] " << enrolledCourses[i]->getCode()
				     << " - " << enrolledCourses[i]->getName() << "\n";
		}
		void viewDroppedCourses() const {
			if (droppedCount == 0) {
				cout << "  No dropped courses.\n";
				return;
			}
			cout << "  Dropped Courses:\n";
			for (int i = 0; i < droppedCount; i++)
				cout << "    [" << i+1 << "] " << droppedCourses[i]->getCode()
				     << " - " << droppedCourses[i]->getName() << "\n";
		}
		// Show grades for all enrolled courses
		void viewGrades() const {
			cout << "  Grades:\n";
			for (int i = 0; i < enrolledCount; i++) {
				Grade* g = enrolledCourses[i]->getStudentGrade(this);
				cout << "    " << enrolledCourses[i]->getName() << " -> ";
				if (g) g->display();
				else  cout << "Not graded\n";
			}
		}
};

// ----------------------------------------------------------
// Teacher class inheritng fromt he person class
class Teacher : public Person {
	private:
		double salary;
		string department;
		Course** assignedCourses;
		int courseCount;
		int courseCapacity;
		// resizing the dynamic array
		void growCourses() {
			int newCap = courseCapacity * 2;
			Course** tmp = new Course*[newCap];
			for (int i = 0; i < courseCount; i++) tmp[i] = assignedCourses[i];
			delete[] assignedCourses;
			assignedCourses = tmp;
			courseCapacity  = newCap;
		}

	public:
		Teacher():salary(0), courseCount(0), courseCapacity(4) { //defualt constructor
			assignedCourses = new Course*[courseCapacity];
		}
		//parametized constrauctor
		Teacher(const string& n, int age, const string& addr,double sal, const string& dept): Person(n, age, addr), salary(sal), department(dept),courseCount(0), courseCapacity(4) {
			assignedCourses = new Course*[courseCapacity];
		}
		~Teacher() { //destructor
			delete[] assignedCourses;
		}
		string getDepartment()const {
			return department;
		}
		double getSalary() const {
			return salary;
		}
		int getCourseCount() const {
			return courseCount;
		}
		Course* getCourse(int i) const {
			return assignedCourses[i];
		}

		void setSalary(double s) {
			salary = s;
		}
		void setDepartment(const string& d) {
			department = d;
		}
		// Assign a course to this teacher and update the course's teacher pointer
		void assignCourse(Course* c) {
			if (courseCount == courseCapacity) growCourses();
			assignedCourses[courseCount++] = c;
			c->setTeacher(this);
		}

		// Remove a course from this teacher and clear the course's teacher pointer
		void deallocateCourse(Course* c) {
			for (int i = 0; i < courseCount; i++) {
				if (assignedCourses[i] == c) {
					for (int j = i; j < courseCount - 1; j++)
						assignedCourses[j] = assignedCourses[j + 1];
					courseCount--;
					c->setTeacher(nullptr);
					return;
				}
			}
		}
		// operator<< prints a one-line teacher summary
		friend ostream& operator<<(ostream& out, const Teacher& t);
		void display() const override {
			cout << "  Salary    : " << salary << endl;
			cout << "  Dept      : " << department << endl;
			Person::display();
			cout << "  Courses   : " << courseCount << " assigned\n";
		}
		void viewAssignedCourses() const {
			if (courseCount == 0) {
				cout <<"  No assigned courses.\n";
				return;
			}
			for (int i = 0; i < courseCount; i++)
				cout << "    [" << i+1 << "] "<< assignedCourses[i]->getCode() << " - "<< assignedCourses[i]->getName() << "\n";
		}
		// Assign marks to a student in a specific course
		void assignMarks(Course* c, Student* s, int marks) {
			c->assignMarks(s, marks);
		}
		// Print the student with the highest marks in a course
		void findTopStudent(Course* c) const {
			int idx = c->findTopStudentIndex();
			if (idx == -1) {
				cout << "  No graded students.\n";
				return;
			}
			cout << "  Top Student: "
			     << c->getEnrolled(idx)->getName()
			     << " | Marks: " << c->getGrade(idx).getMarks()
			     << " | Grade: "  << gradeToString(c->getGrade(idx).getGrade()) << "\n";
		}
};
// ----------------------------------------------------------
//class admin inherits from the person
class Admin : public Person {
	private:
		double salary;
	public:
		Admin() : salary(0) {}
		Admin(const string& n, int age, const string& addr, double sal): Person(n, age, addr), salary(sal) {}
		double getSalary() const {
			return salary;
		}
		void setSalary(double s) {
			salary = s;
		}
		// operator<< prints admin info
		friend ostream& operator<<(ostream& out, const Admin& a); //declarations
		void display() const override {
			cout << "  [Admin]\n";
			cout << "  Salary: " << salary << "\n";
			Person::display();
		}
};

// ----------------------------------------------------------
//operator << overloading definations (declared int the classes previously)
ostream& operator<<(ostream& out, const Student& s) {
	out << "  [Student] " << s.name << " | Roll: " << s.rollNo
	    << " | Dept: " << s.department << "\n";
	return out;
}
ostream& operator<<(ostream& out, const Teacher& t) {
	out << "  [Teacher] " << t.name << " | Dept: " << t.department
	    << " | Salary: " << t.salary << "\n";
	return out;
}
ostream& operator<<(ostream& out, const Admin& a) {
	out << "  [Admin] " << a.name << " | Salary: " << a.salary << "\n";
	return out;
}
ostream& operator<<(ostream& out, const Course& c) {
	out << "  [Course] " << c.code << " - " << c.name
	    << " | Enrolled: " << c.enrolledCount << "\n";
	return out;
}
// Show course info and its teacher
void Course::display() const { //diplay funddoin defination
	cout << *this;
	if (teacher) cout << "  Teacher: " << teacher->getName() << "\n";
	else         cout << "  Teacher: Not Assigned\n";
}

//recursive fucntoins
// Search student array by roll number, returns index or -1
int findStudentRecursive(Student** students, int size, const string& rollNo, int idx = 0) {
	if (idx >= size) return -1;
	if (students[idx]->getRollNo() == rollNo) return idx;
	return findStudentRecursive(students, size, rollNo, idx + 1);
}
// Print all students one by one using recursion
void displayStudentsRecursive(Student** students, int size, int idx = 0) {
	if (idx >= size) return;
	cout << *students[idx];
	displayStudentsRecursive(students, size, idx + 1);
}
// Add up all marks for a student across their courses (used to get average)
int calcTotalMarksRecursive(Student* s, int idx = 0) {
	if (idx >= s->getCourseCount()) return 0;
	Grade* g = s->getCourse(idx)->getStudentGrade(s);
	int m;
	if (g && g->getMarks() >= 0)
		m = g->getMarks();
	else
		m = 0;
	return m + calcTotalMarksRecursive(s, idx + 1);
}

//main class LMS
class LMS {
	private:
		Student** students;
		int       stuCount, stuCapacity;
		Teacher** teachers;
		int       tchCount, tchCapacity;
		Course**  courses;
		int       crsCount, crsCapacity;
		// resizing the array
		void growStudents() {
			int newCap    = stuCapacity * 2; //doubling the array size
			Student** tmp = new Student*[newCap];
			for (int i = 0; i < stuCount; i++) tmp[i] = students[i];
			delete[] students;
			students    = tmp;
			stuCapacity = newCap;
		}
		void growTeachers() {
			int newCap    = tchCapacity * 2;
			Teacher** tmp = new Teacher*[newCap];
			for (int i = 0; i < tchCount; i++) tmp[i] = teachers[i];
			delete[] teachers;
			teachers    = tmp;
			tchCapacity = newCap;
		}
		void growCourses() {
			int newCap   = crsCapacity * 2;
			Course** tmp = new Course*[newCap];
			for (int i = 0; i < crsCount; i++) tmp[i] = courses[i];
			delete[] courses;
			courses     = tmp;
			crsCapacity = newCap;
		}
		// Find teacher index by name, returns -1 if not found
		int findTeacherIdx(const string& name) const {
			for (int i = 0; i < tchCount; i++)
				if (teachers[i]->getName() == name) return i;
			return -1;
		}
		// Find course index by code, returns -1 if not found
		int findCourseIdx(const string& code) const {
			for (int i = 0; i < crsCount; i++)
				if (courses[i]->getCode() == code) return i;
			return -1;
		}
	public:
		LMS() : stuCount(0), stuCapacity(4), tchCount(0), tchCapacity(4),crsCount(0), crsCapacity(4) { //defualt consturctoer
			students = new Student*[stuCapacity];
			teachers = new Teacher*[tchCapacity];
			courses  = new Course*[crsCapacity];
		}
		// Free all dynamically allocated memory
		~LMS() { //destructor
			for (int i = 0; i < stuCount; i++) delete students[i];
			for (int i = 0; i < tchCount; i++) delete teachers[i];
			for (int i = 0; i < crsCount; i++) delete courses[i];
			delete[] students;
			delete[] teachers;
			delete[] courses;
		}
		// ---- ADMIN FUNCTIONS ----
		void addStudent(const string& name, int age, const string& addr,
		                const string& roll, const string& dept) {
			if (stuCount == stuCapacity) growStudents();
			students[stuCount++] = new Student(name, age, addr, roll, dept);
			cout << "  [+] Student added: " << name << "\n";
		}
		void removeStudent(const string& rollNo) {
			int idx = findStudentRecursive(students, stuCount, rollNo);
			if (idx == -1) {
				cout << "  [!] Student not found.\n";
				return;
			}
			cout << "  [-] Removing: " << students[idx]->getName() << "\n";
			delete students[idx];
			for (int i = idx; i < stuCount - 1; i++) students[i] = students[i + 1];
			stuCount--;
		}
		void updateStudent(const string& rollNo) {
			int idx = findStudentRecursive(students, stuCount, rollNo);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			string buf;
			int age;
			cout << "  New Name    : ";
			cin.ignore();
			getline(cin, buf);
			students[idx]->setName(buf);
			cout << "  New Age     : ";
			cin >> age;
			students[idx]->setAge(age);
			cout << "  New Address : ";
			cin.ignore();
			getline(cin, buf);
			students[idx]->setAddress(buf);
			cout << "  New Dept    : ";
			getline(cin, buf);
			students[idx]->setDepartment(buf);
			cout << "  [*] Updated.\n";
		}

		void viewAllStudents() const {
			if (stuCount == 0) {
				cout << "  No students.\n";
				return;
			}
			cout << "  --- All Students ---\n";
			displayStudentsRecursive(students, stuCount);
		}
		void addTeacher(const string& name, int age, const string& addr,
		                double sal, const string& dept) {
			if (tchCount == tchCapacity) growTeachers();
			teachers[tchCount++] = new Teacher(name, age, addr, sal, dept);
			cout << "  [+] Teacher added: " << name << "\n";
		}
		void removeTeacher(const string& name) {
			int idx = findTeacherIdx(name);
			if (idx == -1) {
				cout << "  [!] Teacher not found.\n";
				return;
			}
			delete teachers[idx];
			for (int i = idx; i < tchCount - 1; i++) teachers[i] = teachers[i + 1];
			tchCount--;
			cout << "  [-] Teacher removed.\n";
		}
		void viewAllTeachers() const {
			if (tchCount == 0) {
				cout << "  No teachers.\n";
				return;
			}
			cout << "  --- All Teachers ---\n";
			for (int i = 0; i < tchCount; i++) cout << *teachers[i];
		}

		void addCourse(const string& name, const string& code) {
			if (crsCount == crsCapacity) growCourses();
			courses[crsCount++] = new Course(name, code);
			cout << "  [+] Course added: " << code << " - " << name << "\n";
		}

		void removeCourse(const string& code) {
			int idx = findCourseIdx(code);
			if (idx == -1) {
				cout << "  [!] Course not found.\n";
				return;
			}
			delete courses[idx];
			for (int i = idx; i < crsCount - 1; i++) courses[i] = courses[i + 1];
			crsCount--;
			cout << "  [-] Course removed.\n";
		}
		void viewAllCourses() const {
			if (crsCount == 0) {
				cout << "  No courses.\n";
				return;
			}
			cout << "  --- All Courses ---\n";
			for (int i = 0; i < crsCount; i++) courses[i]->display();
		}
		void allocateCourseToTeacher(const string& code, const string& teacherName) {
			int ci = findCourseIdx(code);
			int ti = findTeacherIdx(teacherName);
			if (ci == -1 || ti == -1) {
				cout << "  [!] Course or Teacher not found.\n";
				return;
			}
			teachers[ti]->assignCourse(courses[ci]);
			cout << "  [*] " << teacherName << " assigned to " << code << "\n";
		}
		void deallocateCourseFromTeacher(const string& code, const string& teacherName) {
			int ci = findCourseIdx(code);
			int ti = findTeacherIdx(teacherName);
			if (ci == -1 || ti == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			teachers[ti]->deallocateCourse(courses[ci]);
			cout << "  [*] Deallocated.\n";
		}
		void unenrollStudentFromCourse(const string& rollNo, const string& code) {
			int si = findStudentRecursive(students, stuCount, rollNo);
			int ci = findCourseIdx(code);
			if (si == -1 || ci == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			*courses[ci] - students[si];               // operator- removes from course
			students[si]->removeCourse(courses[ci]);
			cout << "  [-] Student unenrolled by Admin.\n";
		}
		// ---- sutdent funcitons----
		void studentViewDetails(const string& rollNo) const {
			int idx = findStudentRecursive(students, stuCount, rollNo);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			students[idx]->display();
		}
		void studentEnroll(const string& rollNo, const string& code) {
			int si = findStudentRecursive(students, stuCount, rollNo);
			int ci = findCourseIdx(code);
			if (si == -1 || ci == -1) {
				cout << "  [!] Student or Course not found.\n";
				return;
			}
			*courses[ci] + students[si];               // operator+ enrolls in course
			students[si]->addCourse(courses[ci]);
			cout << "  [+] Enrolled " << students[si]->getName()
			     << " in " << courses[ci]->getName() << "\n";
		}
		void studentDropCourse(const string& rollNo, const string& code) {
			int si = findStudentRecursive(students, stuCount, rollNo);
			int ci = findCourseIdx(code);
			if (si == -1 || ci == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			*courses[ci] - students[si];               // operator- drops from course
			students[si]->removeCourse(courses[ci]);
			cout << "  [-] Dropped from " << courses[ci]->getName() << "\n";
		}
		void studentViewGrades(const string& rollNo) const {
			int idx = findStudentRecursive(students, stuCount, rollNo);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			students[idx]->viewGrades();
			int count = students[idx]->getCourseCount();
			if (count > 0) {
				int total = calcTotalMarksRecursive(students[idx]);
				cout << "  Average Marks: " << total / count << "\n";
			}
		}
		void studentViewTeachers(const string& rollNo) const {
			int si = findStudentRecursive(students, stuCount, rollNo);
			if (si == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			cout << "  Teachers of your courses:\n";
			for (int i = 0; i < students[si]->getCourseCount(); i++) {
				Course*  c = students[si]->getCourse(i);
				Teacher* t = c->getTeacher();
				cout << "    " << c->getName() << " -> "
				     << (t ? t->getName() : "Not Assigned") << "\n";
			}
		}
		void studentViewEnrolled(const string& rollNo) const {
			int idx = findStudentRecursive(students, stuCount, rollNo);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			students[idx]->viewEnrolledCourses();
		}
		void studentViewDropped(const string& rollNo) const {
			int idx = findStudentRecursive(students, stuCount, rollNo);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			students[idx]->viewDroppedCourses();
		}
		// ----teacher functions----

		void teacherViewDetails(const string& name) const {
			int idx = findTeacherIdx(name);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			teachers[idx]->display();
		}
		void teacherViewCourses(const string& name) const {
			int idx = findTeacherIdx(name);
			if (idx == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			teachers[idx]->viewAssignedCourses();
		}
		void teacherViewStudentsInCourse(const string& code) const {
			int ci = findCourseIdx(code);
			if (ci == -1) {
				cout << "  [!] Course not found.\n";
				return;
			}
			cout << "  Students in " << code << ":\n";
			for (int i = 0; i < courses[ci]->getEnrolledCount(); i++)
				cout << *courses[ci]->getEnrolled(i);
		}
		void teacherAssignMarks(const string& teacherName, const string& code,
		                        const string& rollNo, int marks) {
			int ti = findTeacherIdx(teacherName);
			int ci = findCourseIdx(code);
			int si = findStudentRecursive(students, stuCount, rollNo);
			if (ti == -1 || ci == -1 || si == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			teachers[ti]->assignMarks(courses[ci], students[si], marks);
			cout << "  [*] Marks assigned: " << marks << "\n";
		}
		void teacherFindTopStudent(const string& teacherName, const string& code) const {
			int ti = findTeacherIdx(teacherName);
			int ci = findCourseIdx(code);
			if (ti == -1 || ci == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			teachers[ti]->findTopStudent(courses[ci]);
		}
		void teacherGradeDistribution(const string& code) const {
			int ci = findCourseIdx(code);
			if (ci == -1) {
				cout << "  [!] Not found.\n";
				return;
			}
			courses[ci]->displayGradeDistribution();
		}
};

void readLine(string& buffer) { //a helper fucntion to get clean input stirngs ignoring the \n(enter)
	cin.ignore();
	getline(cin, buffer);
}

//ALL MENUS
void adminMenu(LMS& lms) {
	int choice;
	string s1, s2, s3;
	int    age;
	double salary;

	do {
		cout << "\n===== ADMIN MENU =====\n";
		cout << "1. Add Student\n2. Remove Student\n3. Update Student\n";
		cout << "4. View All Students\n5. Add Teacher\n6. Remove Teacher\n";
		cout << "7. View All Teachers\n8. Add Course\n9. Remove Course\n";
		cout << "10. View All Courses\n11. Assign Course to Teacher\n";
		cout << "12. Deallocate Course from Teacher\n13. Unenroll Student from Course\n";
		cout << "0. Back\nChoice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Name: ";
				readLine(s1);
				cout << "Age : ";
				cin >> age;
				cout << "Address: ";
				readLine(s2);
				cout << "Roll No: ";
				readLine(s3);
				{
					string dept;
					cout << "Dept: ";
					readLine(dept);
					lms.addStudent(s1, age, s2, s3, dept);
				}
				break;
			case 2:
				cout << "Roll No to remove: ";
				readLine(s1);
				lms.removeStudent(s1);
				break;
			case 3:
				cout << "Roll No to update: ";
				readLine(s1);
				lms.updateStudent(s1);
				break;
			case 4:
				lms.viewAllStudents();
				break;
			case 5:
				cout << "Name: ";
				readLine(s1);
				cout << "Age : ";
				cin >> age;
				cout << "Address: ";
				readLine(s2);
				cout << "Salary: ";
				cin >> salary;
				cout << "Dept: ";
				readLine(s3);
				lms.addTeacher(s1, age, s2, salary, s3);
				break;
			case 6:
				cout << "Teacher name to remove: ";
				readLine(s1);
				lms.removeTeacher(s1);
				break;
			case 7:
				lms.viewAllTeachers();
				break;
			case 8:
				cout << "Course Name: ";
				readLine(s1);
				cout << "Course Code: ";
				readLine(s2);
				lms.addCourse(s1, s2);
				break;
			case 9:
				cout << "Course Code: ";
				readLine(s1);
				lms.removeCourse(s1);
				break;
			case 10:
				lms.viewAllCourses();
				break;
			case 11:
				cout << "Course Code  : ";
				readLine(s1);
				cout << "Teacher Name : ";
				readLine(s2);
				lms.allocateCourseToTeacher(s1, s2);
				break;
			case 12:
				cout << "Course Code  : ";
				readLine(s1);
				cout << "Teacher Name : ";
				readLine(s2);
				lms.deallocateCourseFromTeacher(s1, s2);
				break;
			case 13:
				cout << "Roll No      : ";
				readLine(s1);
				cout << "Course Code  : ";
				readLine(s2);
				lms.unenrollStudentFromCourse(s1, s2);
				break;
		}
	} while (choice != 0);
}
//student menu
void studentMenu(LMS& lms) {
	string rollNo;
	cout << "Enter Roll No: ";
	readLine(rollNo);

	int    choice;
	string s1;
	do { //do while loop to display choices until user manually exits
		cout << "\n===== STUDENT MENU =====\n";
		cout << "1. View Personal Details\n2. Enroll in Course\n";
		cout << "3. View Final Grade\n4. View Teachers\n";
		cout << "5. View Enrolled Courses\n6. View Dropped Courses\n";
		cout << "7. Drop a Course\n0. Back\nChoice: ";
		cin >> choice;
		switch (choice) { //switch case statements to navigate in the menu
			case 1:
				lms.studentViewDetails(rollNo);
				break;
			case 2:
				cout << "Course Code: ";
				readLine(s1);
				lms.studentEnroll(rollNo, s1);
				break;
			case 3:
				lms.studentViewGrades(rollNo);
				break;
			case 4:
				lms.studentViewTeachers(rollNo);
				break;
			case 5:
				lms.studentViewEnrolled(rollNo);
				break;
			case 6:
				lms.studentViewDropped(rollNo);
				break;
			case 7:
				cout << "Course Code: ";
				readLine(s1);
				lms.studentDropCourse(rollNo, s1);
				break;
		}
	} while (choice != 0);
}
//teacher menu
void teacherMenu(LMS& lms) {
	string tname;
	cout << "Enter Teacher Name: ";
	readLine(tname);

	int    choice;
	string s1, s2;
	int    marks;
	do {
		cout << "\n===== TEACHER MENU =====\n";
		cout << "1. View Personal Details\n2. View Assigned Courses\n";
		cout << "3. View Students in Course\n4. Assign Marks\n";
		cout << "5. Find Top Student\n6. Grade Distribution\n0. Back\nChoice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				lms.teacherViewDetails(tname);
				break;
			case 2:
				lms.teacherViewCourses(tname);
				break;
			case 3:
				cout << "Course Code: ";
				readLine(s1);
				lms.teacherViewStudentsInCourse(s1);
				break;
			case 4:
				cout << "Course Code : ";
				readLine(s1);
				cout << "Student Roll: ";
				readLine(s2);
				cout << "Marks (0-100): ";
				cin >> marks;
				lms.teacherAssignMarks(tname, s1, s2, marks);
				break;
			case 5:
				cout << "Course Code: ";
				readLine(s1);
				lms.teacherFindTopStudent(tname, s1);
				break;
			case 6:
				cout << "Course Code: ";
				readLine(s1);
				lms.teacherGradeDistribution(s1);
				break;
		}
	} while (choice != 0);
}

// MAIN
//=======================================================================
int main() {
	LMS lms;
	// Demo data so you can test right away
	lms.addStudent("Ali Hassan",  20, "GIKI Hostel 1", "2025001", "SE");
	lms.addStudent("Sara Khan",   21, "GIKI Hostel 2", "2025002", "CS");
	lms.addStudent("Bilal Ahmed", 20, "GIKI Hostel 3", "2025003", "EE");

	lms.addTeacher("Dr. Khan", 45, "FCSE Block", 150000, "CS");
	lms.addTeacher("Prof. Ali", 38, "FCSE Block", 120000, "SE");

	lms.addCourse("Object Oriented Programming", "CS112");
	lms.addCourse("Data Structures",             "CS211");
	lms.addCourse("Digital Logic Design",        "EE101");

	lms.allocateCourseToTeacher("CS112", "Dr. Khan");
	lms.allocateCourseToTeacher("CS211", "Prof. Ali");

	lms.studentEnroll("2025001", "CS112");
	lms.studentEnroll("2025001", "CS211");
	lms.studentEnroll("2025002", "CS112");

	lms.teacherAssignMarks("Dr. Khan", "CS112", "2025001", 88);
	lms.teacherAssignMarks("Dr. Khan", "CS112", "2025002", 74);

	// Main login menu
	int role;
	do {
		cout << "\n=============================\n";
		cout << "  GIKI LMS - CS112 Assignment\n";
		cout << "=============================\n";
		cout << "Login As:\n";
		cout << "  1. Admin\n";
		cout << "  2. Student\n";
		cout << "  3. Teacher\n";
		cout << "  0. Exit\n";
		cout << "Choice: ";
		cin >> role;

		switch (role) {
			case 1:
				adminMenu(lms);
				break;
			case 2:
				studentMenu(lms);
				break;
			case 3:
				teacherMenu(lms);
				break;
			case 0:
				cout << "Goodbye!\n";
				break;
			default:
				cout << "Invalid choice.\n";
		}
	} while (role != 0);

	return 0;
}