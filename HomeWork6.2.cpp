
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    // Declare Variables
    
    int FederalTaxRate, StateTaxRate;
    float hours, PayRate;
    string name, weeknumber;

    //Input Variables
    cout << "Enter Week number ";
    cin >> weeknumber;

    cout << "Enter employee's name ";
    cin >> name;

    cout << "Enter number of hours ";
    cin >> hours;
    
    cout << "Enter hourly pay rate ";
    cin >> PayRate;

    cout << "Enter Federal tax rate ";
    cin >> FederalTaxRate;

    cout << "Enter State tax rate ";
    cin >> StateTaxRate;

    // variables for the file
    double grosspay = hours * PayRate;
    double FederalTax = grosspay * FederalTaxRate/100;
    double StateTax = grosspay * StateTaxRate/100;
    double TotalTax = FederalTax + StateTax;
    double netpay = grosspay - TotalTax;

    // Checking math
    cout << TotalTax << endl;
    cout << netpay << endl;

    // Name for the file
    string filename = name + "_w" + weeknumber + ".txt";
    
    // Creating a file 
    ofstream outFile(filename);

    outFile << fixed << setprecision(2);
    outFile << "Employee Name: " << name << endl;
    outFile << "Hours worked: " << hours << endl;
    outFile << "Pay Rate: " << PayRate << endl;
    outFile << "Gross Pay: " << grosspay << endl;
    outFile << "Deductions :" << endl;
    outFile << "  Federal Withholding: "<<FederalTax << endl;
    outFile << "  State Withholding: "<< StateTax << endl;
    outFile << "  Total Deduction:  "<< TotalTax << endl;
    outFile << "Net Pay: " << netpay;

    outFile.close()
 

}

