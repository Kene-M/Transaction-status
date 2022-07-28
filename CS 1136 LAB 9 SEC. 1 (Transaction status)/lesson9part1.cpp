// This program will compute and display the status for an order from an company that sells spools of copper wire.

#include <iostream>
#include <iomanip>

using namespace std;

void readDetails(int&, int&, double&); // Function prototype for reading and processing the transaction details.
void displayResults(int, int, double);  // Function prototype for displaying all the details of the transaction.

    // Main function.
int main()
{
        // Declare variables.
    int numSpoolsOrdered;  // To hold the number of spools ordered.
    int numSpoolsInStock;  // To hold the number of spools currently in stock.
    double shippingCharges = 12.99  ;  // To hold the shipping and handling charges for each spool.

        // Call the function for reading and processing the transaction details.
        // Pass the number of spools ordered, spools in stock and the shipping charges by reference.
    readDetails(numSpoolsOrdered, numSpoolsInStock, shippingCharges);

        // Call the function for displaying......
        // Pass the number of spools ordered, spools in stock and the shipping charges by value.
    displayResults(numSpoolsOrdered, numSpoolsInStock, shippingCharges);

    return 0;
}

    // Function for reading and processing the transaction details.
void readDetails(int& numSpoolsOrdered, int& numSpoolsInStock, double& shippingCharges)
{
    char shippingChoice;  // To hold the type of shipping selected by the user.

        // Ask the user to enter the number of spools that he wants to order.
    cout << "Spools to be ordered";
    cin >> numSpoolsOrdered;
    cout << endl;

        // Validate the input.
    while (numSpoolsOrdered < 1)
    {
            // Display error message.
        cout << "Spools order must be 1 or more" << endl;

            // Ask the user to enter the number of spools that he wants to order.
        cout << "Spools to be ordered";
        cin >> numSpoolsOrdered;
        cout << endl;
    }

        // Ask the user to enter the number of spools that are currently in stock.
    cout << "Spools in stock";
    cin >> numSpoolsInStock;
    cout << endl;

        // Validate the input.
    while (numSpoolsInStock < 0)
    {
            // Display error message.
        cout << "Spools in stock must be 0 or more" << endl;

            // Ask the user to enter the number of spools that are currently in stock.
        cout << "Spools in stock";
        cin >> numSpoolsInStock;
        cout << endl;
    }

        // Ask the user to enter his shipping choice.
    cout << "Special shipping and handling (y or n)";
    cin >> shippingChoice;
    cout << endl;

        // Display output if the user choice the special shipping option.
    if (shippingChoice == 'y')
    {
            // Ask the user to enter the new shipping amount.
        cout << "Shipping and handling amount";
        cin >> shippingCharges;
        cout << endl;

            // Validate the input.
        while (shippingCharges < 0.0)
        {
                // Display error message.
            cout << "The spool shipping and handling charge must be 0.0 or more" << endl;

                // Ask the user to enter the new shipping amount.
            cout << "Shipping and handling amount";
            cin >> shippingCharges;
            cout << endl;
        }
    }
}

    // Function for displaying all the details of the transaction.
void displayResults(int numSpoolsOrdered, int numSpoolsInStock, double shippingCharges)
{
        // Declare constants.
    const double COST_OF_SPOOL = 104.0;  // To hold the cost of each spool of copper wiring.

        // Declare variables.
    int numSpoolsToShip = numSpoolsOrdered;  // To hold the number of spools that are ready to be shipped.
    int numSpoolsOnBackOrder = 0;  // To hold the number of spools on back order.
    double totalSpoolCost;  // To hold the total cost of the spools that are ready to ship.
    double shipping_Charge_For_Ready_Spools;  // To hold the total shipping and handling charges for the spools ready to ship.
    double orderCost;  // To hold the total of the order ready to ship.

        // Check if the number of spools that were ordered is more than those in stock.
    if (numSpoolsOrdered > numSpoolsInStock)
    {
            // Update the number of spools on back order.
        numSpoolsOnBackOrder = numSpoolsOrdered - numSpoolsInStock;

            // Update the number of spools that are ready to be shipped.
        numSpoolsToShip = numSpoolsInStock;

    }

        // Calculate total spool cost, shipping charge for ready spools, and the order cost.
    totalSpoolCost = numSpoolsToShip * COST_OF_SPOOL;
    shipping_Charge_For_Ready_Spools = shippingCharges * numSpoolsToShip;
    orderCost = totalSpoolCost + shipping_Charge_For_Ready_Spools;

        // Display the results to the user.
    cout << "Spools ready to ship: " << numSpoolsToShip << endl;
    cout << "Spools on back-order: " << numSpoolsOnBackOrder << endl;

        // Set the desired output formatting for numbers.
    cout << setprecision(2) << fixed << showpoint;

    cout << "Subtotal ready to ship: $" << setw(10) << right << totalSpoolCost << endl;
    cout << "Shipping and handling:  $" << setw(10) << right << shipping_Charge_For_Ready_Spools << endl;
    cout << "Total shipping charges: $" << setw(10) << right << orderCost << endl;
}
