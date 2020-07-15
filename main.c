#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h> //to get date

void displayCompanyName();//method for display company name

void menuDriven(int *);//method for display menu

void switchCase(int *optionSelceted);

void addItemDetails();//method for add items into a file

void readItemDetails(int *);//method for read items from a file

void displayItemDetails();//method for read items from a file

void updateItemDetails();////method for update items of a file

void updateItemDetailsUnloading();////method for update items of a file

int getItemDetails(int id);//method for get items from a file to use

void storeLoadingDetails();//method for add items Details into a file

void displayLoadingDetails();//method for read loaded items from a file

void readLoadingDetails(int *);//method for read loaded items from a file

void storeUnloadingDetails();

void readUnloadingDetails(int *);

int main( )
{
    system("color 2");

    int number;
    int option;
    int numberNew;
    int arr[3][2] = {};

    int itemID,numberOfItems;

    displayCompanyName();

    menuDriven(&option);



    return 0;
}

void displayCompanyName()
{

    printf("\n----------------------------------------------------------------------------------\n");
    printf("\n----------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\tXYZ Distributors\n");
    printf("\n----------------------------------------------------------------------------------\n");
    printf("\n----------------------------------------------------------------------------------\n");


}

void menuDriven(int *opt)
{
    system("cls");//clear screen
    displayCompanyName();
    printf("\n\n\n");
    printf("1. Add item Details\n");
    printf("2. Read item Details\n");
    printf("3. Store Loading Details \n");
    printf("4. Read Loading Details\n");
    printf("5. Store Unloading Details\n");
    printf("6. Read Unloading Details\n");
    printf("7. Exit\n\n\n");
    printf("Enter your choice :  ");
    scanf("%d", opt);

    switchCase(opt);
}

void switchCase(int *optionSelceted)
{
  switch(*optionSelceted)
    {
    case 1:
        addItemDetails();
        menuDriven(optionSelceted);
        break;
    case 2:
        readItemDetails(optionSelceted);
        menuDriven(optionSelceted);
        break;
    case 3:
        storeLoadingDetails();
        menuDriven(optionSelceted);
        break;
    case 4:
        readLoadingDetails(optionSelceted);
        menuDriven(optionSelceted);
        break;
    case 5:
        storeUnloadingDetails();
        menuDriven(optionSelceted);
        break;
    case 6:
        readUnloadingDetails(optionSelceted);
        menuDriven(optionSelceted);
        break;
    case 7:
        exit(0);

    default:
        break;
    }

}

void addItemDetails()
{
    system("cls");
    displayCompanyName();
    printf("\nAdd Item Details\n\n");

    int itemID;
    int price;
    int stockAmout;


    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","a");

    if(cfPtr == NULL)
    {
        printf("Cannot create file\n");
        return -1;
    }

    char i = 'y';
    while(i=='y')
    {
        displayItemDetails();

        printf("\n");

        printf("Enter item ID : ");
        scanf("%d", &itemID);

        printf("Enter Price for the Item No.%d : ",itemID);
        scanf("%d", &price);

        printf("Enter stock amount for the Item No.%d : ",itemID);
        scanf("%d", &stockAmout);

        fprintf(cfPtr,"%d\t%d\t%d\n",itemID,price,stockAmout);
        //save itemID,price,stock amount into the itemDetails text file

        printf("Do you want to add another item ( y for yes / n for no ): ");
        scanf(" %c", &i);

    }

    fclose(cfPtr);

}

void displayItemDetails()
{
printf("\n\n");

    int itemDetails[50][3],priceOfGivenItemID;

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);

    printf("ItemID\tPrice(Rs.)\tAmount available in the stock\n");

    while(!feof(cfPtr))
    {
        printf("%d\t%d\t\t%d\n",itemDetails[i][0],itemDetails[i][1],itemDetails[i][2]);
        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);

}

void readItemDetails(int *opt)
{
    printf("\n\n");

    int itemDetails[50][3],priceOfGivenItemID;

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);

    printf("ItemID\tPrice(Rs.)\tAmount available in the stock\n");

    while(!feof(cfPtr))
    {
        printf("%d\t%d\t\t%d\n",itemDetails[i][0],itemDetails[i][1],itemDetails[i][2]);
        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);

    int selectOption;

    printf("\nPress 1 - Back to Main Menu : ");
    scanf("%d",&selectOption);

    if(selectOption == 1 )
    {
        menuDriven(opt);
    }

}

