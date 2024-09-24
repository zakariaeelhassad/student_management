#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 100

struct student {
    int s ;
    char thename[100];
    int theage;
};
 int numstudents = 0;


void addstudent(struct student students[]){
    printf("You chose to add a new STUDENT.\n");
    if(numstudents < MAX_STUDENT){

    students[numstudents].s = numstudents+1;
    printf("student:%d \n",students[numstudents].s);
    printf("name: ");
    scanf(" %[^\n]s",students[numstudents].thename);
    printf("age: ");
    scanf(" %d", &students[numstudents].theage);
    printf("student name is %s and the age is %d . \n",students[numstudents].thename,students[numstudents].theage);
    printf("student added successfully!\n\n");
    numstudents++;
    }
     else {
        printf("student limit reached. Cannot add more student.\n\n");
    }
}
void addmoltiplestudent(struct student students[]) {
    int moltiplestudents ;
    printf("how matsh student you want add :");
    scanf(" %d", &moltiplestudents);
    printf("You chose to add a new STUDENT.\n");
    if(numstudents < MAX_STUDENT){
        for(int i = 0; i < moltiplestudents; i++) {
            students[numstudents].s = numstudents+1;
            printf("student:%d \n",students[numstudents].s);
            printf("name: ");
            scanf(" %[^\n]s",students[numstudents].thename);
            printf("age: ");
            scanf(" %d", &students[numstudents].theage);
            printf("student name is %s and the age is %d . \n",students[numstudents].thename,students[numstudents].theage);
            printf("student added successfully!\n\n");
            numstudents++;
        }
    }
    else {
        printf("student limit reached. Cannot add more student.\n\n");
    }
}
void deletstudent(struct student students[]){
    int deletes;
    printf("Your choice is to delete a task:\n");
    printf("Which student do you want to delete: ");
    scanf("%d", &deletes);

    int found = 0;

    if (deletes <= 0 || deletes > numstudents) {
        printf("Invalid ID!\n");
    } else {
        for (int i = 0; i < numstudents; i++) {
            if (students[i].s == deletes) {
                for (int j = i; j < numstudents - 1; j++) {
                    students[j] = students[j + 1];
                }
                numstudents--;
                found = 1;
                printf("student %d deleted successfully!\n", deletes);
                break;
            }
        }
        if (!found) {
            printf("student with ID %d not found!\n", deletes);
        }
    }

}
void updatstudent(struct student students[]){
    printf("You chose to modify a student:\n");
    int modifys;

    do {
        printf("Enter the student ID to modify: ");
        scanf("%d", &modifys);
    } while (modifys <= 0 || modifys > numstudents);

    int modifyChoice;
    printf("Choose what to modify:\n");
    printf("1. name \n");
    printf("2. age\n");
    printf("Enter your choice: ");
    scanf("%d", &modifyChoice);

    while (modifyChoice < 1 || modifyChoice > 2) {
        printf("Invalid choice. Please enter a valid choice (1 or 2).\n");
        printf("Enter your choice: ");
        scanf("%d", &modifyChoice);
    }

    switch (modifyChoice) {
        case 1:
            printf("name : ");
            scanf(" %[^\n]s", students[numstudents-1].thename);
            break;
        case 2:
            printf("age: ");
            scanf("%d", &students[numstudents-1].theage);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("student updated successfully!\n\n");
}
void displaystudent(struct student students[]){
    int displaychoice ;
    int choicedisplay;
    printf("1. display to students : \n");
    printf("2. display 1 student : \n");
    printf("Enter your choice: ");
    scanf("%d", &choicedisplay);
    if (choicedisplay == 2) {
        printf("nomber the student you want display:");
        scanf("%d", &displaychoice);
        if (displaychoice <= 0 || displaychoice > numstudents) {
            printf("Invalid choice.\n");
        }
        else {
            for (int i = 0; i < displaychoice; i++) {
                if (students[i].s == displaychoice) {
                     printf("nomber the student %d name is %s and the age is %d . \n",displaychoice, students[i].thename,students[i].theage);
                }
            }
            return;
        }
    }
    else if (choicedisplay == 1) {
        for (int i = 0; i < numstudents; i++) {
            printf("nomber the student %d name is %s and the age is %d . \n",students[i].s, students[i].thename,students[i].theage);
        }
    }
}

void menu(){
    printf("Choose an option:\n");
    printf("1.add student \n");
    printf("2. add moltiple student \n");
    printf("3.delet student \n");
    printf("4.updat student \n");
    printf("5.display student \n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
}
int main()
{
    struct student students[MAX_STUDENT];
    int choice;
    do{
    menu();
    scanf("%d", &choice);
    switch(choice){
        case 1 :addstudent(students);
        break;
        case 2:addmoltiplestudent(students);
        break;
        case 3 :deletstudent(students);
        break;
        case 4:updatstudent(students);
        break;
        case 5:displaystudent(students);
        break;
        case 0 :printf("Exiting the program.\n");
                break;
        default :
            printf("hsdhd");
    }
    }while(choice != 0);

    return 0;
}

