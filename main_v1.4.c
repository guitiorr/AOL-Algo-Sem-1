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
    printf("Initial savings : Rp%.2lf\n", savings);
    printf("(5%% interest)\n");
    printf("-----------------------------\n");
    //writing into file
    for(int i = 1; i<=months ; i++){
        count = savings * (interest/12) * 0.80;
        savings = savings + count;
        printf("Month %d: Rp%.2lf\n", i, savings);
        fprintf(record, "Month %d: Rp%.2lf\n", i, savings);
    }

    printf("-----------------------------");
    printf("\nRecords exported as records.txt");

    fclose(record);

}

//month input validation for savings module
int months_savings_validation(month, c){

    while(c !=1 || month < 12 || month >= 120){
        if(c !=1){
            system("CLS");
            printf("Please input an integer!\n\n");
            printf("Input months: ");
            c = scanf("%d", &month);
            fflush(stdin);
            while(month < 12 || month >= 120){
                system("CLS");
                printf("Please input a valid number! (12-119)\n\n");
                printf("Input months: ");
                c = scanf("%d", &month);
                fflush(stdin);
            }
        }
        else if(month < 12 || month >= 120){
            system("CLS");
            printf("Please input a valid number! (12-119)\n\n");
            printf("Input months: ");
            c = scanf("%d", &month);
            fflush(stdin);
            while(c != 1){
                system("CLS");
                printf("Please input an integer!\n\n");
                printf("Input months: ");
                c = scanf("%d", &month);
                fflush(stdin);
            }
        }
    }

    return month;
}

double savings_calculation(){




}

//savings module
void savings(){
    double interest;
    int months;
    double balance;
    int check;

    //input balance
    printf("Input monthly deposit : ");
    check = scanf("%lf", &balance);

    //input validation
    while(check != 1 || balance <= 0){
        system("CLS");
        printf("Please input a valid number!\n");
        printf("\nInput monthly deposit : ");
        check = scanf("%lf", &balance);
        fflush(stdin);
    }

    //input months
    system("CLS");
    printf("Please input months, minimum of 12 and maximum of 119.\n");
    printf("Input months : ");
    check = scanf("%d", &months);

    months = months_savings_validation(months, check);

    printf("validasi month sukses\n");
    printf("return value months savings : %d\n", months);

    if(balance < 1000000){
        printf("uang dibawah 1 juta\n");
        if(months >= 12 && months <= 36){
            interest = 0.01;
            printf("1 persen\n");
        }
        else if(months > 36 && months <= 60){
            interest = 0.012;
            printf("1,2 persen\n");
        }
        else if(months > 60 && months <= 120){
            interest = 0.015;
            printf("1,5 persen\n");
        }
    }
    else if(balance >= 1000000){
        printf("uang 1 juta keatas\n");
        if(months >= 12 && months <= 36){
            interest = 0.012;
            printf("1,2 persen\n");
        }
        else if(months > 36 && months <= 60){
            interest = 0.015;
            printf("1,5 persen\n");
        }
        else if(months > 60 && months <= 120){
            interest = 0.017;
            printf("1,7 persen\n");
        }
    }


    printf("hore sampai akhir");
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
        while(check != 1 || methodChoice <=0 || methodChoice > 2 ){
            if(methodChoice !=1 || methodChoice != 2){
                system("CLS");
                printf("Please enter a valid number! (1 or 2)\n\n");
                printf("1. Deposit \n2. Planned savings\n");
                printf("\nEnter number : ");
                check = scanf("%d", &methodChoice);
                fflush(stdin);
                    while(check!=1){
                        system("CLS");
                        printf("Input must be a number! (1 or 2)\n\n");
                        printf("1. Deposit \n2. Planned savings\n");
                        printf("\nEnter number : ");
                        check = scanf("%d", &methodChoice);
                        fflush(stdin);
                    }
            }
            else if(check != 1){
            system("CLS");
            printf("Input must be a number! (1 or 2)\n\n");
            printf("1. Deposit \n2. Planned savings\n");
            printf("\nEnter number : ");
            check = scanf("%d", &methodChoice);
            fflush(stdin);
                while(methodChoice <=0 || methodChoice > 2){
                    system("CLS");
                    printf("Please enter a valid number! (1 or 2)\n\n");
                    printf("1. Deposit \n2. Planned savings\n");
                    printf("\nEnter number : ");
                    check = scanf("%d", &methodChoice);
                    fflush(stdin);
                }
            }
            
        }

    //calling deposit function
    if(methodChoice == 1){
        system("CLS");
        deposit();
    }
    //calling Planned Savings function
    else if(methodChoice == 2){
        system("CLS");
        savings();
    }

    return 0;
}