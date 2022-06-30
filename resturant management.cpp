#include<iostream>
#include <conio.h>
#include <string.h>
#include <chrono>
using namespace std;

void waitingtime()
{
    cout << "\b\b\b\b\b\b\b\b\b\b";
    for(int j = 7; j >=0; j--)
    {
        cout << j;
        _sleep(1000);
        cout << "\b";
    }
}
struct user
{
    char username[20];
    char password[20];
};
struct foodlist
{
    char foodname[31];
    float foodprice;
};

void edit(foodlist food[9], int &counter,bool &first)
{
    char name[31], newfood[31];
    float price, price2;
    cout << "\n\t(1) Edit a food in the list\n\t(2) Remove a food from menu\n\t(3) Add a food to the menu\n\t";
    int command = getch();
    if(command == '1')
    {
        cout << "\n\n\tWhich one do you want to edit?: ";
        int command2 = getch();
        cout << "\n\n\t(1) Edit the name\n\t(2) Editing the price tag\n\t";
        int command3 = getch();
        if( command3 == '1')
        {
            cout << "\n\tWrite a name for the food: ";
            cin.ignore();
            cin.getline(name, 31);
            int a = command2 - '0';
            strcpy(food[a - 1].foodname,name);
        }
        else
        {
            cout << "\n\tEnter a price tag for the food: ";
            cin >> price;
            int a = command2 - '0';
            food[a - 1].foodprice = price;
        }
        return;
    }
    if(command == '2')
    {
        int i;
        cout << "\n\tWhich one do you want to remove?: ";
        int command2 = getch();
        int a = command2 - '0';
        for(i = a - 1; i <= counter; i++)
            food[i] = food[i+1];
        counter--;
        cout << endl;
        return;
    }

    else
    {
        cout << "\n\tWrite the name of the new food: ";
        cin.ignore();
        cin.getline(newfood, 31);
        strcpy(food[counter + 1].foodname,newfood);
        cout << "\n\tEnter the price tag for the new food: ";
        cin >> price2;
        food[counter + 1].foodprice = price2;
        counter++;
    }

}
int main()
{
    user signedup[20];
    char name[20], pass[20];
    int i = 1, j;
    char x;
    bool flag = false, glag = false, admin = false;
    start:
    system("cls");
    cout << "    " << "-------------Welcome to the Restaurant Management System---------------" << endl;
    cout << "\tMenu: " << endl << "\t(1) sign up" << endl << "\t(2) Login" << endl << endl;
    cout << "\tPlease enter a number: ";
    x = getch();
    cout << "\n\n";
    if(x == '1'){
        cout << "\tSign up as a User or Admin? Enter 'u' or 'a': ";
        char y;
        y = getch();
        cout << "\n\n";
        if( y == 'a'){
            if(glag)
            {
                cout << "\tWe already have an admin, please sign up as a user.\n";
                cout << "\tReturning to the 1st window in   seconds.";
                waitingtime();
                goto start;
            }
            cout << "\tYour username is 'admin'. Please select a password: ";
            strcpy(signedup[0].username,"admin");
            cin >> signedup[0].password;
            cout << endl;
            cout << "\tYou registered successfully. Returning to the 1st window in   seconds.";
            waitingtime();
            glag = true;
            goto start;
        }

        else
        {
            takename:
            cout << "\tEnter your username: ";
            cin >> signedup[i].username;
            cout << endl;
             for( j = 0; j < i; j++)
            {
                if(strcmp(signedup[j].username,signedup[i].username) == 0)
                {
                    cout << "\tSorry! This username is already taken. Please try another one!\n\n";
                    goto takename;
                }
            }
            cout << "\tEnter your password: ";
            cin >> signedup[i].password;
            cout << endl;
            cout << "\tYou registered successfully. Returning to the 1st window in   seconds.";
            waitingtime();
            i++;
            goto start;
        }
    }

    else
    {
        cout << "\tEnter your username: ";
        cin >> name;
        cout << endl;
        int threetimewrongpass = 0;
        wrongpass:
        threetimewrongpass++;
        for( j = 0; j < 20; j++)
        {
            if(strcmp(signedup[j].username,name) == 0)
            {
                cout << "\tEnter your password: ";
                cin >> pass;
                if(strcmp(signedup[j].password,pass) == 0)
                {
                    if(strcmp(name, "admin") == 0)
                        admin = true;
                    flag = true;
                    break;
                }
                if(strcmp(signedup[j].password,pass) != 0)
                {
                    cout << "\n\tYou entered a wrong password! Please try again.\n\n";
                    if(threetimewrongpass == 3)
                    {
                        cout << "\tYou have entered a wrong password 3 times. Create another account!";
                        cout << "\t\tReturning to the 1st window in   seconds.";
                        waitingtime();
                        goto start;
                    }
                    goto wrongpass;
                }
            }
        }
        if(j == 20){
        cout << "\tYou haven't signed in yet. Please sign up before trying again.\n\t";
        cout << "Returning to the 1st window in   seconds.";
        waitingtime();
        goto start;
        }
    }
    int counter = 5;
    foodlist food[9];
    bool first = false;
    if(flag)
    {
        strcpy(food[0].foodname, "Chicken Biryani" );
        food[0].foodprice = 2;
        strcpy(food[1].foodname, "Chicken Palao" );
        food[1].foodprice = 1.5;
        strcpy(food[2].foodname, "Chinese rice" );
        food[2].foodprice = 2.5;
        strcpy(food[3].foodname, "Chicken Burger" );
        food[3].foodprice = 1;
        strcpy(food[4].foodname, "Nawabi Pizza" );
        food[4].foodprice = 4.5;
        strcpy(food[5].foodname, "2.5 Litre Coke" );
        food[5].foodprice = 1.75;
        menu:
        system("cls");
        cout << "\t-----------------------------MENU-------------------------------" << endl << endl;
        for( j = 0; j <= counter; j++)
        {
            printf("\t(%d) %-30s\t\t\t$%g only.\n", j + 1, food[j].foodname, food[j].foodprice);
        }
        if(admin)
        {
            cout << "\n\n\t-----------------------ADMINISTER TABLE-------------------------" << endl;
            cout << "\n\t(1) Order food\n\t(2) Edit the food list\n\t";
            int command = getch();
            if(command == '2'){
                edit(food, counter, first);
                goto menu;
            }
        }
        FILE *fp = fopen("data.txt", "wt");
        fwrite(food, sizeof(food), 1, fp);
        cout << "\n\tPlease select the order number: ";
        int order;
        cin >> order;
        cout << "\n\tPlease enter the number of deals: ";
        int deals;
        cin >> deals;
        cout << "\n\tOrder: " << food[order - 1].foodname << ".";
        cout << "\n\tNumber of deals: " << deals << ".";
        cout << "\n\tPrice of each deal: " << food[order - 1].foodprice << "$ only.";
        cout << "\n\tTotal price: " << deals * food[order - 1].foodprice << "$ only." << endl << endl;
        cout << "\t---------------------THANK YOU FOR COMING-----------------------" << endl << endl;
    }
    return 0;
}