void updateItemDetails(int id, int amount)
{

    int itemDetails[50][3];

    int i=0;

    /*Getting Details and store it into the itemDetails array*/

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);

    while(!feof(cfPtr))
    {

        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);//close the connection


     /*store updated item Details into the itemDetails array and save it in the itemDetails text file*/


    cfPtr = fopen("itemDetails.txt","w");

    for(int j=0;j<i;j++)
    {
        if(itemDetails[j][0] == id)
        {
            itemDetails[j][2] = itemDetails[j][2] - amount;
        }
    }

    for(int j=0;j<i;j++)
    {
        //store details into the file
        //itemID, price, amount
        fprintf(cfPtr,"%d\t%d\t%d\n",itemDetails[j][0],itemDetails[j][1],itemDetails[j][2]);
    }


    fclose(cfPtr);//close the connection

}

void updateItemDetailsUnloading(int id, int amount)
{

    int itemDetails[50][3];

    int i=0;

    /*Getting Details and store it into the itemDetails array*/

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);

    while(!feof(cfPtr))
    {

        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);//close the connection


     /*store updated item Details into the itemDetails array and save it in the itemDetails text file*/


    cfPtr = fopen("itemDetails.txt","w");

    for(int j=0;j<i;j++)
    {
        if(itemDetails[j][0] == id)
        {
            itemDetails[j][2] = itemDetails[j][2] + amount;
        }
    }

    for(int j=0;j<i;j++)
    {
        //store details into the file
        //itemID, price, amount
        fprintf(cfPtr,"%d\t%d\t%d\n",itemDetails[j][0],itemDetails[j][1],itemDetails[j][2]);
    }


    fclose(cfPtr);//close the connection

}

int getItemDetails(int id)
{

    int itemDetails[50][2],priceOfGivenItemID;

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);


    while(!feof(cfPtr))
    {
        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);


    for(int i = 0 ; i < 50;i++)
    {
        if(itemDetails[i][0] == id)
        {
            priceOfGivenItemID = itemDetails[i][1];
        }
    }

    return priceOfGivenItemID;
}

