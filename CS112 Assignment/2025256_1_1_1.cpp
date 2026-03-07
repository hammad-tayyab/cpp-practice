//Task1  String and array manipulation 1.(removing the sentence)
#include <iostream>
using namespace std;
int Length(char *arr)
{
    int len = 0;
//checking if the loop moved towards the end of the array    
    while (arr[len] != '\0')//using '\0' to check the end of arr
        len++;
    return len;
}
char* removeSentence(char* Para, char* input)
{
    int lenPara = Length(Para);
    int lenInput = Length(input);

    int index = -1;
//finding the starting index of the input para
    for (int i = 0; i <= lenPara - lenInput; i++) 
    {
        int j;
//checks for all the characters of the input        
        for (j = 0; j < lenInput; j++)
        {
//if any character doesnt match the loop breaks        	
            if (Para[i + j] != input[j])
                break;
        }
//when input para's index is found then assign the index
        if (j == lenInput)
        {
            index = i;
            break;
        }
    }
//when index is found then shifting the charater array to the left
    if (index != -1)
    {
        for (int i = index; i <= lenPara - lenInput; i++)
        {
            Para[i] = Para[i + lenInput];
        }
    }
    else
    {
    	cout<<"\nError: Input paragraph was not found in the paragraph\n";
	}

    return Para;
}

int main()
{
//defualt para	
	
    char paragraph[500] = "I am currently studying OOP course. I hope to pass it. I might fail.";
    char input[500],choice;
    cout<<"Defualt paragraph\n";
    cout<<paragraph<<endl;
    cout<<"Do you want to enter your own paragraph (y/n): ";
    cin>>choice;
    cin.ignore(); // using so that remove the conflict of getting the input
    if (choice == 'y' || choice == 'Y')
    {
        cout<<"\nEnter paragraph:"<<endl;
    	cin.getline(paragraph, 500);//getline is used to get all the characters in a single line
	}

    cout<<"Enter sentence to remove:"<<endl;
    cin.getline(input, 500);
//calling the function
    removeSentence(paragraph, input);
    cout<<"\nUpdated paragraph:"<<endl;
    cout<<paragraph;
    return 0;
}