//  Created by Milan Patel 2/6/18


#include <stdio.h>
#include <math.h>

int main(void)
{
    /*  define variables  */
    double purchaseprice,
    downpayment,
    annualinterest,
    monthlyinterest,
    totalpayments,
    borrowedamount,
    monthlypayment,
    topformula,
    bottomformula,
    bottomp1;
    
    /* gather data from users  */
    printf("Enter purchase price: $");
    scanf("%lf" , &purchaseprice);
    printf("Enter down payment: $");
    scanf("%lf" , &downpayment);
    
    borrowedamount = purchaseprice - downpayment;
    
    printf("Enter annual interest rate (.06 = 6 percent) : ");
    scanf("%lf" , &annualinterest);
    
    monthlyinterest = annualinterest / 12;
    
    printf("Enter number of total payments: ");
    scanf("%lf" , &totalpayments);
    
    topformula = borrowedamount * monthlyinterest;
    bottomp1 = pow(1+monthlyinterest, -totalpayments);
    bottomformula = ((1 - bottomp1));
    
    monthlypayment = topformula/bottomformula;
    
    /* display mortgage results */
    
    printf("\nYou're total borrowed amount is $%.2lf\n", borrowedamount);
    printf("You're monthly payment amount is $%.2lf", monthlypayment);
    
    /* getch(0); */
    return(0);
}


