#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
double getPrice(int room_type);
double calculateDiscount(double subtotal, int nights);
void computeAmounts(double price, int nights, double& subtotal, double& discount, double& afterDiscount);
double applyPromo(double afterDiscount, char promo_code);
void displaySummary(double price, int nights, double subtotal, double discount, double final_total);
void displayMessage(double final_total);

// getPrice
double getPrice(int room_type) {
    double price[] = { 0.0, 150.00, 200.00, 300.00 };

    if (room_type >= 1 && room_type <= 3)
        return price[room_type];
    else
        return 0.0;
}

// calculateDiscount
double calculateDiscount(double subtotal, int nights) {
    if (nights > 5) return subtotal * 0.10;
    else if (nights >= 3) return subtotal * 0.05;
    else return 0.0;
}

// computeAmounts
void computeAmounts(double price, int nights, double& subtotal, double& discount, double& afterDiscount) {
    subtotal = price * nights;
    discount = calculateDiscount(subtotal, nights);
    afterDiscount = subtotal - discount;
}

// applyPromo
double applyPromo(double afterDiscount, char promo_code) {
    if (promo_code == 'Y' || promo_code == 'y')
        return afterDiscount * 0.10;  // promo gives 10% discount
    return 0.0;
}

// displaySummary
void displaySummary(double price, int nights, double subtotal, double discount, double final_total) {
    cout << fixed << setprecision(2);
    cout << "\n------------------BOOKING SUMMARY------------------\n";
    cout << "Price per Night : RM" << price << endl;
    cout << "Nights Stayed   : " << nights << endl;
    cout << "Subtotal        : RM" << subtotal << endl;
    cout << "Discount        : RM" << discount << endl;
    cout << "Final Total     : RM" << final_total << endl;
    cout << "---------------------------------------------------\n";
}

// displayMessage
void displayMessage(double final_total) {
    if (final_total >= 1200)
        cout << "VIP CUSTOMER: You are eligible for free airport pickup!\n";
    else if (final_total < 300)
        cout << "Enjoy your vacation!\n";
    else
        cout << "Thank you for booking FTMK Grand Hotel.\n";
}

int main() {
    int room_type, nights;
    char promo_code, anotherbooking;

    do {
        cout << "=======================================\n";
        cout << "    FTMK GRAND HOTEL BOOKING SYSTEM\n";
        cout << "=======================================\n";
        cout << "1. Standard Room - RM150.00 per night\n";
        cout << "2. Deluxe Room   - RM200.00 per night\n";
        cout << "3. Suite Room    - RM300.00 per night\n";
        cout << "----------------------------------------\n";

        cout << "Enter room type (1-3): ";
        cin >> room_type;
        double price = getPrice(room_type);
        
        if (room_type<1||room_type>3) {
            cout << "Invalid room type!\n";
            continue;
        }
        
        cout << "Enter number of nights: ";
        cin >> nights;

        if (nights <= 0) {
            cout << "Invalid number of nights!\n";
            continue;
        }

        cout << "Do you have promo code? (Y/N): ";
        cin >> promo_code;

        // compute amounts
        double subtotal = 0.0, discount = 0.0, afterDiscount = 0.0;
        computeAmounts(price, nights, subtotal, discount, afterDiscount);

        // apply promo
        double promo_amount = applyPromo(afterDiscount, promo_code);
        double final_total = afterDiscount - promo_amount;

        // summary
        displaySummary(price, nights, subtotal, discount, final_total);

        // message
        displayMessage(final_total);

        cout << "Do you want to make another booking? (Y/N): ";
        cin >>anotherbooking;

    } while (anotherbooking == 'Y' || anotherbooking == 'y');

    cout << "Thank you for using FTMK Hotel Booking System!\n";
    return 0;
}
