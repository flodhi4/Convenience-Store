// Fauzan Lodhi
// November 7, 2020
// Convenience Store Program
// User is welcomed to the store, given a menu of items and costs
// user enters which item to buy, and quantity
// quantity is sent to item file, where the cost is calculated
// cost is returned to main
// all the costs are sent to the bill function to calculate total and hst and recieved back in main
// costs are written to BILL.DAT file to store all the costs
// total costs are sent to payment function which keeps going until user has paid the due amount
// program reads from BILL.DAT to give the user their customer's copy of reciept
// program uses overloaded function to share a fun fact of how much they spent on a specific category of items
//program begins a customer survey where the customer will enter # of times they have purchased an item at this store
// program will use array to store each rating and then use pointer to display each rating

//--------------------

// main.cpp welcomes the user, shows the menu
// takes the user's order, calculates everything, writes to BILL.DAT file
// takes the user's payments
// calls on Q1 then shares fun fact, then calls on Q2



#include "Q1.h"
#include "Q2.h"
#include <iostream>
#include <bits/stdc++.h>    // import all libraries
using namespace std;

//------------------------------------ declare welcome and menu functions
void welcome();
void menu();
//------------------------------------ declare item and bill functions
double water(int bottles);
double snickers(int bars);
double jolly(int ranchers);
double face(int masks);
double tic(int tacs);
double bill(double a, double b, double c, double d, double e);
double payment (double a);
double add(double a, double b);

//------------------------------------

int main()
{

    system ("Color F0");    // change screen to white background with black text like a reciept
    string buy;     // declare string buy variable
    int bottles=0, bars=0, ranchers=0, masks=0, tacs=0;   // declare int variables to get amount of each item
    double bottlecost=0, barscost=0, rancherscost=0, maskscost=0, tacscost=0, hst=1.13; // declare double variables for cost of each item
    char yes = 'y'; // declare char variable specifically for do while loop
    welcome();  // call on welcome function
    menu();     // call on menu function
    do  // begin do while loop
    {
        cout << "\nWhat would you like to buy? (Please enter exactly as shown on menu): ";
        getline(cin, buy);      // user enter what they want to buy


        if (buy=="water bottle")    // if user would like to buy water bottles
        {
            cout << "# of bottles to buy: ";
            cin >> bottles;     // enter quantity
            bottlecost=water(bottles);  // send quantity to water function and recieve as bottlecost
        }

        //------------------------------------

        else if (buy=="snickers bar")   // if user would like to buy snickers bars
        {
            cout << "# of bars to buy: ";
            cin >> bars;        // enter quantity
            barscost=snickers(bars);    // send quantity to snickers function and recieve as barscost
        }

        //------------------------------------

        else if (buy=="jolly ranchers")     // if user would like to buy jolly ranchers
        {
            cout << "# of ranchers to buy: ";
            cin >> ranchers;    // enter quantity
            rancherscost=jolly(ranchers);   // send quantity to jolly functions and recieve as rancherscost
        }

        //------------------------------------

        else if (buy=="face masks")     // if user would like to buy face masks
        {
            cout << "# of masks to buy: ";
            cin >> masks;       // enter quantity
            maskscost=face(masks);  // send quantity to face functions and recieve as maskscost
        }

        //------------------------------------

        else if (buy=="tic tacs")   // if user would like to buy tic tacs
        {
            cout << "# of tacs to buy: ";
            cin >> tacs;        // enter quantity
            tacscost=tic(tacs); // send quantity to face functions and recieve as tacscost
        }

        //------------------------------------

        else        // if user enters item off the menu or spelling error
        {
            cout << "Error. Please try again." << endl;
        }

        //------------------------------------

        cout << "Enter y to add to order: ";
        cin >> yes;     // enter y to add to order; anything else will exit the loop
        cin.ignore();

    }while (yes=='y');
    double owe = bill(bottlecost, barscost, rancherscost, maskscost, tacscost);  // after exiting loop, send all costs to bill function
    hst = (bottlecost+barscost+rancherscost+maskscost+tacscost)*0.13;   // calculate hst in main

    //---------------------------------------------
    ofstream fout;
    fout.open("BILL.DAT");  // create and write to .dat file
    fout << fixed << showpoint << setprecision(2) << bottlecost << endl;     // write the bill to .dat file
    fout << fixed << showpoint << setprecision(2) << barscost << endl;
    fout << fixed << showpoint << setprecision(2) << rancherscost << endl;
    fout << fixed << showpoint << setprecision(2) << maskscost << endl;
    fout << fixed << showpoint << setprecision(2) << tacscost << endl;
    fout << fixed << showpoint << setprecision(2) << hst << endl;
    fout << fixed << showpoint << setprecision(2) << owe << endl;
    fout.close();   // close file
    //---------------------------------------------

    payment(owe);       // send variable owe to payment function and run

    Q1();       // call on Q1

    system("PAUSE");    // wait for user to continue

    // display fun facts using overloaded function
    cout << "\nFUN FACT!" << endl;
    double drinks = add(bottlecost, tacscost);      // overloaded function
    cout << "On water & TicTacs you spent a total of: $" << fixed << showpoint << setprecision(2) << drinks << endl;

    double candy = add(barscost, rancherscost);     // overloaded function
    cout << "\nOn candy you spent a total of: $" << fixed << showpoint << setprecision(2) << candy << endl;

    Q2();   // call on Q2

    return 0;
}