void storeLoadingDetails()
{
    system("cls");//clear screen

    displayCompanyName();
    printf("\nStore Loading Details\n");

    int salesDetailsLoading[1][7];

    /*
    salesDetailsLoading[0][0] = item id
    salesDetailsLoading[0][1] = number of items loading
    salesDetailsLoading[0][2] = Total Price ( price of a item * number of items loading )
    salesDetailsLoading[0][3] = vehicle id
    salesDetailsLoading[0][4] = year
    salesDetailsLoading[0][5] = month
    salesDetailsLoading[0][6] = day
    */

    int price; // price of a item
    char option = 'y';

    printf("\n");

    FILE *cfPtr;


    cfPtr = fopen("itemsLoadingReport.txt","a");

    if(cfPtr == NULL)
    {
        printf("Cannot create file\n");
        return -1;
    }



    while(option=='y')
    {


        displayItemDetails(); //display details of items


        printf("\n");
        printf("Please input item number : ");
        scanf("%d", &salesDetailsLoading[0][0]); //input item id

        price = getItemDetails(salesDetailsLoading[0][0]); //get the price of input id number

        printf("Please input No of items loading for item number %d : ",salesDetailsLoading[0][0]);
        scanf("%d", &salesDetailsLoading[0][1]); // input number of items loading for the given id number

        updateItemDetails(salesDetailsLoading[0][0],salesDetailsLoading[0][1]); //call updateItemDetails function to update item amount in the itemDetails text file

        salesDetailsLoading[0][2] = price * salesDetailsLoading[0][1]; //calculate the total price

        printf("Please input vehicle ID :  ");
        scanf("%d", &salesDetailsLoading[0][3]); // input vehicle

        printf("Please input current year ");
        scanf("%d", &salesDetailsLoading[0][4]); // input current year

        printf("Please input current month ");
        scanf("%d", &salesDetailsLoading[0][5]); // input current month

        printf("Please input current date ");
        scanf("%d", &salesDetailsLoading[0][6]); // input current date

        /*display details*/
        printf("price of item %d is %d\n",salesDetailsLoading[0][0],price);
        printf("Total price of item %d is %d\n",salesDetailsLoading[0][0],salesDetailsLoading[0][2]);

        for(int i = 0; i < 7; i++)
        {
            /*saving itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
            fprintf(cfPtr,"%d\t",salesDetailsLoading[0][i]);
        }

        fprintf(cfPtr,"\n");



        printf("\n");
        printf("Do you loading another item (y/n) : ");//ask to enter another item
        scanf(" %c",&option);
    }



    fclose(cfPtr);



}

void readLoadingDetails(int *opt)
{
    system("cls");
    displayCompanyName();
    printf("\nLoading Details\n\n");

    int loadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsLoadingReport.txt","r");
    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);

    printf("ItemID\tnumber of Items\t Total Price\tvehicle\t date\n");

    while(!feof(cfPtr))
    {
        printf("%d\t%d\t\t %d\t\t%d\t %d-%d-%d\n",loadingitemDetails[i][0],loadingitemDetails[i][1],loadingitemDetails[i][2],loadingitemDetails[i][3],loadingitemDetails[i][4],loadingitemDetails[i][5],loadingitemDetails[i][6]);
        i++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);
    }

    fclose(cfPtr);


    int selectOption;

    printf("\nPress 1 - Back to Main Menu : ");
    scanf("%d",&selectOption);

    if(selectOption == 1 )
    {

        menuDriven(opt);
    }

}


void displayLoadingDetails()
{

    printf("\nLoading Details\n\n");

    int loadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsLoadingReport.txt","r");
    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);

    printf("ItemID\tnumber of Items\t Total Price\tvehicle\t date\n");

    while(!feof(cfPtr))
    {
        printf("%d\t%d\t\t %d\t\t%d\t %d-%d-%d\n",loadingitemDetails[i][0],loadingitemDetails[i][1],loadingitemDetails[i][2],loadingitemDetails[i][3],loadingitemDetails[i][4],loadingitemDetails[i][5],loadingitemDetails[i][6]);
        i++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);
    }

    fclose(cfPtr);



}


void storeUnloadingDetails()
{
    system("cls");//clear screen

    displayCompanyName();


    int salesDetailsUnloading[1][6];

    /*
    salesDetailsLoading[0][0] = item id
    salesDetailsLoading[0][1] = number of items unloading
    salesDetailsLoading[0][2] = vehicle id
    salesDetailsLoading[0][3] = year
    salesDetailsLoading[0][4] = month
    salesDetailsLoading[0][5] = day
    */

    char option = 'y';

    printf("\n");

    FILE *cfPtr;


    cfPtr = fopen("itemsUnloadingReport.txt","a");

    if(cfPtr == NULL)
    {
        printf("Cannot create file\n");
        return -1;
    }



    while(option=='y')
    {


        displayLoadingDetails(); //display details of items

        printf("-------------------------------------------------------");
        printf("\nStore Unloading Details\n");

        printf("\n");
        printf("Please input item number : ");
        scanf("%d", &salesDetailsUnloading[0][0]); //input item id

        printf("Please input No of items unloading for item number %d : ",salesDetailsUnloading[0][0]);
        scanf("%d", &salesDetailsUnloading[0][1]); // input number of items loading for the given id number

        updateItemDetailsUnloading(salesDetailsUnloading[0][0],salesDetailsUnloading[0][1]); //call updateItemDetails function to update item amount in the itemDetails text file

        printf("Please input vehicle ID :  ");
        scanf("%d", &salesDetailsUnloading[0][2]); // input vehicle

        printf("Please input current year ");
        scanf("%d", &salesDetailsUnloading[0][3]); // input current year

        printf("Please input current month ");
        scanf("%d", &salesDetailsUnloading[0][4]); // input current month

        printf("Please input current date ");
        scanf("%d", &salesDetailsUnloading[0][5]); // input current date


        for(int i = 0; i < 6; i++)
        {
            /*saving itemID,number of Items,vehicle id,year,month,date into the itemsUnloadingReport text file*/
            fprintf(cfPtr,"%d\t",salesDetailsUnloading[0][i]);
        }

        fprintf(cfPtr,"\n");

        printf("\n");
        printf("Do you unloading another item (y/n) : ");//ask to enter another item
        scanf(" %c",&option);
    }



    fclose(cfPtr);
}

void readUnloadingDetails(int *opt)
{
    system("cls");
    displayCompanyName();
    printf("\nUnloading Details\n\n");

    int unloadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsUnloadingReport.txt","r");
    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d %d", &unloadingitemDetails[i][0],&unloadingitemDetails[i][1],&unloadingitemDetails[i][2],&unloadingitemDetails[i][3],&unloadingitemDetails[i][4],&unloadingitemDetails[i][5],&unloadingitemDetails[i][6]);

    printf("ItemID\tnumber of Items\t Total Price\tvehicle\t date\n");

    while(!feof(cfPtr))
    {
        printf("%d\t%d\t\t %d\t\t%d\t %d-%d-%d\n",unloadingitemDetails[i][0],unloadingitemDetails[i][1],unloadingitemDetails[i][2],unloadingitemDetails[i][3],unloadingitemDetails[i][4],unloadingitemDetails[i][5],unloadingitemDetails[i][6]);
        i++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d %d", &unloadingitemDetails[i][0],&unloadingitemDetails[i][1],&unloadingitemDetails[i][2],&unloadingitemDetails[i][3],&unloadingitemDetails[i][4],&unloadingitemDetails[i][5],&unloadingitemDetails[i][6]);
    }

    fclose(cfPtr);


    int selectOption;

    printf("\nPress 1 - Back to Main Menu : ");
    scanf("%d",&selectOption);

    if(selectOption == 1 )
    {

        menuDriven(opt);
    }
}
