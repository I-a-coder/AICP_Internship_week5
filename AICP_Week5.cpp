#include <iostream>
#include <string>

using namespace std;

// Function to check if a frequent parking number is valid
bool isValidFrequentParkingNumber(const string& frequentParkingNumber)
{
    if (frequentParkingNumber.size() != 5)
        return false;

    int total = 0;
    for (int i = 0; i < 4; ++i)
        total += (i + 1) * (frequentParkingNumber[i] - '0');

    int checkDigit = frequentParkingNumber[4] - '0';
    return total % 11 == checkDigit;
}

int main()
{
    string day;
    int arrivalHour, hoursParked;
    string frequentParkingNumber;
    float dailyTotal = 0.0f;

    // Prices per hour
    const float priceSundayBefore16 = 2.00;
    const float priceSundayAfter16 = 1.00;
    const float priceWeekday = 10.00;
    const float priceSaturday = 3.00;

    // Discounts
    const float discountBefore16 = 0.10;
    const float discountAfter16 = 0.50;
    const float eveningCharge = 4.00;

    // Input data
    cout << "Enter day of the week: ";
    cin >> day;
    cout << "Enter arrival hour (0-23): ";
    cin >> arrivalHour;
    cout << "Enter hours parked: ";
    cin >> hoursParked;
    cout << "Enter frequent parking number (if available): ";
    cin >> frequentParkingNumber;

    // Calculate price
    float pricePerHour;
    if (day == "Sunday") 
    {
        if (arrivalHour >= 16)
            pricePerHour = priceSundayAfter16;
        else
            pricePerHour = priceSundayBefore16;
    }
    else if (day == "Saturday") 
    {
        pricePerHour = priceSaturday;
    }
    else {
        pricePerHour = priceWeekday;
    }

    // Calculate discount based on arrival time
    float discount = (arrivalHour >= 16) ? discountAfter16 : discountBefore16;

    // Validate frequent parking number
    if (!frequentParkingNumber.empty()) 
    {
        bool isValid = isValidFrequentParkingNumber(frequentParkingNumber);
        if (!isValid) 
        {
            cout << "Invalid frequent parking number. No discount applied." << endl;
            discount = 0;
        }
    }

    // Calculate base price
    float basePrice = pricePerHour * hoursParked;

    // Apply discount
    float finalPrice = basePrice * (1 - discount);

    // Add evening charge if applicable
    if (arrivalHour < 16 && arrivalHour + hoursParked >= 16)
        finalPrice += eveningCharge;

    // Update daily total
    dailyTotal += finalPrice;

    // Display result
    cout << "Price to park: " << finalPrice << endl;
    cout << "Daily total: " << dailyTotal << endl;

    return 0;
}
