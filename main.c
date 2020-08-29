#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayCompanyName();//method for display company name

void menuDriven(int *);//method for display menu

void switchCase(int *optionSelceted);

void addItemDetails();//method for add items into a file

void readItemDetails(int *);//method for read items from a file

void displayItemDetails();//method for read items from a file

void updateItemDetails();////method for update items of a file

void updateItemDetailsUnloading();////method for update items of a file

int getItemDetails(int id);//method for get items from a file to use

int checkItemAmountLessThanZero(int id,int amount);//check amount after loading is less than zero or not

void storeLoadingDetails();//method for add items Details into a file

void displayLoadingDetails();//method for read loaded items from a file

void readLoadingDetails(int *);//method for read loaded items from a file

void storeUnloadingDetails();//method for store data of unloaded items from a file

void readUnloadingDetails(int *);//method for read the data of unloaded items from a file

void calculateSales();//Calculates sales to get the amount of sales and Total Price

void displaySalesReport(int *);//method for display sales details

int main( )
{

    system("color 2");//change the CLI color into green

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

    printf("\n\t----------------------------------------------------------------------------------\n");
    printf("\n\t----------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tXYZ Distributors\n");
    printf("\n\t----------------------------------------------------------------------------------\n");
    printf("\n\t----------------------------------------------------------------------------------\n");


}

void menuDriven(int *opt)
{
    system("cls");//clear screen
    displayCompanyName();
    printf("\n\n\n");
    printf("\t1. Add item Details\n");
    printf("\t2. Read item Details\n");
    printf("\t3. Store Loading Details \n");
    printf("\t4. Read Loading Details\n");
    printf("\t5. Store Unloading Details\n");
    printf("\t6. Read Unloading Details\n");
    printf("\t7. Read Sales Details\n");
    printf("\t8. Exit\n\n\n");
    printf("\tEnter your choice :  ");
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
        displaySalesReport(optionSelceted);
        menuDriven(optionSelceted);
        break;
    case 8:
        exit(0);

    default:
        break;
    }

}

void addItemDetails()
{
    system("cls");
    displayCompanyName();
    printf("\n\tAdd Item Details\n\n");

    int itemID;
    int price;
    int stockAmout;


    char i = 'y';
    while(i=='y')
    {
        FILE *cfPtr;

        cfPtr = fopen("itemDetails.txt","a");

        if(cfPtr == NULL)
        {
            printf("Cannot create file\n");
            return -1;
        }

        displayItemDetails();

        printf("\n");

        printf("\tEnter item ID : ");

        scanf("%d", &itemID);



        printf("\tEnter Price for the Item No.%d : ",itemID);
        scanf("%d", &price);

        printf("\tEnter stock amount for the Item No.%d : ",itemID);
        scanf("%d", &stockAmout);

        fprintf(cfPtr,"%d\t%d\t%d\n",itemID,price,stockAmout);
        //save itemID,price,stock amount into the itemDetails text file

        fclose(cfPtr);

        printf("\tDo you want to add another item ( y for yes / n for no ): ");
        scanf(" %c", &i);

    }



}

void displayItemDetails()
{
    printf("\n\n");

    int itemDetails[50][3],priceOfGivenItemID;

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);

    printf("\tItemID\tPrice(Rs.)\tAmount available in the stock\n");

    while(!feof(cfPtr))
    {
        printf("\t%d\t%d\t\t%d\n",itemDetails[i][0],itemDetails[i][1],itemDetails[i][2]);
        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);


}

void readItemDetails(int *opt)
{
    system("cls");
    displayCompanyName();
    printf("\n\n\tItem Details\n");
    printf("\t-----------------------------------------------------------------\n\n");

    int itemDetails[50][3],priceOfGivenItemID;

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemDetails.txt","r");

    fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);

    printf("\tItemID\t\tPrice(Rs.)\tAmount available in the stock\n");
    printf("\t-----------------------------------------------------------------\n");

    while(!feof(cfPtr))
    {
        printf("\t%d\t\t%d\t\t%d\n",itemDetails[i][0],itemDetails[i][1],itemDetails[i][2]);
        i++;
        fscanf(cfPtr,"%d %d %d", &itemDetails[i][0],&itemDetails[i][1],&itemDetails[i][2]);
    }

    fclose(cfPtr);

    int selectOption;

    printf("\n\tPress 1 - Back to Main Menu : ");
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

