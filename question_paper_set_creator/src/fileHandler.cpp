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
    if (questionBank.empty()) {
        cerr << "Question bank is empty. Aborting generation.\n";
        return;
    }

    string fileType;
    cout << "Enter file type (txt or csv): ";
    cin >> fileType;

    // Validate file type
    if (fileType != "txt" && fileType != "csv") {
        cerr << "Invalid file type. Please enter 'txt' or 'csv'.\n";
        return;
    }

    // Adjust if more questions are requested than available
    if (questionsPerSet > questionBank.size()) {
        cout << "Only " << questionBank.size() << " questions available. Reducing questions per set to match.\n";
        questionsPerSet = questionBank.size();
    }

    random_device rd;
    mt19937 g(rd());

    for (int setNum = 1; setNum <= numSets; ++setNum)
    {
        vector<string> shuffledQuestions = questionBank;
        shuffle(shuffledQuestions.begin(), shuffledQuestions.end(), g);

        string fileName = "SET" + to_string(setNum) + "." + fileType;
        ofstream outFile(fileName);

        if (!outFile.is_open()) {
            cerr << "Failed to create file: " << fileName << "\n";
            continue;
        }

        if (fileType == "csv") {
            outFile << "Question Number,Question\n";
            for (int i = 0; i < questionsPerSet; ++i) {
                outFile << i + 1 << ",\"" << shuffledQuestions[i] << "\"\n";
            }
        }
        else { // txt
            outFile << "Question Paper - SET " << setNum << "\n\n";
            for (int i = 0; i < questionsPerSet; ++i) {
                outFile << i + 1 << ". " << shuffledQuestions[i] << "\n";
            }
        }

        outFile.close();
        cout << "SET" << setNum << "." << fileType << " generated with " << questionsPerSet << " questions.\n";
    }
}