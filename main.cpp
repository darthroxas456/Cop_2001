/*
 * Authors name: Owen Rose
 * This is a procedural project for COP 2001
 * This is a program that, once finished, will be able to keep track of what products are produced
 * for a media player production facility.
*/
#include <iostream>
#include <iomanip>
//prototype
using namespace std;
void showMenu();

int prodNum = 1;
int audioSerialNum = 1;
int audioMobileSerialNum = 1;
int visualSerialNum = 1;
int visualMobileSerialNum = 1;

int main() {
    int choice; //to hold the menu choice.

    //these are the constants for each of the choices.
  const int PRODUCE_ITEMS =1,
            ADD_EMPLOYEE_ACCOUNT =2,
            ADD_MUSIC_PLAYER =3,
            ADD_MOVIE_PLAYER =4,
            DISPLAY_PRODUCTION_STATISTICS =5,
            QUIT_CHOICE =6;

    std::cout << "Production Line Tracker\n";
    std::cout << "\n";
    do{
        //Display the menu and get user's choice.
        showMenu();
        std::cin >> choice;
        while(choice < PRODUCE_ITEMS || choice > QUIT_CHOICE){
            std::cout << "Not a valid selection\n" ;
            std::cout << "1. Produce Items\n";
            std::cout << "2. Add Employee Account\n";
            std::cout << "3. Add Music Player\n";
            std::cout << "4. Add Movie Player\n";
            std::cout << "5. Display Production Statistics\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;
        }
        // If the user doesn't want to quit, proceed.
        if(choice != QUIT_CHOICE){
            //display the menu STUBS.
            switch(choice){
                case PRODUCE_ITEMS:
                    std::cout << "Produce Items Stub\n"; //prints a stub for the selected item
                    break;
                case ADD_EMPLOYEE_ACCOUNT:
                    std::cout << "Add Employee Account Stub\n"; //prints a stub for the selected item
                    break;
                case ADD_MUSIC_PLAYER:
                    std::cout << "Add Music Player Stub\n"; //prints a stub for the selected item
                    break;
                case ADD_MOVIE_PLAYER:
                    std::cout << "Add Movie Player Stub\n"; //prints a stub for the selected item
                    break;
                case DISPLAY_PRODUCTION_STATISTICS:
                    std::cout << "Display Production Statistics Stub\n"; //prints a stub for the selected item
                    break;
            }
        }
    }while(choice != QUIT_CHOICE);


    // Eventually the user will be able to choose the item to produce.
    // For now, just have them input the information.
    cout << "Enter the Manufacturer\n";
    string manufacturer;
    cin >> manufacturer; // assigns what the user inputs to manufacturer.
    cout << "Enter the Product Name\n";
    string prodName;
    cin >> prodName; // assigns what the user inputs to prodName.
    cout << "Enter the item type\n";
    cout << "1. Audio\n" <<
         "2. Visual\n" <<
         "3. AudioMobile\n" <<
         "4. VisualMobile\n";
    int itemTypeChoice;
    cin >> itemTypeChoice;
    string itemTypeCode;
    // write code to set the item type code based on the selected item type
    // Audio "MM", Visual "VI", AudioMobile "AM", or VisualMobile "VM".
    if(itemTypeChoice == 1){
        itemTypeCode = "MM"; // assigns MM to item code based on the users choice

    }else if(itemTypeChoice == 2){
        itemTypeCode = "VI"; // assigns MM to item code based on the users choice

    }else if(itemTypeChoice == 3){
        itemTypeCode = "AM"; // assigns MM to item code based on the users choice

    }else if(itemTypeChoice == 4){
        itemTypeCode = "VM"; // assigns MM to item code based on the users choice
    }
    cout << "Enter the number of items that were produced\n";
    int numProduced;
    cin >> numProduced; // assigns what the user input to numProduced.

    // add a loop to record production, for now simply by
    // outputting production number and serial number
    int i;
    for(i=1; i <= numProduced; i++){
        cout << "Production Number: "<< i << " Serial Number: App" << itemTypeCode <<"0000"<< i << endl;
    }    // prints out the production numbers and serial numbers for what the user asked for.
    return 0;
}

//***********************************************************
//Definition of function showMenu which displays the menu. **
//***********************************************************
void showMenu(){

    std::cout << "1. Produce Items\n";     // these are the choices for the initial menu hte user sees.
    std::cout << "2. Add Employee Account\n";
    std::cout << "3. Add Music Player\n";
    std::cout << "4. Add Movie Player\n";
    std::cout << "5. Display Production Statistics\n";
    std::cout << "6. Exit\n";
}


