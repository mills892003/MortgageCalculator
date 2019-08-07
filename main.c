//  Customized Loan Amortization Table
//
//  Created by Milan Patel on 2/21/18.
//  Copyright © 2018 Milan Patel. All rights reserved.

#include <stdio.h>
#include <math.h>

int main(void)
{
    // Welcome statement
    printf("Custimized Loan Amortization Table Program\n\n");
    
    //  define variables
    float
    annualinterest,
    monthlyinterest;
    int totalpayments;
    float borrowedamount,
    monthlypayment,
    // variables for interest calc
    topformula,
    bottomformula,
    bottomp1,
    // payment variables
    intpay = 0,
    princepay = 0;
    
    // gather borrowed amount, annual interest and number of payments from users
    
    printf("Enter borrowed amount : $");
    scanf("%f" , &borrowedamount);
    printf("Enter annual interest rate (.06 = 6 percent) : ");
    scanf("%f" , &annualinterest);
    printf("Enter number of total payments: ");
    scanf("%d" , &totalpayments);
    
    // compute monthly interest, and monthly payment amount
    monthlyinterest = annualinterest / 12;
    topformula = borrowedamount * monthlyinterest;
    bottomp1 = pow(1+monthlyinterest, -totalpayments);
    bottomformula = ((1 - bottomp1));
    
    monthlypayment = topformula/bottomformula;
    monthlypayment = roundf(monthlypayment*100)/100;
    // display general terms
    
    printf("\nPrinciple         $%.2f      Payment    $%.2f", borrowedamount, monthlypayment);
    printf("\nAnnual Interest    %.1f%%         Term       %d months\n\n\n", annualinterest*100, totalpayments);
    
    
// display amortization table

    printf("   Payment    Interest      Principal      Princiciple\n");
    printf("                                             Balance\n");
    printf("-----------------------------------------------------------\n");
    int start;
    for  (start = 1;
          totalpayments >= start;
          start += 1) {

        intpay = roundf(monthlyinterest * borrowedamount*100)/100;
        princepay = monthlypayment - intpay;
        if(start < totalpayments){
                printf("%4c%3d%6c%6.2f", ' ', start, ' ', intpay);
                printf("%10c%.2f%5c%12.2f\n", ' ', monthlypayment - intpay, ' ', borrowedamount-princepay);
        }
        else
        {
            printf("%4c%3d%6c%6.2f", ' ', start, ' ', intpay);
            printf("%10c%.2f%5c%12.2f\n", ' ', borrowedamount, ' ', borrowedamount-princepay);
        }
        borrowedamount = borrowedamount - princepay;
      

    }
    
    printf("\nFinal payment:   $%.2f", borrowedamount + intpay+princepay);
   // getch(0);

    return(0);
}


