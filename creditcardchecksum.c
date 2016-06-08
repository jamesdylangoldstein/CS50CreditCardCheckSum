//
//  CS50UpdatedLuhn.c
//  CS50UpdatedLuhn
//
//  Created by James Dylan Goldstein on 6/7/16.
//  Rewrote my Luhn's algorithm psetwith functions and shorter/cleaner code
//  Shortening repeated portions with exponents and loops

#include <stdio.h>
#include <string.h>
#include "cs50.h"

unsigned long long Exponent(unsigned long long base, unsigned long long exponent);
unsigned long long NumDigits(unsigned long long creditcardnum);
unsigned long long DigitAssigner(unsigned long long *digitsarray, unsigned long long creditcardnum);
unsigned long long PrintCardType(unsigned long long *digitsarray, unsigned long long creditcardlength);
unsigned long long DoubleEveryOtherDigit(unsigned long long *digitsarray);
unsigned long long SumDigits(unsigned long long *digitsarray);

unsigned long long creditcardlength, creditcardnum, base, exponent;
long long firstsumdigits;

int main(int argc, const char * argv[])
{
    printf("Type a credit card number: ");
    creditcardnum = GetLongLong();
    creditcardlength = NumDigits(creditcardnum);
    unsigned long long digitsarray[creditcardlength];

    long long timesninemodzero, finalsum;

    // Assign each number of the CC to a spot in an array
    DigitAssigner(digitsarray, creditcardnum);
    
    // Identify the type of credit card
    PrintCardType(digitsarray, creditcardlength);
    
    // Starting with the right-most digit, double that digit and do that to every other digit
    // Then if the new doubled number is two digits (example: 7 * 2 = 14)
    // Make the new doubled number one digit by adding both digits together (7 * 2 = 1 + 4)
    // counterc is -1 because a 16 digit card becomes 0-15
    DoubleEveryOtherDigit(digitsarray);
    
    // Sum all the new doubled digits together and all of the remaining original digits
    // Record this sum and leave it for later
    firstsumdigits = SumDigits(digitsarray);
    
    // Create a new variable with the same number as the previous sum
    // Multiply that number by 9 and then find the remainder when divided by 10
    timesninemodzero = firstsumdigits * 9 % 10;
    
    // Take the remainder and added to the saved sum from earlier
    finalsum = firstsumdigits + timesninemodzero;
    
    // If the new final sum divides evenly by 10, it's a valid credit card.
    if (finalsum % 10 == 0)
    {
        printf("This is a valid credit card.");
    }
    else
    {
        printf("This is not a valid credit card.");
    }
    
    return 0;
}

// Function for exponentiation, to shorten numbers in code and allow for looping
unsigned long long Exponent(unsigned long long base, unsigned long long exponent)
{
    if (exponent == 0)
    {
       return 1;
    }
    else if (exponent == 1)
    {
        return base;
    }
    else
    {
        unsigned long long result = base;
        for (unsigned long long counter = 2; counter <= exponent; counter++)
        {
            result *= base;
        }
        return result;
    }
    
}

// Function that finds the number of digits in a long number
unsigned long long NumDigits(unsigned long long creditcardnum)
{
    unsigned long long digitcounter;
    
    if (creditcardnum <= 0)
        return 0;
    else
    {
        for (digitcounter = 1; digitcounter <= 19; digitcounter++)
        {
            if (creditcardnum < Exponent(10, digitcounter))
                return digitcounter;
        }
    }
    return 0;
}

// Assigns each digit of the credit card number to a place in an array
unsigned long long DigitAssigner(unsigned long long *digitsarray, unsigned long long creditcardnum)
{
    unsigned long long countera;
    unsigned long long creditcardmanip = creditcardnum;
    long long counterb = creditcardlength - 1;
    
    for (countera = 0; countera < creditcardlength; countera++)
    {
        digitsarray[countera] = creditcardmanip/Exponent(10, counterb);
        creditcardmanip = creditcardmanip - (digitsarray[countera]*Exponent(10, counterb));
        counterb--;
    }
    return 0;
}

// Function that identifies the type of credit card
unsigned long long PrintCardType(unsigned long long *digitsarray, unsigned long long creditcardlength)
{
    if ((digitsarray[0] == 3 && digitsarray[1] == 4) || (digitsarray[0] == 3 && digitsarray[1] == 7))
    {
        if (creditcardlength == 15)
        {
            printf("This is an American Express card.\n");
        }
        else
        {
            printf("Not a known credit card brand.\n");
        }
    }
    else if (digitsarray[0] == 4)
    {
        if (creditcardlength == 13 || creditcardlength == 16)
        {
            printf("This is a Visa card.\n");
        }
        else
        {
            printf("Not a known credit card brand.\n");
        }
    }
    else if ((digitsarray[0] == 5 && digitsarray[1] == 1) || (digitsarray[1] == 2 || digitsarray[1] == 3) || (digitsarray[1] == 4) || (digitsarray[1] == 5))
    {
        if (creditcardlength == 16)
        {
            printf("This is a MasterCard.\n");
        }
        else
        {
            printf("Not a known credit card brand.\n");
        }
    }
    return 0;
}

unsigned long long DoubleEveryOtherDigit(unsigned long long *digitsarray)
{
    long long counterc = creditcardlength - 1;
    
    while (counterc >= 0)
    {
        digitsarray[counterc] *= 2;
        if(digitsarray[counterc] > 9)
        {
            digitsarray[counterc] = digitsarray[counterc] % 10 + 1;
        }
        counterc -= 2;
    }
    
    return 0;
}

unsigned long long SumDigits(unsigned long long *digitsarray)
{
    for (int counterd = 0; counterd < creditcardlength; counterd++)
    {
        firstsumdigits += digitsarray[counterd];
    }
    return firstsumdigits;
}
