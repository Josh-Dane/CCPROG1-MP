#include <stdio.h>

void DisplayGreeting(){
    printf("\n\t************************************\n");
    printf("\t* WELCOME TO THE KOREAN FOOD STORE!*\n");
    printf("\t************************************\n\n");
}

int Menu_Options(){
    int nMenuChoices;
    do {
    printf("If you wish to see the menu please press [1]\n");
    printf("If you wish to proceed to order food, press [2]\n");
    printf("Enter number: ");
    scanf("%d", &nMenuChoices);
    if(nMenuChoices == 1 || nMenuChoices == 2){
        return nMenuChoices;
    } else if (nMenuChoices == 80808){
        printf("MAINTENANCE\n");
        return 0;
    } else printf("INVALID INPUT\n");
    } while (nMenuChoices != 1 && nMenuChoices != 2 && nMenuChoices != 80808);
    return 0;
}

int MenuDisplay(MenuChoice){
    char cChoice;
    do {
    if (MenuChoice == 1){
        printf("Korean Corndog \t\tPHP 140.00 (Original)\tPHP 150.00 (Mozzarella)\tPHP 150.00 (Potato)\n");
        printf("Bingsu \t\t\tPHP 300.00 (Regular)\tPHP 400.00 (Large)\n");
        printf("Gimbap \t\t\tPHP 100.00 (Tuna)\tPHP 120.00 (Cheese)\n\n");
        printf("Proceed to order? Press (N) or (n). Press (X) or (x) to cancel. ");
        scanf(" %c", &cChoice); 
        if(cChoice == 'n' || cChoice == 'N'){
            return cChoice;
        } else if (cChoice == 'x' || cChoice == 'X'){
            printf("\nORDER CANCELLED\n");
            return cChoice;
        } else {
            printf("\nINVALID INPUT\n\n");
        }
    } else return MenuChoice;
    } while (cChoice != 'x' && cChoice != 'X' && cChoice != 'n' && cChoice != 'N');
}

int Order_Menu(char cChosen, int MenuChoice, int *qtyK, int *qtyB, int *qtyG){
    char FoodChoice;
    do{
    if (MenuChoice == 2 || cChosen == 'n' || cChosen == 'N'){
        printf("Let's pick your food!\n");
        printf("Press [K] for Korean Corndog, press [B] for Bingsu, and press [G] for Gimbap. ");
        scanf(" %c", &FoodChoice);
        if (FoodChoice == 'K' || FoodChoice == 'k'){
            *qtyK += 1;
            printf("Korean Corndog added. Anything else? If nothing else, press N. \n");
        } else if (FoodChoice == 'B' || FoodChoice == 'b'){
            *qtyB += 1;
            printf("Bingsu added. Anything else? If nothing else, press N.\n");
        } else if (FoodChoice == 'G' || FoodChoice == 'g'){
            *qtyG += 1;
            printf("Gimbap added. Anything else? If nothing else, press N.\n");
        } else if (FoodChoice == 'n' || FoodChoice == 'N'){
            return FoodChoice;
        } else {
            printf("\nINVALID INPUT\n");
        }
    }
    } while (FoodChoice != 'N' && FoodChoice != 'n');
    return 0;
}

int FoodType (int qtyK, int qtyB, int qtyG, int *nOrigKD, int *nMozKD, int *nPotKD, int *nRegBingsu, int *nLargeBingsu, int *nTunaGimbap, int *nCheeseGimbap){
    char cCorndog, cBingsu, cGimbap;
    int nCorndog = qtyK, nBingsu = qtyB, nGimbap = qtyG;
    while (nCorndog > 0){
        printf("Which Korean Corndog do you like? Press [O] for Original, press [M] for Mozzarella, and press [P] for potato ");
        scanf(" %c", &cCorndog);
        if (cCorndog == 'O' || cCorndog == 'o'){
            *nOrigKD += 1;
            printf("Original Korean Corndog selected\n");
            nCorndog--;
        } else if (cCorndog == 'M' || cCorndog == 'm'){
            *nMozKD += 1;
            printf("Mozzarella Korean Corndog selected\n");
            nCorndog--;
        } else if (cCorndog == 'p' || cCorndog == 'P'){
            *nPotKD += 1;
            printf("Potato Korean Corndog selected\n");
            nCorndog--;
        }else printf("INVALID INPUT\n");
    }
    while (nBingsu > 0){
        printf("What will be the size of your Bingsu? Press [R] for regular and Press [L] for large. ");
        scanf(" %c", &cBingsu);
        if(cBingsu == 'r' || cBingsu == 'R'){
            *nRegBingsu += 1;
            printf("Regular Bingsu selected.\n");
            nBingsu--;
        } else if (cBingsu == 'l' || cBingsu == 'L'){
            *nLargeBingsu += 1;
            printf("Large Bingsu selected.\n");
            nBingsu--;
        } else printf("INVALID INPUT\n");
    }
    while (nGimbap > 0){
        printf("What kind of Gimbap would you like? Press [T] for Tuna. Press [C] for Cheese. ");
        scanf(" %c", &cGimbap);
        if(cGimbap == 't' || cGimbap == 'T'){
            *nTunaGimbap += 1;
            printf("Tuna Gimbap selected.\n");
            nGimbap--;
        } else if (cGimbap == 'C' || cGimbap == 'c'){
            *nCheeseGimbap += 1;
            printf("Cheese Gimbap selected.\n");
            nGimbap--;
        } else printf("INVALID INPUT\n");
    }
    return 0;
}