int checkItemAmountLessThanZero(int id,int amount)
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


    for(int j=0;j<i;j++)
    {
        if(itemDetails[j][0] == id)
        {
            itemDetails[j][2] = itemDetails[j][2] - amount;

            //if amount after substraction is less than zero
            if(itemDetails[j][2] < 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }

        }
    }

    fclose(cfPtr);//close the connection
}

void storeLoadingDetails()
{
    system("cls");//clear screen

    displayCompanyName();
    printf("\n\tStore Loading Details\n");

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
        printf("\tPlease input item number : ");
        scanf("%d", &salesDetailsLoading[0][0]); //input item id

        price = getItemDetails(salesDetailsLoading[0][0]); //get the price of input id number

        printf("\tPlease input No of items loading for item number %d : ",salesDetailsLoading[0][0]);
        scanf("%d", &salesDetailsLoading[0][1]); // input number of items loading for the given id number

        int checkItemAmount = checkItemAmountLessThanZero(salesDetailsLoading[0][0],salesDetailsLoading[0][1]);//call checkItemAmountLessThanZero to check amount after loading is less than zero or not

        while( checkItemAmount == 1 )
        {
            printf("\n\tYou cant load %d number of items...Please input a valid value\n\n",salesDetailsLoading[0][1]);
            printf("\tPlease input No of items loading for item number %d : ",salesDetailsLoading[0][0]);
            scanf("%d", &salesDetailsLoading[0][1]); // input number of items loading for the given id number

            checkItemAmount = checkItemAmountLessThanZero(salesDetailsLoading[0][0],salesDetailsLoading[0][1]);//call checkItemAmountLessThanZero to check amount after loading is less than zero or not
        }

        updateItemDetails(salesDetailsLoading[0][0],salesDetailsLoading[0][1]); //call updateItemDetails function to update item amount in the itemDetails text file

        salesDetailsLoading[0][2] = price * salesDetailsLoading[0][1]; //calculate the total price

        printf("\tPlease input vehicle ID :  ");
        scanf("%d", &salesDetailsLoading[0][3]); // input vehicle

        printf("\tPlease input current year : ");
        scanf("%d", &salesDetailsLoading[0][4]); // input current year

        printf("\tPlease input current month : ");
        scanf("%d", &salesDetailsLoading[0][5]); // input current month

        printf("\tPlease input current date : ");
        scanf("%d", &salesDetailsLoading[0][6]); // input current date

        /*display details*/
        printf("\tprice of item %d is %d\n",salesDetailsLoading[0][0],price);
        printf("\tTotal price of item %d is %d\n",salesDetailsLoading[0][0],salesDetailsLoading[0][2]);

        for(int i = 0; i < 7; i++)
        {
            /*saving itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
            fprintf(cfPtr,"%d\t",salesDetailsLoading[0][i]);
        }

        fprintf(cfPtr,"\n");



        printf("\n");
        printf("\tDo you loading another item (y/n) : ");//ask to enter another item
        scanf(" %c",&option);
    }



    fclose(cfPtr);



}

void readLoadingDetails(int *opt)
{
    system("cls");
    displayCompanyName();
    printf("\n\tLoading Details\n\n");

    int loadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsLoadingReport.txt","r");
    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);

    printf("\tItemID\t\tNumber of Items\t\tTotal Price\t\tVehicle\t\tDate\n");

    printf("\t---------------------------------------------------------------------------------------------\n");

    while(!feof(cfPtr))
    {
        printf("\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d-%d-%d\n",loadingitemDetails[i][0],loadingitemDetails[i][1],loadingitemDetails[i][2],loadingitemDetails[i][3],loadingitemDetails[i][4],loadingitemDetails[i][5],loadingitemDetails[i][6]);
        i++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);
    }

    fclose(cfPtr);


    int selectOption;

    printf("\n\tPress 1 - Back to Main Menu : ");
    scanf("%d",&selectOption);

    if(selectOption == 1 )
    {

        menuDriven(opt);
    }

}


void displayLoadingDetails()
{

    printf("\n\tLoading Details\n\n");

    int loadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsLoadingReport.txt","r");
    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);

    printf("\tItemID\tnumber of Items\t Total Price\tvehicle\t date\n");



    while(!feof(cfPtr))
    {
        printf("\t%d\t%d\t\t %d\t\t%d\t %d-%d-%d\n",loadingitemDetails[i][0],loadingitemDetails[i][1],loadingitemDetails[i][2],loadingitemDetails[i][3],loadingitemDetails[i][4],loadingitemDetails[i][5],loadingitemDetails[i][6]);
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




    while(option=='y')
    {
        FILE *cfPtr;


        cfPtr = fopen("itemsUnloadingReport.txt","a");

        if(cfPtr == NULL)
        {
            printf("Cannot create file\n");
            return -1;
        }


        displayLoadingDetails(); //display details of items

        printf("\t-------------------------------------------------------");
        printf("\n\tStore Unloading Details\n");

        printf("\n");
        printf("\tPlease input item number : ");
        scanf("%d", &salesDetailsUnloading[0][0]); //input item id

        printf("\tPlease input No of items unloading for item number %d : ",salesDetailsUnloading[0][0]);
        scanf("%d", &salesDetailsUnloading[0][1]); // input number of items loading for the given id number

        updateItemDetailsUnloading(salesDetailsUnloading[0][0],salesDetailsUnloading[0][1]); //call updateItemDetails function to update item amount in the itemDetails text file

        printf("\tPlease input vehicle ID :  ");
        scanf("%d", &salesDetailsUnloading[0][2]); // input vehicle

        printf("\tPlease input current year ");
        scanf("%d", &salesDetailsUnloading[0][3]); // input current year

        printf("\tPlease input current month ");
        scanf("%d", &salesDetailsUnloading[0][4]); // input current month

        printf("\tPlease input current date ");
        scanf("%d", &salesDetailsUnloading[0][5]); // input current date


        for(int i = 0; i < 6; i++)
        {
            /*saving itemID,number of Items,vehicle id,year,month,date into the itemsUnloadingReport text file*/
            fprintf(cfPtr,"%d\t",salesDetailsUnloading[0][i]);
        }
        printf("\n");


         fclose(cfPtr);/*Close the Pointer*/

        /*Calculates sales to get the amount of sales and Total Price*/
        calculateSales();


        /*ask to enter another item*/
        printf("\tDo you unloading another item (y/n) : ");
        scanf(" %c",&option);
    }




}