void welcome()  // function to display welcome message to user and introduce them
{
    cout << "Welcome to the Brampton Convenience Store!" << endl;
    cout << "We currently are running low on stock, so we only have a few items left" << endl;
    cout << "Please take a look at our list of remaining products: " << endl;
}

//------------------------------------

void menu()     // function to display what is available at the convenience store
{
    cout << "\nwater bottle"<< right << setw(30) << setfill(' ') << "$2.75" << endl;
    cout << "snickers bar"<< right << setw(30) << setfill(' ') <<"$1.25" << endl;
    cout << "jolly ranchers"<< right << setw(28) << setfill(' ') <<"$3.50" << endl;
    cout << "face masks"<< right << setw(32) << setfill(' ') <<"$1.99" << endl;
    cout << "tic tacs"<< right << setw(34) << setfill(' ') <<"$0.99" << endl;
}

//------------------------------------

double water(int bottles)   // function to calculate water bottle total cost
{
    double total = 0+(2.75*bottles);
    return total;
}

//------------------------------------

double snickers(int bars)   // function to calculate snickers bar total cost
{
    double total = 0+(1.25*bars);
    return total;
}

//------------------------------------

double jolly(int ranchers)  // function to calculate jolly ranchers total cost
{
    double total = 0+(3.50*ranchers);
    return total;
}

//------------------------------------

double face(int masks)  // function to calculate face masks total cost
{
    double total = 0+(1.99*masks);
    return total;
}

//------------------------------------

double tic(int tacs)    // function to calculate tic tacs total cost
{
    double total = 0+(0.99*tacs);
    return total;
}

//------------------------------------

double bill(double a, double b, double c, double d, double e)
{
    system("CLS");      // clear screen when bill function is called upon
    double hst=1.13;        // declare hst variable
    cout << "Brampton Convenience Store" << endl;     // heading with billing and store name
    system ("PAUSE");       // programs waits for user to continue


    cout << fixed << setprecision(2);       // all output will be to two decimal places
    cout << "\nYour bill...." << endl;
    cout << "Water Bottles" << right << setw(30) << setfill(' ') << "$" << a << endl;        // output the cost of each item
    cout << "Snickers Bars" << right << setw(30) << setfill(' ') << "$" << b << endl;          // costs are jusified and aligned right
    cout << "Jolly Ranchers" << right << setw(29) << setfill(' ') << "$"<< c << endl;          // all total costs per item are recieved by a,b,c,d,e variables
    cout << "Face Masks" << right << setw(33) << setfill(' ') << "$" << d << endl;
    cout << "Tic Tacs" << right << setw(35) << setfill(' ') << "$" << e << endl;


    double total;
    total= (a+b+c+d+e);      // calculates total before tax
    hst = (total*hst)-total;    // total amount of hst

    cout << "Total HST" << right<<setw(34)<<setfill(' ')<< "$" << hst;       // outputs money in HST owed
    total=total+hst;        //total cost now includes HST

    cout << "\nYour total bill is" << right << setw(25) << setfill(' ') << "$" << total << endl;   //output total with HST included




    return total;   // return total to main
}

//------------------------------------

double payment (double a)       // user payment function
{
    double pay, newtotal, orgtotal;     // declare variables
    orgtotal= a;
    cout.precision(2);
    do
    {
        cout << "\nEnter amount you would like to pay: $";      // prompot user to enter payment amount
        cin >> pay;
        newtotal = orgtotal-pay;    // new total is total subtracted by payment

        if(newtotal>=0.01)      // if user did not pay enough
        {
            cout << "\nYou still owe: $" << newtotal << endl;

            orgtotal = newtotal;
        }

        else if (newtotal<0)        // if user paid too much
        {
            cout << "You recieved $" << newtotal << " in change" << endl;
        }

        else
        {
            newtotal=0;
        }

    }while(newtotal>=0.01); // do while loop to ensure that user pays the total amount owed

}


double add(double a, double b)      // overloaded function will be used to add total costs of specific items purchased
{
    double total = a+b;
    return total;
}
