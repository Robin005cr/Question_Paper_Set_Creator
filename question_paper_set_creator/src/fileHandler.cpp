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
#include <algorithm> // for std::shuffle
#include <random>
#include <sstream>
#include <string>
#include "fileHandler.hpp"
using namespace std;

// Function to split string by a delimiter
vector<string> FileHandler::split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    stringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter))
    {
        if (!token.empty())
        {
            tokens.push_back(token);
        }
    }
    return tokens;
}

// Function to read questions from a .txt file
vector<string> FileHandler::readQuestionsFromFile(const string &filePath)
{
    ifstream file(filePath);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Split the questions using the '?' delimiter

    return split(content, '?');
}
// Function to generate the question paper sets
void FileHandler::generateQuestionPapers(const vector<string> &questionBank, int numSets, int questionsPerSet)
{
    // Use random_device and mt19937 for better randomness
    random_device rd;
    mt19937 g(rd());
    string fileType;
    cout << "Enter File type(txt or csv):" << endl;
    cin >> fileType;

    for (int setNum = 1; setNum <= numSets; ++setNum)
    {
        vector<string> shuffledQuestions = questionBank;
        shuffle(shuffledQuestions.begin(), shuffledQuestions.end(), g);

        // Create SETx.txt
        ofstream outFile("SET" + to_string(setNum) + "." + fileType);

        outFile << "Question Paper - SET " << setNum << "\n\n";
        for (int i = 0; i < questionsPerSet && i < shuffledQuestions.size(); ++i)
        {
            outFile << i + 1 << ". " << shuffledQuestions[i] << "\n";
        }

        outFile.close();
        cout << "SET" << setNum << "." << fileType << "generated with " << questionsPerSet << " questions.\n";
    }
}