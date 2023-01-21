#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//deposit function
void deposit(){
    double count;
    const double interest = 0.05;
    double savings;
    int months;
    int check;

    //savings input
    printf("Input savings : ");
    check = scanf("%lf", &savings);
    printf("\n");

    //savings input validation
    while(savings <= 0 || check !=1){
        if(savings <= 0){
            system("CLS");
            printf("Please enter a valid amount.\n\n");
            printf("Input savings : ");
            check = scanf("%lf", &savings);
            fflush(stdin);
            printf("\n");
                while(check != 1){
                    system("CLS");
                    printf("Savings must be a number!\n\n");
                    printf("Input savings : ");
                    check = scanf("%lf", &savings);
                    fflush(stdin);
                    printf("\n");
                }
        }
        else if(check != 1){
            system("CLS");
            printf("Savings must be a number!\n\n");
            printf("Input savings : ");
            check = scanf("%lf", &savings);
            fflush(stdin);
            printf("\n");
        }
    }

    system("CLS");
    //month input
    printf("Input number of month(s) : ");
    check = scanf("%d", &months);
    printf("\n");

    //months input validation
    while(check != 1 || months <= 0 || months > 12){
        if(months <= 0 || months > 12){
            system("CLS");
            printf("Please enter a valid number of months!(1-12)\n\n");
            printf("Input number of month(s) : ");
            check = scanf("%d", &months);
            fflush(stdin);
            printf("\n");
                while(check != 1){
                system("CLS");
                printf("Number of months must be a number!\n\n");
                printf("Input number of month(s) : ");
                check = scanf("%d", &months);
                fflush(stdin);
                printf("\n");
                }
        }
        else if(check != 1){
            system("CLS");
            printf("Number of months must be a number!\n\n");
            printf("Input number of month(s) : ");
            check = scanf("%d", &months);
            fflush(stdin);
            printf("\n");
            while(months <= 0 || months > 12){
                system("CLS");
                printf("Please enter a valid number of months!(1-12)\n\n");
                printf("Input number of month(s) : ");
                check = scanf("%d", &months);
                fflush(stdin);
                printf("\n");
            }
        }
    }
    
    FILE * record = fopen("records.txt","w");

    system("CLS");
    printf("Initial savings : Rp%.3lf\n", savings);
    printf("-----------------------------\n");
    //writing into file
    for(int i = 1; i<=months ; i++){
        count = savings * interest/12 * 0.80;
        savings = savings + count;
        printf("Month %d: Rp%.3lf\n", i, savings);
        fprintf(record, "Month %d: Rp%.3lf\n", i, savings);
    }

    printf("-----------------------------");
    printf("\nRecords exported as records.txt");

    fclose(record);

}


void savings(){

    

}

int main(){
    int methodChoice;
    int check;

        //menu
        printf("\n1. Deposit \n2. Planned savings\n");
        printf("\nEnter number : ");
        check = scanf("%d", &methodChoice);
        printf("\n");

        //menu input validation
        while(methodChoice <=0 || methodChoice > 2 || check != 1){
            system("CLS");
            printf("Please enter a valid number (1 or 2)\n\n");
            printf("1. Deposit \n2. Planned savings\n");
            printf("\nEnter number : ");
            scanf("%d", &methodChoice);
            fflush(stdin);
        }

    //calling deposit function
    if(methodChoice == 1){
        system("CLS");
        deposit();
    }
    //calling Planned Savings function
    else if(methodChoice == 2){
        printf("Planned savings func\n");
    }

    return 0;
}