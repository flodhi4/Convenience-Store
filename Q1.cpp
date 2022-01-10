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

//Q1 displays the customers reciept
// it reads the bill.dat file and stores into functions
// then it displays the customer's copy of the reciept

#include "Q1.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Q1::Q1()
{
    double bottlecost, barscost, rancherscost, maskscost, tacscost, hst, owe;       // declare variables
    system("PAUSE");       // wait for user to continue
    system("CLS");      // clear screen

    ifstream fin;       // ifstream to read file
    fin.open("BILL.DAT",ios::in);       // open bill.dat file

    fin >> bottlecost;      // read all the variables that were stored in the file
    fin >> barscost;
    fin >> rancherscost;
    fin >> maskscost;
    fin >> tacscost;
    fin >> hst;
    fin >> owe;

    cout.precision(2);      // print to 2 decimal places


    cout <<"\n\t\tBRAMPTON CONVENIENCE STORE" << endl;      // top of reciept
    cout <<"\t\tPhone #: (123)-456-7890" << endl;
    cout <<"\t\tCUSTOMER'S COPY" << endl;

    // Display all items and total costs
    cout << "Water Bottles" << right << setw(30) << setfill(' ') << "$" << fixed << showpoint << setprecision(2) << bottlecost << endl;
    cout << "Snickers Bars" << right << setw(30) << setfill(' ') << "$" << fixed << showpoint << setprecision(2) << barscost << endl;
    cout << "Jolly Ranchers" << right << setw(29) << setfill(' ') << "$" << fixed << showpoint << setprecision(2) << rancherscost << endl;
    cout << "Face Masks" << right << setw(33) << setfill(' ') << "$" << fixed << showpoint << setprecision(2) << maskscost << endl;
    cout << "Tic Tacs" << right << setw(35) << setfill(' ') << "$" << fixed << showpoint << setprecision(2) << tacscost << endl;
    cout << "Total HST" << right << setw(34) << setfill(' ') << "$" << hst << endl;
    cout << "Your TOTAL" << right << setw(33) << setfill(' ') << "$" << fixed << showpoint << setprecision(2) << owe << endl;
    cout << "\n";


    fin.close();    // close file
}