void readUnloadingDetails(int *opt)
{
    system("cls");
    displayCompanyName();
    printf("\n\tUnloading Details\n\n");

    int unloadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsUnloadingReport.txt","r");
    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d", &unloadingitemDetails[i][0],&unloadingitemDetails[i][1],&unloadingitemDetails[i][2],&unloadingitemDetails[i][3],&unloadingitemDetails[i][4],&unloadingitemDetails[i][5]);

    printf("\tItemID\t\tnumber of Items\t\tvehicle\t\tdate\n");
    printf("\t--------------------------------------------------------------------------\n");

    while(!feof(cfPtr))
    {
        printf("\t%d\t\t%d\t\t\t%d\t\t%d-%d-%d\n",
        unloadingitemDetails[i][0],unloadingitemDetails[i][1],unloadingitemDetails[i][2],unloadingitemDetails[i][3],unloadingitemDetails[i][4],unloadingitemDetails[i][5],unloadingitemDetails[i][6]);
        i++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d", &unloadingitemDetails[i][0],&unloadingitemDetails[i][1],&unloadingitemDetails[i][2],&unloadingitemDetails[i][3],&unloadingitemDetails[i][4],&unloadingitemDetails[i][5]);
    }

    fclose(cfPtr);


    int selectOption;

    printf("\n\tPress 1 - Back to Main Menu : ");
    scanf("%d",&selectOption);

    if(selectOption == 1 )
    {

        menuDriven(opt);
    }
}


