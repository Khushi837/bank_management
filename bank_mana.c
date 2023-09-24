// assignment make a program in c
// BANK MANAGEMENT SYSTEM program
// In this program we create a function to read all customers details and call it in main.
// my program has following menu driven options as listed below
// the menu driven options are
// 1. Print the Account number and name and balance of each customer.
// 2. Withdraw money
// 3. Deposit money
// 4. Search Customer
#include <stdio.h>
struct customer
{
    int account_no;
    char name[80];
    int balance;
};
void accept(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);
int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;
    printf("Banking System\n\n");
    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {
        printf("\nBanking System Menu :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(data, n);
            break;
        case 2:
            printf("Enter account number to search : ");
            scanf("%d", &account_no);
            index = search(data, n, account_no);
            if (index == -1)
            {
                printf("Record not found : ");
            }
            else
            {
                printf("A/c Number: %d\n Balance: %d\n",
                       data[index].account_no, data[index].name,
                       data[index].balance);
            }
            break;
        case 3:
            printf("Enter account number : ");
            scanf("%d", &account_no);
            printf("Enter amount to deposit : ");
            scanf("%d", &amount);
            deposit(data, n, account_no, amount);
            break;
        case 4:
            printf("Enter account number : ");
            scanf("%d", &account_no);
            printf("Enter amount to withdraw : ");
            scanf("%d", &amount);
            withdraw(data, n, account_no, amount);
        }
    } while (choice != 0);
    return 0;
}
void accept(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);
        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        list[i].balance = 0;
    }
}
void display(struct customer list[80], int s)
{
    int i;
    printf("\n\nA/c No\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,
               list[i].balance);
    }
}
int search(struct customer list[80], int s, int number)
{
    int i;
    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        }
    }
    return -1;
}
void deposit(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i == -1)
    {
        printf("Record not found");
    }
    else
    {
        list[i].balance += amt;
    }
}
void withdraw(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i == -1)
    {
        printf("Record not found\n");
    }
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}
