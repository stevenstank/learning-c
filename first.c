#include <stdio.h>

int main()
{
    char questions[][100] = {
        "What is the capital of France?",
        "What is 2 + 2?",
        "What is the largest planet in our solar system?"
    };

    char options[][100] = {
        "A) Paris\n B) London\n C) Berlin\n D) Madrid\n",
        "A) 3\n B) 4\n C) 5\n D) 6\n",
        "A) Earth\n B) Mars\n C) Jupiter\n D) Saturn\n"
    };

    char answers[][100] = {
        "Paris",
        "4",
        "Jupiter"
    };

    char user_answer1[100];
    char user_answer2[100];
    char user_answer3[100];

    printf("Quiz Time!\n");
    printf("%s\n", questions[0]);
    printf("%s\n", options[0]);
    scanf("%s", &user_answer1);
    if(user_answer1 == answers[0]){
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %s\n", answers[0]);
    }

    printf("%s\n", questions[1]);
    printf("%s\n", options[1]);
    scanf("%s", &user_answer2);
    if(user_answer2 == answers[1]){
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %s\n", answers[1]);
    }

    printf("%s\n", questions[2]);
    printf("%s\n", options[2]);
    scanf("%s", &user_answer3);
    if(user_answer3 == answers[2]){
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %s\n", answers[2]);
    }

    printf("Quiz Over!\n");
    printf("Your total score is: \n")
    return 0;

}