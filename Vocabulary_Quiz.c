#include <stdio.h>
#include <stdlib.h>


char question[200], line[200];  //line for the line fetched from a file.
char ans, ans_u;  //ans for correct answer and ans_u for user's answer.

//This function parse the line and separate the question, answer and stores them in global variable question and ans
void getQuestion(char *line){
    int i;
    for(i=0; i<strlen(line)-1; i++){
        if (line[i] != '<'){
            question[i] = line[i];
        }
        else{
            question[i] = '\0';
            break;
        }
    }
    ans  = line[strlen(line)-4];
}

//This function will fetch a random line from the file Quiz.txt
//The file must store all the questions and answers in specific pattern.
void getWord()
{
  int random, word;
  time_t t; //It will be used to generate random number

  FILE *fp;
  fp = fopen("Quiz.txt", "r");
  if (NULL == fp){
    printf("file can't be opened \n");
  }

  srand((unsigned)time(&t));  //Time is added as seed to initialized rand() function.
  random = rand() % 500;  //It will generate a random number between 1 to 499. (According to words available in Quiz.txt
  word = 1;

  while (fgets(line, 200, fp) != NULL){ //Fetch the line as per random number
    word = word + 1;
    if (word >= random)
    {
      fclose(fp);
      break;
    }
  }
}

int main()
{
  int choice, correct, wrong, total;
  correct = 0;
  wrong = 0;
  total = 0;
  while (1){

    system("cls");
    printf("\n\n This program is created by Radhi Patel (22CED105)\n\n\n");
    printf("----------  Welcome to the Vocabulary Quiz  ----------\n\n");

    printf(" 1.  To play vocabulary quiz\n");
    printf(" 0.  To Exit\n");
    printf(" Enter your choice :");
    scanf("%d", &choice);

    if (choice == 1){
        New_word:  //This label is used to repeat for next word
        system("cls");

        getWord();      //This will fetch a line from the Quiz.txt
        total = total + 1;
        getQuestion(line);  //This will separate question and answer.
        printf("\n\n\n Find the similar of:\n\n %d.    %s",total, question);
        printf("\n\n Enter your choice : ");
        ans_u = toupper(getch()); //User's answer will be stored in this global variable.

        if ( ans_u == ans){
            printf("\n\n Right\n");
            correct = correct + 1;
        }
        else {
            printf("\n\n Wrong. Correct Answer is :%c\n", ans);
            wrong = wrong + 1;
        }

        printf("\n\n Score : Correct-%d     wrong-%d\n\n", correct, wrong);

        printf("\n\n Press '1' for next question and 'Any other key' to exit : ");
        choice = 0;
        scanf("%d", &choice);


        if (choice == 1) {
            goto New_word;
        }
        else{
            break;
        }
    }
    else if (choice == 0)
    {
      break;
    }
  }
}
