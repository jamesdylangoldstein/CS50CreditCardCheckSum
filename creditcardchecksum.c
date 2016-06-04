//
//  creditcardchecksum.c
//  CS50CreditCardCheckSum
//
//  Created by James Dylan Goldstein on 6/3/16.
//  Copyright © 2016 James Dylan Goldstein. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int main(void) {
    unsigned long long int creditcard, creditcardlength, digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8, digit9, digit10, digit11, digit12, digit13, digit14, digit15, digit16, digit1db, digit2db, digit3db, digit4db, digit5db, digit6db, digit7db, digit8db, digit9db, digit10db, digit11db, digit12db, digit13db, digit14db, digit15db, digit16db,creditcardmanip, luhnalgone, luhnalgtwo, luhnalgthree;
    
    do{
        printf("Type your credit card number.\nMake sure it is 16 digits:\n");

        creditcard = GetLongLong();

        if (creditcard <= 0) creditcardlength = 0;
        else if (creditcard < 10 && creditcard > 0) creditcardlength = 1;
        else if (creditcard < 100 && creditcard >= 10) creditcardlength = 2;
        else if (creditcard < 1000 && creditcard >= 100) creditcardlength = 3;
        else if (creditcard < 10000 && creditcard >= 1000) creditcardlength = 4;
        else if (creditcard < 100000 && creditcard >= 10000) creditcardlength = 5;
        else if (creditcard < 1000000 && creditcard >= 100000) creditcardlength = 6;
        else if (creditcard < 10000000 && creditcard >= 1000000) creditcardlength = 7;
        else if (creditcard < 100000000 && creditcard >= 10000000) creditcardlength = 8;
        else if (creditcard < 1000000000 && creditcard >= 100000000) creditcardlength = 9;
        else if (creditcard < 10000000000 && creditcard >= 1000000000) creditcardlength = 10;
        else if (creditcard < 100000000000 && creditcard >= 10000000000) creditcardlength = 11;
        else if (creditcard < 1000000000000 && creditcard >= 100000000000) creditcardlength = 12;
        else if (creditcard < 10000000000000 && creditcard >= 1000000000000) creditcardlength = 13;
        else if (creditcard < 100000000000000 && creditcard >= 10000000000000) creditcardlength = 14;
        else if (creditcard < 1000000000000000 && creditcard >= 100000000000000) creditcardlength = 15;
        else if (creditcard < 10000000000000000 && creditcard >= 1000000000000000) creditcardlength = 16;
        else if (creditcard < 100000000000000000 && creditcard >= 10000000000000000) creditcardlength = 17;
        else if (creditcard < 1000000000000000000 && creditcard >= 100000000000000000) creditcardlength = 18;
        else creditcardlength = 19;
    }while(creditcardlength != 13 && creditcardlength != 15 && creditcardlength != 16);
  

    printf("You entered %lld \n", creditcard);
    
    creditcardmanip = creditcard;
    
    digit1 = creditcardmanip/1000000000000000;
    creditcardmanip = creditcardmanip - (digit1*1000000000000000);
    digit2 = creditcardmanip/100000000000000;
    creditcardmanip = creditcardmanip - (digit2*100000000000000);
    digit3 = creditcardmanip/10000000000000;
    creditcardmanip = creditcardmanip - (digit3*10000000000000);
    digit4 = creditcardmanip/1000000000000;
    creditcardmanip = creditcardmanip - (digit4*1000000000000);
    digit5 = creditcardmanip/100000000000;
    creditcardmanip = creditcardmanip - (digit5*100000000000);
    digit6 = creditcardmanip/10000000000;
    creditcardmanip = creditcardmanip - (digit6*10000000000);
    digit7 = creditcardmanip/1000000000;
    creditcardmanip = creditcardmanip - (digit7*1000000000);
    digit8 = creditcardmanip/100000000;
    creditcardmanip = creditcardmanip - (digit8*100000000);
    digit9 = creditcardmanip/10000000;
    creditcardmanip = creditcardmanip - (digit9*10000000);
    digit10 = creditcardmanip/1000000;
    creditcardmanip = creditcardmanip - (digit10*1000000);
    digit11 = creditcardmanip/100000;
    creditcardmanip = creditcardmanip - (digit11*100000);
    digit12 = creditcardmanip/10000;
    creditcardmanip = creditcardmanip - (digit12*10000);
    digit13 = creditcardmanip/1000;
    creditcardmanip = creditcardmanip - (digit13*1000);
    digit14 = creditcardmanip/100;
    creditcardmanip = creditcardmanip - (digit14*100);
    digit15 = creditcardmanip/10;
    creditcardmanip = creditcardmanip - (digit15*10);
    digit16 = creditcardmanip/1;
    creditcardmanip = creditcardmanip - (digit16*1);
    
    if((digit1 == 3 && digit2 == 4) || (digit1 == 3 && digit2 == 7)){
        printf("This is an American Express card.\n");
    }
    else if(digit1 == 4){
        printf("This is a Visa card.\n");
    }
    else if((digit1 == 5 && digit2 == 1) || (digit1 == 5 && digit2 == 2) || (digit1 == 5 && digit2 == 3) || (digit1 == 5 && digit2 == 4) || (digit1 == 5 && digit2 == 5)){
        printf("This is a MasterCard.\n");
    }
    
    digit1db = digit1*2;
    if(digit1db > 10){
        digit1db = (digit1db % 10) + 1;
    }
    digit2db = digit2*2;
    if(digit2db > 10){
        digit2db = (digit2db % 10) + 1;
    }
    digit3db = digit3*2;
    if(digit3db > 10){
        digit3db = (digit3db % 10) + 1;
    }
    digit4db = digit4*2;
    if(digit4db > 10){
        digit4db = (digit4db % 10) + 1;
    }
    digit5db = digit5*2;
    if(digit5db > 10){
        digit5db = (digit5db % 10) + 1;
    }
    digit6db = digit6*2;
    if(digit6db > 10){
        digit6db = (digit6db % 10) + 1;
    }
    digit7db = digit7*2;
    if(digit7db > 10){
        digit7db = (digit7db % 10) + 1;
    }
    digit8db = digit8*2;
    if(digit8db > 10){
        digit8db = (digit8db % 10) + 1;
    }
    digit9db = digit9*2;
    if(digit9db > 10){
        digit9db = (digit9db % 10) + 1;
    }
    digit10db = digit10*2;
    if(digit10db > 10){
        digit10db = (digit10db % 10) + 1;
    }
    digit11db = digit11*2;
    if(digit11db > 10){
        digit11db = (digit11db % 10) + 1;
    }
    digit12db = digit12*2;
    if(digit12db > 10){
        digit12db = (digit12db % 10) + 1;
    }
    digit13db = digit13*2;
    if(digit13db > 10){
        digit13db = (digit13db % 10) + 1;
    }
    digit14db = digit14*2;
    if(digit14db > 10){
        digit14db = (digit14db % 10) + 1;
    }
    digit15db = digit15*2;
    if(digit15db > 10){
        digit15db = (digit15db % 10) + 1;
    }
    digit16db = digit16*2;
    if(digit16db > 10){
        digit16db = (digit16db % 10) + 1;
    }
    
    if(creditcardlength == 13){
        luhnalgone = digit13db + digit12 + digit11db + digit10 + digit9db + digit8 + digit7db + digit6 + digit5db + digit4 + digit3db + digit2 + digit1db;
    }
    else if (creditcardlength == 15){
        luhnalgone = digit15db + digit14 + digit13db + digit12 + digit11db + digit10 + digit9db + digit8 + digit7db + digit6 + digit5db + digit4 + digit3db + digit2 + digit1db;
    }
    else if (creditcardlength == 16){
        luhnalgone = digit16db + digit15 + digit14db + digit13 + digit12db + digit11 + digit10db + digit9 + digit8db + digit7 + digit6db + digit5 + digit4db + digit3 + digit2db + digit1;
    }
    
    luhnalgtwo = (luhnalgone * 9) % 10;
    
    luhnalgthree = luhnalgone + luhnalgtwo;
    
    if(luhnalgthree % 10 == 0){
        printf("This is a valid credit card.");
    }
    else{
        printf("This is not a valid credit card.");
    }
        
}
