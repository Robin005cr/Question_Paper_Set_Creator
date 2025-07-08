/*
 * project   : https://github.com/Robin005cr/Question_Paper_Set_Creator
 * file name : alarm.hpp
 * author    : Robin CR
 * mail id   : robinchovallurraju@gmail.com
 * portfolio : https://robin005cr.github.io/
 *
 * Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
 * Suggestions for improvements or better methods are always welcome and appreciated.
 * I value constructive feedback and aim to continuously improve the quality of the work.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>   // for std::shuffle
#include <ctime>
#include <sstream>
#include <filesystem>
#include "fileHandler.hpp"

using namespace std;
namespace fs = std::filesystem;


// Function to take questions as direct input from the user
vector<string> inputQuestionsFromUser(int totalQuestions)
{
    vector<string> questions;
    string question;

    cout << "Enter " << totalQuestions << " questions (end each question with Enter):\n";
    cin.ignore(); // To clear the input buffer

    for (int i = 0; i < totalQuestions; ++i)
    {
        cout << "Question " << i + 1 << ": ";
        getline(cin, question);
        if (!question.empty()) {
            questions.push_back(question);
        }
    }

    return questions;
}

int main() 
{
    int choice, totalQuestions = 20, numSets, questionsPerSet;
    vector<string> questionBank;
    FileHandler handler;
    cout << "Choose input method:\n";
    cout << "1. Insert questions manually\n";
    cout << "2. Read questions from file\n";
    cout << "Enter your choice (1/2): ";
    cin >> choice;

    if (choice == 1) 
    {
        // Manually insert questions
        questionBank = inputQuestionsFromUser(totalQuestions);
    }
    else if (choice == 2) 
    {
        // Read questions from a file
#ifdef _WIN32
        string filePath = "C:/Users/ASUS/Desktop/Question_Paper_Set_Creator/input_ques/questions.txt";
#else
        string filePath = "/home/username/Question_Paper_Set_Creator/input_ques/questions.txt";
#endif


        /*cout << "Enter the file path: ";
        cin >> filePath;*/
        questionBank = handler.readQuestionsFromFile(filePath);
    }
    else 
    {
        cout << "Invalid choice!";
        return 1;
    }

    if (questionBank.size() < totalQuestions) 
    {
        cout << "Error: Less than " << totalQuestions << " questions found!\n";
        return 1;
    }

    cout << "Enter the number of sets to generate: ";
    cin >> numSets;

    cout << "Enter the number of questions per set: ";
    cin >> questionsPerSet;



    if (questionsPerSet > totalQuestions) 
    {
        cout << "Error: Question count exceeds available questions!\n";
        return 1;
    }

    // Generate the question papers
    handler.generateQuestionPapers(questionBank, numSets, questionsPerSet);

    return 0;
}
