#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>   // for std::shuffle
#include <random>      // for std::random_device and std::mt19937
#include <ctime>
#include <sstream>

using namespace std;

// Function to split string by a delimiter
vector<string> split(const string& s, char delimiter) 
{
    vector<string> tokens;
    string token;
    stringstream tokenStream(s);

    while (getline(tokenStream, token, delimiter)) 
    {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

// Function to read questions from a .txt file
vector<string> readQuestionsFromFile(const string& filePath) 
{
    ifstream file(filePath);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Split the questions using the '?' delimiter

    return split(content, '?');
}

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

// Function to generate the question paper sets
void generateQuestionPapers(const vector<string>& questionBank, int numSets, int questionsPerSet) 
{
    // Use random_device and mt19937 for better randomness
    random_device rd;
    mt19937 g(rd());

    for (int setNum = 1; setNum <= numSets; ++setNum) 
    {
        vector<string> shuffledQuestions = questionBank;
        shuffle(shuffledQuestions.begin(), shuffledQuestions.end(), g);

        // Create SETx.txt
        ofstream outFile("SET" + to_string(setNum) + ".txt");

        outFile << "Question Paper - SET " << setNum << "\n\n";
        for (int i = 0; i < questionsPerSet && i < shuffledQuestions.size(); ++i) 
        {
            outFile << i + 1 << ". " << shuffledQuestions[i] << "\n";
        }

        outFile.close();
        cout << "SET" << setNum << ".txt generated with " << questionsPerSet << " questions.\n";
    }
}

int main() 
{
    int choice, totalQuestions = 20, numSets, questionsPerSet;
    vector<string> questionBank;

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
        string filePath = "C:\\Users\\Robin\\OneDrive\\Desktop\\Professional\\Question_Paper_Set_Creator\\QuestionpaperInputOutput\\ques.txt";
        /*cout << "Enter the file path: ";
        cin >> filePath;*/
        questionBank = readQuestionsFromFile(filePath);
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
    generateQuestionPapers(questionBank, numSets, questionsPerSet);

    return 0;
}
