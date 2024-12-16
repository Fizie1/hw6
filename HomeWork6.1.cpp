#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string word;

    // Prompt user for input
    cout << "Enter a word (5 or 6 characters): ";
    cin >> word;

    // Check number of characters 
    if (word.length() == 5 || word.length() == 6)  
    {
        // Reverse the word
        string reversedWord = "";
        for (int i = word.length() - 1; i >= 0; i--)
        {
            reversedWord += word[i];
        }

        // Print the reversed word
        cout << "Reversed word: " << reversedWord << endl;

        // Check if the word is a palindrome 
        bool isPalindrome = true;
        for (int i = 0; i < word.length() / 2; i++)
        {
            // Compare letters in lower case
            if (tolower(word[i]) != tolower(word[word.length() - i - 1]))
            {
                isPalindrome = false;
                break;
            }
        }

        // Print whether the word is a palindrome
        if (isPalindrome)
        {
            cout << word << " is a palindrome." << endl;
        }
        else
        {
            cout << word << " is not a palindrome." << endl;
        }

        // Write the word to the file "palindrome_word_checker.txt"
        ofstream outFile("palindrome_word_checker.txt", ios::app);  
        if (outFile.is_open())
        {
            outFile << word << endl;
            outFile.close();
            cout << "The word has been written to palindrome_word_checker.txt." << endl;
        }
        else
        {
            cout << "Error opening the file!" << endl;
        }

    }
    else
    {
        cout << "Your word doesn't fit the condition. It should be 5 or 6 characters long." << endl;
    }

    return 0;  
}
