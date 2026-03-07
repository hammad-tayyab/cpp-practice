//Task 2 (1) Recursion (Perfect Number program)
#include <iostream>
using namespace std;
//helping function to return the sum of the divisors usign recursion
int SumDivisors(int num , int currentNum)
{
	if(currentNum > num/2) // Base Case 
	{
		return 0;
	}
	if(num % currentNum == 0)//checking if the currentnumber is the factor of the num
	{
		return currentNum + SumDivisors(num, currentNum+1); //recursive call returning the factor with the call
	}
	else
	{
		return SumDivisors(num,currentNum + 1);//rescursive call
	}
}
bool IsPerfectNumber(int num)//boolean function
{
	if(num<=1)
	{
		return false;
	}
	return SumDivisors(num, 1) == num; //calling the recursive function and checking the condition
}
int main()
{
	int n;
	bool status = false;
	cout<<"====Perfect Number====\n";
	cout<<"Enter the number you want to check: ";
	cin>>n;
	status = IsPerfectNumber(n); //function call
	//displaying the result
	if (status)
	{
		cout<<n<<" is a perfect number";
	}
	else cout<<n<<" is not a perfect number";
	
	return 0;
}