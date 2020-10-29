#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <limits.h>


void printGrades (FILE *fp, int start_position){
    int score = 0;
    float total_score = 0;
    int buffer = 3;
    int max = INT_MIN;
    const int NUMBER_OF_STUDENTS = 10;

    fseek (fp, start_position, SEEK_SET);
    while (fscanf (fp, "%d", &score) == 1){
        buffer++;
        if (buffer == 4){
            total_score += score;
            buffer = 0;
            if (score > max) max = score;
        }
    }
    switch (start_position){
        case 0:
            printf("Highest score on Chapter 1 HW 1: %d\n", max);
            printf("Average score on Chapter 1 HW 1: %f\n",total_score/NUMBER_OF_STUDENTS);
            break;
        case 3:
            printf("Highest score on Chapter 1 HW 2: %d\n", max);
            printf("Average score on Chapter 1 HW 2: %f\n",total_score/NUMBER_OF_STUDENTS);
            break;
        case 6:
            printf("Highest score on Chapter 2 HW 1: %d\n", max);
            printf("Average score on Chapter 2 HW 1: %f\n",total_score/NUMBER_OF_STUDENTS);
            break;
        case 9:
            printf("Highest score on Chapter 2 HW 2: %d\n", max);
            printf("Average score on Chapter 2 HW 2: %f\n",total_score/NUMBER_OF_STUDENTS);
            break;

        default:
            printf("Invalid Grade\n");
    }
    fclose (fp);
}


int main(int argc, char* argv[]){
    FILE *fp = fopen ("quiz_grades.txt", "r");

    if (fp == NULL){
        perror ("Error");
        exit (1);
    }
    int status;

    int manager1, manager2;
    int worker1, worker2, worker3, worker4;

    manager1 = fork();
    if (manager1 == 0){
        worker1 = fork();
        if (worker1 == 0){
            printGrades(fp, 0);
        }else{
            waitpid (worker1, &status, 0);
            worker2 = fork();
            if (worker2 == 0){
                printGrades (fp, 3);
            }else{
                waitpid (worker2, &status, 0);
            }
        }
    }else{
        waitpid (manager1, &status, 0);
        manager2 = fork();
        if (manager2 == 0){
            worker3 = fork();
            if (worker3 == 0){
                printGrades (fp, 6);
            }else{
                waitpid (worker3, &status, 0);
                worker4 = fork ();
                if (worker4 == 0){
                    printGrades (fp, 9);
                }else{
                    waitpid (worker4, &status, 0);
                }
            }
        }else{
            waitpid (manager2, &status, 0);
        }
    }





    return 0;
}
