#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double ROOM_TYPE1 = 150.00;
	double ROOM_TYPE2 = 200.00;
	double ROOM_TYPE3 = 300.00;

	int room_type, nights;
	double sub_total = 0.0, discount = 0.0, total = 0.0, promo = 0.0;
	char promo_code;

	cout << "=======================================\n";
	cout << "    FTMK GRAND HOTEL BOOKING SYSTEM\n";
	cout << "=======================================\n";
	cout << "1. Standard Room - RM150.00 per night\n";
	cout << "2. Deluxe Room   - RM200.00 per night\n";
	cout << "3. Suite Room    - RM300.00 per night\n";
	cout << "----------------------------------------\n";

	cout << "Enter room type (1-3): ";
	cin >> room_type;

	cout << "Enter number of nights: ";
	cin >> nights;
	if (nights <= 0) {
		cout << "Number of nights must be more than 0!" << endl;
		return 0;
	}

	cout << "\n";
	if (room_type == 1) {
		cout << "You selected Standard Room.";
		sub_total = ROOM_TYPE1 * nights;
	}
	else if (room_type == 2) {
		cout << "You selected Deluxe Room.";
		sub_total = ROOM_TYPE2 * nights;
	}
	else if (room_type == 3) {
		cout << "You selected Suite Room.";
		sub_total = ROOM_TYPE3 * nights;
	}
	else {
		cout << "Invalid room type!" << endl;
		return 0;
	}

	cout << "\nDo you have promo code? (Y for Yes / N for No): ";
	cin >> promo_code;

	cout << "\n";
	cout << "------------------BOOKING SUMMARY------------------\n";

	cout << fixed << setprecision(2);

	if (room_type == 1) {
		cout << "Price per Night : RM" << ROOM_TYPE1 << endl;
	}
	else if (room_type == 2) {
		cout << "Price per Night : RM" << ROOM_TYPE2 << endl;
	}
	else {
		cout << "Price per Night : RM" << ROOM_TYPE3 << endl;
	}
	cout << "Nights Stayed   : " << nights << endl;
	cout << "Subtotal        : RM" << sub_total << endl;

	if (nights > 5) {
		discount = sub_total * 0.10;
		cout << "Discount (10.00%): RM" << discount << endl;
	}
	else if (nights >= 3) {
		discount = sub_total * 0.05;
		cout << "Discount (5.00%): RM" << discount << endl;
	}
	else {
		cout << "Discount        : RM0.00" << endl;
	}

	cout << "------------------------------------------------\n";

	if (promo_code == 'Y' || promo_code == 'y') {
		promo = (sub_total - discount) * 0.90;
		cout << "Final Total     : RM" << promo << endl;
	}
	else {
		total = sub_total - discount;
		cout << "Final Total     : RM" << total << endl;
	}
	
	cout << "------------------------------------------------\n";

	if (total >= 1200 || promo >= 1200) {
		cout << "VIP CUSTOMER: You are eligible for free airport pickup !" << endl;
	}
	else if (total < 300 || promo < 300) {
		cout << "Enjoy your vacation !" << endl;
	}
	else {
		cout << "Thank you for booking FTMK Grand Hotel." << endl;
	}
	return 0;
}