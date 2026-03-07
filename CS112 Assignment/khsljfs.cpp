# include <iostream>
using namespace std;

class Test {
	int x;
	public:
		
		Test(int a = 0){
			x= a;
			cout<<"C";	
		}
		
		Test (const Test &t)
		{
			x = t.x;
			cout<<"CC";	
		}
		~Test(){
			cout<<"D";
		}
};
int main(){
	Test t1(10);
	Test t2 = t1;
	Test t3;
	t3=t1;
	return 0;
}