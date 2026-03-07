//task 1 -2- substring of the circular array
#include <iostream>
using namespace std;

int Length(char* arr)//length function
{
    int len = 0;
    while (arr[len] != '\0')
        len++;
    return len;
}

bool FindSubString(char* Str, char* substr, int &start, int &end)
{
    int n = Length(Str);
    int m = Length(substr);

    // if substring is longer than string it cannot exist as a substring
    if (m > n)
	{
        start = -1;
        end = -1;
        return false;
    }

    for (int i = 0; i < n; i++)
	{
        int j;
        // Check if substr matches
        for (j = 0; j < m; j++)
		{
            // handling circular wrapping
            if (Str[(i + j) % n] != substr[j]) break;
        }

        // If the entire substring was matched
        if (j == m) 
		{
            start = i;
            end = (i + m - 1) % n;//again cirular mapping to find the index properly 
            return true;
        }
    }

    // No match found
    start = -1;
    end = -1;
    return false;
}
int main()
{
	int start = -1 , end = -1;
	char Str[100] , SubStr[100];//initializing the char arrays and variables
	cout<<"Enter the main circular string: ";
	cin.getline(Str , 100);//getline for getting all the input in a single line
	cout<<"Enter the circular substring: ";
	cin.getline(SubStr,100);
	bool result = FindSubString(Str, SubStr, start,end);//Calling the function
	if(result)	cout<<"\nOutput:\nReturn True\nStarting index "<<start<<"\nEnding index "<<end;
	else	cout<<"\nOutput:\nReturn False";
	return 0;
}