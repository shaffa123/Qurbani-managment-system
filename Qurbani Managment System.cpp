#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ====================== Base Class ======================
class Animal
{
protected:
    string name;
    double animalPrice;
    double cuttingPrice;

public:
    Animal(string n, double aPrice, double cPrice)
    {
        name = n;
        animalPrice = aPrice;
        cuttingPrice = cPrice;
    }

    virtual void displayDetails()
    {
        cout << "\nAnimal: " << name << endl;
        cout << "Animal Price: Rs. " << animalPrice << endl;
        cout << "Cutting Price: Rs. " << cuttingPrice << endl;
    }

    double getTotalPrice()
    {
        return animalPrice + cuttingPrice;
    }

    string getName()
    {
        return name;
    }
};

// ====================== Derived Classes ======================
class Goat : public Animal
{
public:
    Goat() : Animal("Goat", 45000, 5000) {}
};

class Cow : public Animal
{
public:
    Cow() : Animal("Cow", 120000, 12000) {}
};

class Camel : public Animal
{
public:
    Camel() : Animal("Camel", 200000, 20000) {}
};

// ====================== Donation Class ======================
class Donation
{
private:
    double donationAmount;

public:
    Donation()
    {
        donationAmount = 0;
    }

    void askDonation()
    {
        char choice;

        cout << "\nDo you want to donate for needy families and children? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            cout << "Enter donation amount: Rs. ";
            cin >> donationAmount;

            cout << "Thank you for your kindness " << endl;
        }
    }

    double getDonation()
    {
        return donationAmount;
    }
};

// ====================== Payment Class ======================
class Payment
{
public:
    void processPayment(double total)
    {
        int method;

        cout << "\n====================================";
        cout << "\n        PAYMENT SECTION";
        cout << "\n====================================";

        cout << "\n1. Card Payment";
        cout << "\n2. Cash On Delivery";

        cout << "\n\nChoose Payment Method: ";
        cin >> method;

        if (method == 1)
        {
            string cardNumber;
            string hiddenCard = "";

            cout << "\nEnter 16-digit Card Number: ";
            cin >> cardNumber;

            // Hide card number except last 4 digits
            for (int i = 0; i < cardNumber.length() - 4; i++)
            {
                hiddenCard += "*";
            }

            hiddenCard += cardNumber.substr(cardNumber.length() - 4);

            cout << "\nProcessing Secure Payment..." << endl;

            cout << "Card Number: " << hiddenCard << endl;

            cout << "Payment of Rs. " << total << " Successful " << endl;
        }
        else if (method == 2)
        {
            cout << "\nCash On Delivery Selected." << endl;
            cout << "Please pay Rs. " << total << " at delivery." << endl;
        }
        else
        {
            cout << "\nInvalid Payment Method!" << endl;
        }
    }
};

// ====================== Main Function ======================
int main()
{
    cout << "=============================================";
    cout << "\n      QURBANI MANAGEMENT SYSTEM";
    cout << "\n=============================================";

    cout << "\n\nWelcome to Online Qurbani Service";

    int choice;

    cout << "\n\nAvailable Animals:";
    cout << "\n1. Goat  - Rs. 45000 + Cutting Rs. 5000";
    cout << "\n2. Cow   - Rs. 120000 + Cutting Rs. 12000";
    cout << "\n3. Camel - Rs. 200000 + Cutting Rs. 20000";

    cout << "\n\nSelect Animal: ";
    cin >> choice;

    Animal *selectedAnimal;

    // Dynamic Binding (Polymorphism)
    if (choice == 1)
    {
        selectedAnimal = new Goat();
    }
    else if (choice == 2)
    {
        selectedAnimal = new Cow();
    }
    else if (choice == 3)
    {
        selectedAnimal = new Camel();
    }
    else
    {
        cout << "\nInvalid Choice!" << endl;
        return 0;
    }

    // Display Animal Details
    selectedAnimal->displayDetails();

    // Donation
    Donation d;
    d.askDonation();

    // Total Bill
    double totalBill = selectedAnimal->getTotalPrice() + d.getDonation();

    cout << "\n====================================";
    cout << "\n          FINAL BILL";
    cout << "\n====================================";

    cout << "\nAnimal Selected: " << selectedAnimal->getName();
    cout << "\nAnimal + Cutting Charges: Rs. "
         << selectedAnimal->getTotalPrice();

    cout << "\nDonation Amount: Rs. " << d.getDonation();

    cout << "\n------------------------------------";
    cout << "\nTotal Payment: Rs. " << totalBill;
    cout << "\n------------------------------------";

    // Payment
    Payment p;
    p.processPayment(totalBill);

    cout << "\n\nThank you for using Qurbani Management System ";
    cout << "\nMay your Qurbani be accepted!" << endl;

    delete selectedAnimal;

    return 0;
}