float CalculatingPrices(int nOrigKD, int nMozKD, int nPotKD, int nRegBingsu, int nLargeBingsu, int nTunaGimbap, int nCheeseGimbap, float *fOrigKD, float *fMozKD, float *fPotKD, float *fRegBingsu, float *fLargeBingsu, float *fTunaGimbap, float *fCheeseGimbap){
    if (nOrigKD > 0){
        *fOrigKD = nOrigKD * 140.00;
    }
    if (nMozKD > 0){
        *fMozKD = nMozKD * 150.00;
    }
    if (nPotKD > 0){
        *fPotKD = nPotKD * 150.00;
    }
    if (nRegBingsu > 0){
        *fRegBingsu = nRegBingsu * 300.00;
    }
    if (nLargeBingsu > 0){
        *fLargeBingsu = nLargeBingsu * 400.00;
    }
    if (nTunaGimbap > 0){
        *fTunaGimbap = nTunaGimbap * 100.00;
    }
    if (nCheeseGimbap > 0){
        *fCheeseGimbap = nCheeseGimbap * 120.00;
    }
    return 0;
}

float PrintPrices(float fOrigKD, float fMozKd, float fPotKD, float fRegBingsu, float fLargeBingsu, float fTunaGimbap, float fCheeseGimbap){
    float fTotalPrice = fOrigKD + fMozKd + fPotKD + fRegBingsu + fLargeBingsu + fTunaGimbap + fCheeseGimbap;
    printf("\n\nYOUR TOTAL PRICE IS:\n");
    if(fOrigKD > 0){
        printf("Original Korean Corndog: \t\t%.2f\n", fOrigKD);
    }
    if (fMozKd > 0){
        printf("Mozzarella Korean Corndog: \t\t%.2f\n", fMozKd);
    }
    if (fPotKD > 0){
        printf("Potato Korean Corndog: \t\t\t%.2f\n", fPotKD);
    }
    if (fRegBingsu > 0){
        printf("Regular Bingsu: \t\t\t%.2f\n",fRegBingsu);
    }
    if (fLargeBingsu > 0){
        printf("Large Bingsu: \t\t\t\t%.2f\n", fLargeBingsu);
    }
    if (fTunaGimbap > 0){
        printf("Tuna Gimbap: \t\t\t\t%.2f\n", fTunaGimbap);
    }
    if (fCheeseGimbap > 0){
        printf("Cheese Gimbap: \t\t\t\t%.2f\n", fCheeseGimbap);
    }
    printf("--------------------------------------------------\n");
    printf("total:\t\t\t\t\t%.2f\n", fTotalPrice);
    return fTotalPrice;
}

float Payment(float fTotalPayment, float *fPayment){
    int nDenomination;
    float fDifference = fTotalPayment;

   do{
   while(fDifference > 0){
    printf("To pay for your order, you may choose the following:\n");
    printf("Press [1] for 1000 pesos. Press [2] for 500 pesos. Press [3] for 100 pesos. Press [4] for 50 pesos. Press [5] for 20 pesos.\n");
    printf("Press [6] for 10 pesos. Press [7] for 5 pesos. Press [8] for 1 peso.\n");
    scanf("%d", &nDenomination);
    
    switch (nDenomination){
        case 1:
        printf("You have paid 1000 pesos\n");
        fDifference -= 1000;
        *fPayment += 1000;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 2: 
        printf("You have paid 500 pesos\n");
        fDifference -= 500;
        *fPayment += 500;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 3:
        printf("You have paid 100 pesos\n");
        fDifference -= 100;
        *fPayment += 100;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 4:
        printf("You have paid 50 pesos\n");
        fDifference -= 50;
        *fPayment += 50;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 5:
        printf("You have paid 20 pesos\n");
        fDifference -= 20;
         *fPayment += 20;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 6:
        printf("You have paid 10 pesos\n");
        fDifference -= 10;
        *fPayment += 10;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 7:
        printf("You have paid 5 pesos\n");
        fDifference -= 5;
        *fPayment += 5;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        case 8:
        printf("You have paid 1 peso\n");
        fDifference -= 1;
        *fPayment += 1;
        if (fDifference > 0){
            printf("You have %.2f pesos remaining.\n", fDifference);
        }
        break;

        default:
        printf("INVALID INPUT\n");
    }
   }
   } while (nDenomination > 8 && nDenomination < 1);
   return fDifference;
}

