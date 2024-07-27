# Vocabulary Quiz Program

## Overview

This C program is a simple vocabulary quiz game that reads questions and answers from a text file and quizzes the user. The program fetches a random line from the `Quiz.txt` file, displays a question, and prompts the user to input an answer. The program then evaluates the answer and provides feedback.

## Features

- **Random Question Generation**: Fetches a random question from `Quiz.txt`.
- **User Interaction**: Prompts the user to answer questions and provides feedback on their answers.
- **Score Tracking**: Keeps track of the number of correct and incorrect answers.
- **Repeat or Exit**: Allows the user to either proceed to the next question or exit the program.

## File Structure

- `Quiz.txt`: A text file containing questions and answers in a specific format. Each line should have the question followed by the correct answer in angle brackets (`<answer>`). For example:
  

- `vocab_quiz.c`: The source code for the quiz program.

## Compilation and Execution

### Prerequisites

To compile and run this program, you need a C compiler such as `gcc`.

### Building and Running the Program

1. **Clone the repository** (if you haven’t already):

 ```bash
 git clone https://github.com/your-username/vocabulary-quiz.git
 ```
2. **Navigate to the project directory:**
   ```bash
   cd vocabulary-quiz
   ```
3. **Compile the code:**
   ```bash
   gcc -o vocab_quiz vocab_quiz.c
   ```
  
