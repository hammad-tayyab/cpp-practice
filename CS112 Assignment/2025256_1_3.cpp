//Task 3 (MCQs)
#include <iostream>
using namespace std;
// Function to ask a question
bool askQuestion(string question, string options[4], char correctAnswer, int questionNum)
{
    char userChoice; // store user's answer
    //diplaying the question
    cout << "Question " << questionNum << ":" << endl;
    cout << question << endl;
    cout << "a. " << options[0] << endl;
    cout << "b. " << options[1] << endl;
    cout << "c. " << options[2] << endl;
    cout << "d. " << options[3] << endl;
    cout << "Your answer (a, b, c, or d): ";
    cin >> userChoice;//getting input from the user
    // convering input to lowercase to handle uppercase inputs
    userChoice = tolower(userChoice);
    // checking the answer of teh user
    if (userChoice == correctAnswer)
    {
        cout << "Correct!" << endl << endl;
        return true;
    }
    else
    {
        cout << "Incorrect!" << endl << endl;
        return false;
    }
}

int main()
{
    char playAgain;

    // questions
    string questions[20] =
    {
        "What is the capital of France?",
        "In which year did World War II end?",
        "What is the largest planet in our solar system?",
        "Who wrote 'Romeo and Juliet'?",
        "What is the capital of Japan?",
        "Which ocean is the largest?",
        "What is the currency of Australia?",
        "Who was the first President of the United States?",
        "What is the main ingredient in guacamole?",
        "In which year did the Titanic sink?",
        "What is the largest mammal on Earth?",
        "Who painted the Mona Lisa?",
        "What is the national flower of Japan?",
        "Which planet is known as the 'Red Planet'?",
        "What is the largest desert in the world?",
        "Who wrote 'To Kill a Mockingbird'?",
        "What is the capital of Canada?",
        "Which element has the chemical symbol 'H'?",
        "What is the largest organ in the human body?",
        "Which famous scientist developed the theory of relativity?"
    };

    // options
    string options[20][4] =
    {
        {"Berlin", "Madrid", "Paris", "Rome"},
        {"1943", "1945", "1948", "1950"},
        {"Venus", "Mars", "Jupiter", "Saturn"},
        {"Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain"},
        {"Beijing", "Seoul", "Tokyo", "Bangkok"},
        {"Indian Ocean", "Atlantic Ocean", "Pacific Ocean", "Arctic Ocean"},
        {"Euro", "Dollar", "Australian Dollar", "Peso"},
        {"Thomas Jefferson", "George Washington", "Abraham Lincoln", "John Adams"},
        {"Tomatoes", "Onions", "Avocado", "Peppers"},
        {"1910", "1912", "1915", "1920"},
        {"Elephant", "Blue Whale", "Giraffe", "Polar Bear"},
        {"Vincent van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Claude Monet"},
        {"Rose", "Tulip", "Cherry Blossom", "Orchid"},
        {"Jupiter", "Venus", "Saturn", "Mars"},
        {"Sahara Desert", "Gobi Desert", "Arabian Desert", "Antarctic Desert"},
        {"J.K. Rowling", "Ernest Hemingway", "Harper Lee", "F. Scott Fitzgerald"},
        {"Ottawa", "Toronto", "Vancouver", "Montreal"},
        {"Hydrogen", "Helium", "Carbon", "Oxygen"},
        {"Heart", "Liver", "Skin", "Lungs"},
        {"Isaac Newton", "Galileo Galilei", "Albert Einstein", "Stephen Hawking"}
    };

    // correct answers
    char answers[20] =
    {
        'c', 'b', 'c', 'b', 'c', 'c', 'c', 'b', 'c', 'b',
        'b', 'b', 'c', 'd', 'd', 'c', 'a', 'a', 'c', 'c'
    };
    do
    {
        int score = 0; 
        
        // Loop 
        for (int i = 0; i < 20; i++)
        {
            // Call askQuestion
            if (askQuestion(questions[i], options[i], answers[i], i + 1))
            {
                score++;
            }
        }

        // Display final score
        cout << "Overall Score: " << score << " out of 20" << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
        system("cls");//using for clearing the screen

    }
    while (tolower(playAgain) == 'y'); // repeat if user enters 'y'

    return 0;
}