void calculateSales()
{
    /* Getting Loading Details into an array */
    int loadingitemDetails[50][7];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("itemsLoadingReport.txt","r");

    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);

    while(!feof(cfPtr))
    {
        //printf("\t%d\t%d\t\t %d\t\t%d\t %d-%d-%d\n",loadingitemDetails[i][0],loadingitemDetails[i][1],loadingitemDetails[i][2],loadingitemDetails[i][3],loadingitemDetails[i][4],loadingitemDetails[i][5],loadingitemDetails[i][6]);

        i++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d %d", &loadingitemDetails[i][0],&loadingitemDetails[i][1],&loadingitemDetails[i][2],&loadingitemDetails[i][3],&loadingitemDetails[i][4],&loadingitemDetails[i][5],&loadingitemDetails[i][6]);
    }



    /* Getting unloading Details into an array */
    int unloadingitemDetails[50][6];

    int j=0;


    cfPtr = fopen("itemsUnloadingReport.txt","r");

    /*getting itemID,number of Items,Total Price,vehicle,year,month,date into the itemsLoadingReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d ", &unloadingitemDetails[j][0],&unloadingitemDetails[j][1],&unloadingitemDetails[j][2],&unloadingitemDetails[j][3],&unloadingitemDetails[j][4],&unloadingitemDetails[j][5]);

    printf("\n\tUnloading\n");
    while(!feof(cfPtr))
    {
        //printf("\t%d\t%d\t\t %d\t\t %d-%d-%d\n",unloadingitemDetails[j][0],unloadingitemDetails[j][1],unloadingitemDetails[j][2],unloadingitemDetails[j][3],unloadingitemDetails[j][4],unloadingitemDetails[j][5]);
        j++;
        /*getting itemID,number of Items,Total Price,year,month,date into the itemsLoadingReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d", &unloadingitemDetails[j][0],&unloadingitemDetails[j][1],&unloadingitemDetails[j][2],&unloadingitemDetails[j][3],&unloadingitemDetails[j][4],&unloadingitemDetails[j][5]);
    }


    int numberOfSales;
    int TotalPrice,price;



    cfPtr = fopen("salesReport.txt","w");

    /* Calculate Number of sales for each Item */
    for(int k = 0; k <= i;k++)
    {
        for(int p = 0; p <= j;p++)
        {
            //printf("\nj is %d\n",j);
            //printf("\tloading item %d\tunloading %d\n",loadingitemDetails[k][0],unloadingitemDetails[p][0]);

            //check the loading item id and unloading id is equal
            if(loadingitemDetails[k][0] == unloadingitemDetails[p][0])
            {
                //printf("loading item %d\tunloading %d\n",loadingitemDetails[k][0],unloadingitemDetails[p][0]);
                numberOfSales = loadingitemDetails[k][1] - unloadingitemDetails[p][1];

                //get the price of input id number
                price = getItemDetails(loadingitemDetails[k][0]);

                //get the total price
                TotalPrice = price * numberOfSales;

                /*saving itemID,numberOfSales,TotalPrice,unloadingYear,unloadingMonth,unloadingDate salesReport text file*/
                fprintf(cfPtr,"%d\t%d\t%d\t%d\t%d\t%d\n",loadingitemDetails[k][0],numberOfSales,TotalPrice,unloadingitemDetails[p][3],unloadingitemDetails[p][4],unloadingitemDetails[p][5]);

            }
        }
    }

    fclose(cfPtr);

}

void displaySalesReport(int *opt)
{
    system("cls");
    displayCompanyName();
    printf("\n\tSales Report\n\n");

    int salesDetails[50][6];

    int i=0;

    FILE *cfPtr;

    cfPtr = fopen("salesReport.txt","r");
    /*getting itemID,sales Amount,Total Price,Date salesReport text file*/
    fscanf(cfPtr,"%d %d %d %d %d %d", &salesDetails[i][0],&salesDetails[i][1],&salesDetails[i][2],&salesDetails[i][3],&salesDetails[i][4],&salesDetails[i][5]);

    printf("\tItemID\t\tSales Amount\tTotal Price\tDate\n");
    printf("\t---------------------------------------------------------------------\n");

    while(!feof(cfPtr))
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d-%d-%d\n",salesDetails[i][0],salesDetails[i][1],salesDetails[i][2],salesDetails[i][3],salesDetails[i][4],salesDetails[i][5]);
        i++;
        /*getting itemID,sales Amount,Total Price,Date salesReport text file*/
        fscanf(cfPtr,"%d %d %d %d %d %d", &salesDetails[i][0],&salesDetails[i][1],&salesDetails[i][2],&salesDetails[i][3],&salesDetails[i][4],&salesDetails[i][5]);

    }

    fclose(cfPtr);

    /*
    ************************************Display bar graph***********************************
    */

    for(int a = 0; a < i;a++)
    {
         printf("\n");
         printf("\n\tITEMID : %d  SALES : %d\n",salesDetails[a][0],salesDetails[a][1]);
         printf("\t");
         for(int b=0;b<salesDetails[a][1];b++)
         {
            printf("\xDB");
         }
    }


    /*
    ************************************End of Display bar graph***********************************
    */

    int selectOption;

    printf("\n\n\n\tPress 1 - Back to Main Menu : ");
    scanf("%d",&selectOption);

    if(selectOption == 1 )
    {

        menuDriven(opt);
    }

}
