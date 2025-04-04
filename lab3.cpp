/** \file lab3.cpp
 * @TODO: Fix
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then Check In
 *                   the code with a comment on the fix you did
 *                3) There are a three functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      28/01/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
using namespace std;

// Global constants
const int VAT = 21;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
    const int SIZE = 10;
    // Initialize array price
    const int price[SIZE] = { 12, 4, 8, 1, 17, 2, 4, 2, 9, 1 };

    int choice;
    // Declare array quantity and total
    int quantity[SIZE], total[SIZE];

    // Interactive menu
    do {
        choice = printMenu();

        switch (choice) {
            // Enter quantity
        case 1:
            fillInArray(quantity, SIZE);
            break;
            // Calculate total
        case 2:
            multArrays(quantity, price, total, SIZE);
            break;
            // Print total
        case 3:
            displayArray(total, SIZE);
            break;
            // All positive
        case 4:
            cout << "\nAll elements are positive: " << isAllPositive(quantity, SIZE);
            break;
            // Exit
        case 5:
            // No code needed
            break;
        default:
            // Should never happen
            assert(false);
        }
    } while (choice != 5);

    cout << "\nHave a nice day:)" << endl;
    return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
    int choice;

    do {
        cout << "\n == MENU ==";
        cout << "\n1) Enter quantity";
        cout << "\n2) Calculate total";
        cout << "\n3) Print total";
        cout << "\n4) Check if all elements are positive";
        cout << "\n5) Exit";

        cout << "\nEnter the choice: ";
        cin >> choice;

        if (choice < 1 || choice > 4) {
            cout << "\nWrong choice, try again.";
        }
    } while (choice < 1 || choice > 4);
    return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        cout << "\nEnter an element for the array at " << i << ": ";
        cin >> arr[i];
    }

    cout << "\nArray filled in successfully.";
}

/**
 * <code>multArrays</code> multiplies the value of elements of the quantity array
 * to the corresponding value at the price array and stores values in total array.
 * NOTE: precondition is that the arrays have the same size.
 * <BR>
 * @param arrQuantity The array containing quantity.
 * @param arrPrice The array containing prices.
 * @param arrTotal The array to store the total.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        arrTotal[i] = arrQuantity[i] * arrPrice[i];
    }

    cout << "\nCalculation done successfully.";
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], const int size) {
    assert(size > 0);

    int sum = 0;

    for (int i = 0; i < size; ++i) {
        cout << "\nValue at " << i << ": " << arr[i];
        sum += arr[i];
    }

    cout << "\nThe total is: " << sum;
}

/**
 * <code>sumOddArray</code> calculates the sum of odd numbers in the array
 * <BR>
 * @param arr The array to check
 * @param size The size of the array
 * @return The sum of odd numbers in the array
 */
int sumOddArray(const int arr[], const int size) {
    assert(size > 0);

    int sum = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }

    return sum;
}

/**
 * <code>isAllPositive</code> checks if all elements in the array are bigger or equal to zero
 * <BR>
 * @param arr The array to check
 * @param size The size of the array
 * @return true if all elements are positive, false otherwise
 */
bool isAllPositive(const int arr[], const int size) {
    assert(size > 0);

    bool result = true;

    for (int i = 0; result && i < size; i++) {
        if (arr[i] < 0) {
            result = false;
        }
    }

    return result;
}

/**
 * <code>avgOddArray</code> calculates the average of odd numbers in the array
 * and stores it in the last passed parameter
 * <BR>
 * @param arr The array to check
 * @param size The size of the array
 * @param avgOdd Parameter to store the average of odd numbers
 */
void avgOddArray(const int arr[], const int size, int& avgOdd) {
    assert(size > 0);

    int countOdd = 0;
    int sumOdd = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            sumOdd += arr[i];
            countOdd++;
        }
    }

    if (countOdd == 0) {
        avgOdd = 0;
    } else {
        avgOdd = sumOdd / countOdd;
    }
}
