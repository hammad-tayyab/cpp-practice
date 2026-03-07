//Task 2 (2) (vowel calculator in a string)
#include <iostream>
using namespace std;
int findVowels(char* str)
{
	if (*str == '\0') //base case
	{
		return 0;
	}
	//checking whether the character belongs to the vowels
	bool isVowel = (*str == 'a' ||*str == 'A'||*str == 'e'||*str == 'E' ||*str == 'i' ||*str == 'I' ||*str == 'o' ||*str == 'O' ||*str == 'u' ||*str == 'U');
	
	return isVowel + findVowels(str + 1); //recusion call with the boolean value(0 or 1) depending on the result
}
int main ()
{
	int vowels = 0;
	char arr[200];//initializing the char array
	cout<<"Enter the string to check: ";
	cin.getline(arr,200); //getline to get all the charcters in the line.
	vowels = findVowels(arr);
	cout<<"Number of Vowels : "<<vowels;//diplaying the result
	return 0;
}