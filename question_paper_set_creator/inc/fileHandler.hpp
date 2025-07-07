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
#include<vector>
#include<string>
using namespace std;
class FileHandler{
    public:
        vector<string> split(const string &s, char delimiter);
        vector<string> readQuestionsFromFile(const string &filePath);
        void generateQuestionPapers(const vector<string> &questionBank, int numSets, int questionsPerSet);
};