void PrintReceipt(float fTotalPayment, float fDifference, float fPayment, float fOrigKD, float fMozKD, float fPotKD, float fRegBingsu, float fLargeBingsu, float fTunaGimbap, float fCheeseGimbap, int *ReceiptNumber){
    float fChange = 0;
    fChange = fPayment - fTotalPayment;
    *ReceiptNumber += 1;
    printf("\n\nYOUR OFFICIAL RECEIPT\t\t\tReceipt Number#%d\n", *ReceiptNumber);
     if(fOrigKD > 0){
        printf("Original Korean Corndog: \t\t%.2f\n", fOrigKD);
    }
    if (fMozKD > 0){
        printf("Mozzarella Korean Corndog: \t\t%.2f\n", fMozKD);
    }
    if (fPotKD >0){
        printf("Potato Korean Corndog: \t\t\t%.2f\n", fPotKD);
    }
    if (fRegBingsu > 0){
        printf("Regualr Bingsu: \t\t\t%.2f\n",fRegBingsu);
    }
    if (fLargeBingsu > 0){
        printf("Large Bingsu: \t\t\t\t%.2f\n", fLargeBingsu);
    }
    if (fTunaGimbap > 0){
        printf("Tuna Gimbap: \t\t\t\t%.2f\n", fTunaGimbap);
    }
    if (fCheeseGimbap > 0){
        printf("Cheese Gimbap: \t\t\t\t%.2f\n", fCheeseGimbap);
    }
    printf("--------------------------------------------------\n");
    printf("Total Price: \t\t\t\t%.2f\n", fTotalPayment);
    printf("Total Payment: \t\t\t\t%.2f\n", fPayment);
    printf("Change: \t\t\t\t%.2f\n", fChange);
}

/*void ResetPrice(float fTotalPayment, float fDifference, float fPayment, float fOrigKD, float fMozKD, float fPotKD, float fRegBingsu, float fLargeBingsu, float fTunaGimbap, float fCheeseGimbap, int nOrigKD, int nMozKD, int nPotKD, int nRegBingsu, int nLargeBingsu, int nTunaGimbap, int nCheeseGimbap, int qtyK, int qtyB, int qtyG){
    fTotalPayment = 0;
    fDifference = 0;
    fPayment = 0;
    fOrigKD = 0; fMozKD = 0; fPotKD = 0; fRegBingsu = 0; fLargeBingsu = 0; fTunaGimbap = 0; fCheeseGimbap = 0; 
    nOrigKD = 0; nMozKD = 0; nPotKD = 0; nRegBingsu = 0; nLargeBingsu = 0; nTunaGimbap = 0; nCheeseGimbap = 0;
    qtyB = 0; qtyG = 0; qtyK = 0;
}*/

int main(){
    int MenuChoice, nMenuChoices, MenuOptions, qtyK = 0, qtyB = 0, qtyG = 0, nOrigKD = 0, nMozKD = 0, nPotKD = 0,nRegBingsu = 0, nLargeBingsu = 0, nTunaGimbap = 0, nCheeseGimbap = 0, ReceiptNumber = 0;
    float fOrigKD = 0, fMozKD = 0, fPotKD = 0, fRegBingsu = 0, fLargeBingsu = 0, fTunaGimbap = 0, fCheeseGimbap = 0, fTotalPayment, fPayment = 0, fDifference;
    char cChosen;
    do{
    do{
    fTotalPayment = 0;
    fDifference = 0;
    fPayment = 0;
    fOrigKD = 0; fMozKD = 0; fPotKD = 0; fRegBingsu = 0; fLargeBingsu = 0; fTunaGimbap = 0; fCheeseGimbap = 0; 
    nOrigKD = 0; nMozKD = 0; nPotKD = 0; nRegBingsu = 0; nLargeBingsu = 0; nTunaGimbap = 0; nCheeseGimbap = 0;
    qtyB = 0; qtyG = 0; qtyK = 0;
    DisplayGreeting();
    MenuChoice = Menu_Options();
    cChosen = MenuDisplay(MenuChoice);
    } while (cChosen == 'x' || cChosen == 'X');
    Order_Menu(cChosen, MenuChoice, &qtyK, &qtyB, &qtyG);
    FoodType(qtyK, qtyB, qtyG, &nOrigKD, &nMozKD, &nPotKD, &nRegBingsu, &nLargeBingsu, &nTunaGimbap, &nCheeseGimbap);
    CalculatingPrices(nOrigKD, nMozKD, nPotKD, nRegBingsu, nLargeBingsu, nTunaGimbap, nCheeseGimbap, &fOrigKD, &fMozKD, &fPotKD, &fRegBingsu, &fLargeBingsu, &fTunaGimbap, &fCheeseGimbap);
    fTotalPayment = PrintPrices(fOrigKD, fMozKD, fPotKD, fRegBingsu, fLargeBingsu, fTunaGimbap, fCheeseGimbap);
    Payment(fTotalPayment, &fPayment);
    PrintReceipt(fTotalPayment, fDifference, fPayment, fOrigKD, fMozKD, fPotKD, fRegBingsu, fLargeBingsu, fTunaGimbap, fCheeseGimbap, &ReceiptNumber);
    } while (fPayment > fTotalPayment);
}