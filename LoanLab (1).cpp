#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void drawline(char c, int charRep)
{
    for (int a=1; a <= charRep; a++)
        {
            cout << c; 
        }
        cout << endl;
}

double printLoanPayments(double loanAmount,double annualInterest, double monthlyPayment)
{
    double principle = loanAmount;
    double monthlyinterestpercent = annualInterest /12; 
    int month =1;
    double interestindollars; 
    double PaidOnBalance;
    double interestpaidsofar =0;
    
    cout << "Month\tBalance\tPayment\tPaidOnBalance\tInterest\tTotal Int. Paid" << endl; 
    
    while(principle >=0){   
        interestindollars = principle * monthlyinterestpercent;
        PaidOnBalance = monthlyPayment - interestindollars;
        interestpaidsofar += interestindollars;  
        
        principle = principle + interestindollars - monthlyPayment;
        
        cout << month <<"\t" << principle << "\t" << monthlyPayment << "\t" << PaidOnBalance << "\t" << interestindollars << "\t\t" << interestpaidsofar << endl;
        /*cout << "Month " << month << endl;
        
        cout << "Balance = " << principle << endl;
        // calc specific monthly interest 
        cout << "Monthly Payment = " << monthlyPayment << endl; 
        
        cout << "Paid on Balance = " << PaidOnBalance << endl; 
        
        cout << "Interest payment = " << interestindollars << endl;
        
        cout << "Total Interest Paid = " << interestpaidsofar << endl; 
        */ 
       if(month %12 ==0)
        {
            drawline('$', 65);
        } 
        
        month++; 
        
        
        
    
 
    }

}
// make a header here for drawline

// make a function called printLoanPayments that
// takes in the loanAmount, annualInterest, and monthly payment
// (each of the above are doubles)

// print a header for multiple columns
// convert annualInterest to monthly interest



// keep updating the current balance
// keep updating the total Interest paid
// calculate the current month's 'interest accrued' (owed)
// calculate the amount of the loan balance that is 'paid down'.
// This is the amount that is paid toward the balance.
// Note: monthly payment = AmountPaidTowardBalance + interestAccrued.

// each month (starting at 1), print on a single line:
// Month  Balance Payment PaidOnBalance Interest and  Total Int. Paid
// until the Balance is 0

// Reject a monthly payment that is not able to cover at least the first 
// month's interest.

// Remember to print so that dollars and cents are shown

// Copy your drawLine function here


int main(){
    cout << setprecision(2) << fixed;
    double loanAmount, annualInterest, monthlyPayment;
	cout << "What is the loan amount? ";
	cin >> loanAmount;
	
	cout << "What is the annual interest? Type answer as a decimal (.1 for 10%, etc) ";
	cin >> annualInterest;
	if(annualInterest >= .25)
	{
	    cout << "Interest greater than 25% is illegal and is called 'criminal usury'." << endl << "Enter an interest rate less than 25%." << endl;
	    cin >> annualInterest;
	}
	
	cout << "What is the monthly payment? ";
	cin >> monthlyPayment;
	cout << endl; 
	if (monthlyPayment < ((annualInterest/12)* loanAmount))
	{
	    cout << "ERROR: monthly payment must be greater than " << ((annualInterest/12)* loanAmount) << " Please rerun with larger payment. Goodbye.";
	    return 0;
	}
    
    printLoanPayments(loanAmount, annualInterest, monthlyPayment);
	
	
	return 0;
}




        
