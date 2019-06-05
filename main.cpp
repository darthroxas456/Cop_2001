/** @file main.cpp
 *  @brief This is a procedural project for COP 2001
 *
 *  This is a program that, once finished, will be able to keep track of what products are produced
 * for a media player production facility.
 *
 *  @author Owen Rose
 *  @bug No known bugs.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
//prototype
using namespace std;

/** @brief This function prints out the menu screen.
 *
 *  The showMenu function creates the menu that the user will use to travel through
 *  to create serial numbers for the media players made.
 *
 *
 *  @return void
 */
void showMenu();

/** @brief This function prints out a string of code.
 *
 *  the addToProductLine functions allows the user to input the manufacturer,
 *  item name, and what type of product the item is and then prints out
 *  in a single line what they inputted.
 *
 *  @param productLineManufacturer: this vector contains
 *
 *  @return void
 */
void addToProductLine(std::vector<std::string> &,
                      std::vector<std::string> &,
                      std::vector<std::string> &);

/** @brief This function prints out a string of code.
 *
 *  the addToProductLine functions allows the user to input the manufacturer,
 *  item name, and what type of product the item is and then prints out
 *  in a single line what they inputted.
 *
 *  @param
 *
 *  @return void
 */
void production_log(std::vector<int> &production_number,
                    std::vector<std::string> &production_manufacturers,
                    std::vector<std::string> &production_names,
                    std::vector<std::string> &production_item_types,
                    std::vector<std::string> &production_serial_num,
                    std::vector<std::string> manufacturers,
                    std::vector<std::string> names,
                    std::vector<std::string> item_types,
                    int &MM_num, int &AM_num,
                    int &VI_num, int &VM_num);


void add_sample_products(std::vector<std::string> &manufacturers,
                         std::vector<std::string> &names,
                         std::vector<std::string> &item_types);

void output_sorted_product_names(std::vector<std::string>);

void find_manufacturer_of_product();


int main() {
    int choice; //to hold the menu choice.

    int AM_num = 0;
    int MM_num = 0;
    int VI_num = 0;
    int VM_num = 0;
    // vectors for Product Line
    // vector to store product manufacturer
    std::vector<std::string> manufacturers;
    // a parallel vector to store product name
    std::vector<std::string> names;
    // a parallel vector to store product item type
    std::vector<std::string> item_types;

    //Production vectors
    std::vector<int> production_number;

    std::vector<std::string> production_manufacturers;

    std::vector<std::string> production_names;

    std::vector<std::string> production_item_types;

    std::vector<std::string> production_serial_num;

    //these are the constants for each of the choices.
    const int PRODUCE_ITEMS = 1,
            ADD_EMPLOYEE_ACCOUNT = 2,
            ADD_ITEM = 3,
            DISPLAY_PRODUCTION_STATISTICS = 4,
            QUIT_CHOICE = 5;

    add_sample_products(manufacturers, names, item_types);

    std::cout << "Production Line Tracker\n";
    std::cout << "\n";

    do {
        //Display the menu and get user's choice.
        showMenu();
        std::cin >> choice;
        while (choice < PRODUCE_ITEMS || choice > QUIT_CHOICE) {
            std::cout << "Not a valid selection\n";
            std::cout << "1. Produce Items\n";
            std::cout << "2. Add Employee Account\n";
            std::cout << "3. Add Item\n";
            std::cout << "4. Display Production Statistics\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;
        }
        // If the user doesn't want to quit, proceed.
        if (choice != QUIT_CHOICE) {
            //display the menu STUBS.
            switch (choice) {
                case PRODUCE_ITEMS:
                    //std::cout << "Produce Items Stub\n"; //prints a stub for the selected item
                    production_log(production_number,
                                   production_manufacturers,
                                   production_names,
                                   production_item_types,
                                   production_serial_num,
                                   manufacturers,
                                   names,
                                   item_types,
                                   MM_num, AM_num,
                                   VI_num, VM_num);
                    break;
                case ADD_EMPLOYEE_ACCOUNT:
                    std::cout << "Add Employee Account Stub\n"; //prints a stub for the selected item
                    break;
                case ADD_ITEM:
                    addToProductLine(manufacturers, names, item_types);
                    break;
                case DISPLAY_PRODUCTION_STATISTICS:
                    //std::cout << "Display Production Statistics Stub\n"; //prints a stub for the selected item
                    output_sorted_product_names(names);
                    find_manufacturer_of_product();
                    break;
                default:
                    std::cout << "Please select an item from the menu. " << std::endl;

            }
        }
    } while (choice != QUIT_CHOICE);

}

//***********************************************************
//Definition of function showMenu which displays the menu. **
//***********************************************************
void showMenu() {
    std::cout << "\nProduction Line Tracker\n";
    std::cout << "1. Produce Items\n";     // these are the choices for the initial menu the user sees.
    std::cout << "2. Add Employee Account\n";
    std::cout << "3. Add Item\n";
    std::cout << "4. Display Production Statistics\n";
    std::cout << "5. Exit\n";
}

