# Question Paper Set Creator

## Overview
This project is a C++ application that helps generate multiple sets of question papers from a question bank. It allows users to either manually input questions or read them from a file, and then generates randomized sets of questions for use in exams or quizzes.

## Features
- Input questions manually or read from a file
- Specify the total number of questions, number of sets, and questions per set
- Ensures no set exceeds the available number of questions
- Outputs randomized question sets

## How It Works
1. **Choose Input Method:**
   - The program prompts the user to choose between manual question entry or reading from a file.
2. **Input Questions:**
   - If manual, the user enters each question one by one.
   - If from file, the program reads questions from a specified file path (default is `input_ques/questions.txt`).
3. **Validation:**
   - The program checks if the number of questions provided meets the required total.
4. **Set Generation:**
   - The user specifies how many sets to generate and how many questions per set.
   - The program ensures the number of questions per set does not exceed the total available.
5. **Output:**
   - The program generates the specified number of sets, each containing a randomized selection of questions.

## File Structure
- `src/main.cpp`: Main application logic and user interaction
- `inc/fileHandler.hpp`: Header for file handling utilities
- `src/fileHandler.cpp`: Implementation of file handling and set generation
- `input_ques/questions.txt`: Default input file for questions

## Usage
1. **Build the Project:**
   - Use CMake to configure and build the project.
2. **Run the Application:**
   - Follow the prompts to input questions and generate sets.

## Customization
- You can change the default number of questions or file paths in `main.cpp`.
- To use your own question bank, replace the contents of `input_ques/questions.txt`.

## Clone repo

To clone this repository, run:

```bash
git clone https://github.com/Robin005cr/Question_Paper_Set_Creator.git
```


