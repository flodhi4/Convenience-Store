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

//Q2 is a customer survey
// they will enter how many times they have purchased an item at this store
// for each time, the user will enter a customer service rating out of 5
// each rating will be stored in an array
// a pointer integer is the initialized as the array[i] value inside a for loop
// each rating is displayed
// the user is thanked


#include "Q2.h"
#include <bits/stdc++.h>
using namespace std;
Q2::Q2()
{
    system("PAUSE");    // wait for the user to continue
    system("CLS");      // clear screen
    int n;             // declare int variable
    cout << "THANK YOU FOR SHOPPING AT THE BRAMPTON CONVENIENCE STORE" << endl;     // tell the user that this is a survey
    cout << "\nTHIS IS A CUSTOMER SURVEY" << endl;

    cout << "How many times have you purchased an item here?: ";
    cin >> n;       // prompt the user to enter an integer of how many times they have purchased an item from the store

    int orders[n];      // create array the size of integer n

    for (int i=0; i<n; i++)     // for loop as many times as the customer has bought an item at the store
    {
        int rating;
        cout << "\nFor visit #" << i+1 << ", how would you rank customer service here, out of 5? 5=best, 0=worst: ";
        cin >> rating;      // prompt the user to give the store a rating out of 5 for each time they have bought an item here
        cout << endl;
        if (rating>5 || rating<0)       // if user enters a rating off the scale
        {
            cout << "Error." << endl;
            i=i-1;      // to ensure the loop continues

        }

        //-----------------------

        else
        {
            orders[i] = rating;    // rating is stored in array
        }
    }

    //----------------------------

    for (int i=0; i<n; i++)     // for loop to print the information stored in the array
    {
        int *ptrRating = &orders[i];        // use pointer to print the array values
        cout << "\nFor visit #" << i+1 << endl;
        cout << "You rated customers service " << *ptrRating << " out of 5" << endl;        // print the pointer rating
    }

    cout << "\nSURVEY COMPLETE. THANK YOU" << endl;     // thank the user for using this program
}