void addToProductLine(std::vector<std::string> &productLineManufacturer,
                      std::vector<std::string> &productLineName, std::vector<std::string> &productLineItemType) {
    std::cout << "Adding a new product to the product line\n";
    std::cin.ignore();
    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
    getline(std::cin, manufacturer);
    // add manufacturer to the vector here

    productLineManufacturer.push_back(manufacturer);


    std::cout << "Enter the Product Name\n";
    std::string prodName;
    getline(std::cin, prodName);
    // add prodName to the vector
    productLineName.push_back(prodName);


    std::cout << "Enter the item type\n";
    std::cout <<
              "1. Audio\n" <<
              "2. Visual\n" <<
              "3. Audio Mobile\n" <<
              "4. Visual Mobile\n";

    int itemTypeChoice;

    std::cin >> itemTypeChoice;
    std::string itemTypeCode;
    switch (itemTypeChoice) {
        case 1:
            itemTypeCode = "MM";
            break;
        case 2:
            itemTypeCode = "VI";
            break;
        case 3:
            itemTypeCode = "AM";
            break;
        case 4:
            itemTypeCode = "VM";
            break;
        default:
            std::cout << "Not a valid selection\n";
            std::cout << "Setting type to 'NA'\n";
            itemTypeCode = "NA";
            break;
    }
    // add itemTypeCode to the vector
    productLineItemType.push_back(itemTypeCode);
    std::cin.ignore();

    cout << manufacturer << ", " << prodName << ", " << itemTypeCode << endl << endl;

}

void production_log(std::vector<int> &production_number,
                    std::vector<std::string> &production_manufacturers,
                    std::vector<std::string> &production_names,
                    std::vector<std::string> &production_item_types,
                    std::vector<std::string> &production_serial_num,
                    std::vector<std::string> manufacturers,
                    std::vector<std::string> names,
                    std::vector<std::string> item_types,
                    int &MM_num, int &AM_num,
                    int &VI_num, int &VM_num) {

    int prodLine_num;
    cout << "Select one of the following:" << endl;
    for (prodLine_num = 0; prodLine_num < manufacturers.size();
         prodLine_num++) {
        cout << prodLine_num + 1 << ". " << manufacturers[prodLine_num]
             << ", " << names[prodLine_num] << endl;
    }
    int choice;
    cin >> choice;

    int amount_made;
    cout << "Amount Made:" << endl;
    cin >> amount_made;
    for (int i = 0; i < amount_made; i++) {
        production_number.push_back(prodLine_num + 1);

        production_manufacturers.push_back(manufacturers[choice - 1]);

        production_names.push_back(names[choice - 1]);

        production_item_types.push_back(item_types[choice - 1]);

        int serial_num;
        if (item_types[choice - 1] == "AM") {
            serial_num = AM_num;
            AM_num++;
        } else if (item_types[choice - 1] == "MM") {
            serial_num = MM_num;
            MM_num++;
        } else if (item_types[choice - 1] == "VI") {
            serial_num = VI_num;
            VI_num++;
        } else if (item_types[choice - 1] == "VM") {
            serial_num = VM_num;
            VM_num++;
        }
        std::stringstream serial;
        serial << production_manufacturers[choice - 1] + item_types[choice - 1] << setfill('0') << setw(5)
               << serial_num;
        production_serial_num.push_back(serial.str());

        cout << serial.str() << endl;
    }


}

void add_sample_products(std::vector<std::string> &manufacturers,
                         std::vector<std::string> &names,
                         std::vector<std::string> &item_types) {
    manufacturers.push_back("Microsoft");
    names.push_back("Zune");
    item_types.push_back("AM");
    manufacturers.push_back("Apple");
    names.push_back("iPod");
    item_types.push_back("AM");
    manufacturers.push_back("Sylvania");
    names.push_back("SDVD1187");
    item_types.push_back("VM");

}

void output_sorted_product_names(std::vector<std::string> names) {
    sort(names.begin(), names.end());

    for (auto x : names) {
        std::cout << x << std::endl;
    }

}

void find_manufacturer_of_product() {

    std::cout << "Enter the product name from the list above "
                 "to find the manufacturer\n";
    std::string prod_name_to_find;
    std::cin >> prod_name_to_find;

    if (prod_name_to_find == "iPod") {
        std::cout << "The manufacturer of that product is Apple" << std::endl;
    } else if (prod_name_to_find == "ipod") {
        std::cout << "The manufacturer of that product is Apple" << std::endl;
    } else if (prod_name_to_find == "Zune") {
        std::cout << "The manufacturer of that product is Microsoft" << std::endl;
    } else if (prod_name_to_find == "zune") {
        std::cout << "The manufacturer of that product is Microsoft" << std::endl;
    } else if (prod_name_to_find == "SDVD1187") {
        std::cout << "The manufacturer of that product is Sylvania" << std::endl;
    } else if (prod_name_to_find == "sdvd1187") {
        std::cout << "The manufacturer of that product is Sylvania" << std::endl;
    } else {
        std::cout << "The product name was not found." << std::endl;
    }
}

