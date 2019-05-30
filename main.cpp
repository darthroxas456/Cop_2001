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
//prototype
using namespace std;

/** @brief This function prints out the menu screen.
 *
 *  The showMenu function creates the menu that the user will use to travel through
 *  to create serial numbers for the media players made.
 *
 *  @param  "1. Produce Items";
    @param  "2. Add Employee Account";
    @param  "3. Add Music Player";
    @param  "4. Add Movie Player";
    @param  "5. Display Production Statistics";
    @param  "6. Exit";
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
 *  @param input of manufacturer
 *  @param input of product name
 *  @param input of product type.
 *  @param output of the three listed above as a string.
 *
 *  @return void
 */
void addToProductLine(std::vector<std::string>&, std::vector<std::string>&,
                      std::vector<std::string>&);

/** @brief This function prints out the sample information the user can input.
 *
 *  The add_sample_products function used vectors to create
 *  a grid of data to print out sample data for the user.
 *
 *  @param product_line_manufacturers.push_back("Microsoft");
 *  @param product_line_names.push_back("Zune");
 *  @param product_line_item_types.push_back("AM");
 *  @param product_line_manufacturers.push_back("Apple");
 *  @param product_line_names.push_back("iPod");
 *  @param product_line_item_types.push_back("AM");
 *  @param product_line_manufacturers.push_back("Sylvania");
 *  @param product_line_names.push_back("SDVD1187");
 *  @param product_line_item_types.push_back("VM");
 *
 *  @return void
 */
void add_sample_products(std::vector<std::string> &, std::vector<std::string> &,
                         std::vector<std::string> &);

void output_product_line(std::vector<std::string>, std::vector<std::string>,
                         std::vector<std::string>);

void output_sorted_product_names(std::vector<std::string>);

void find_manufacturer_of_product(std::vector<std::string>, std::vector<std::string>);


int prodNum = 1;
int audioSerialNum = 1;
int audioMobileSerialNum = 1;
int visualSerialNum = 1;
int visualMobileSerialNum = 1;

int main() {
    int choice; //to hold the menu choice.

    //these are the constants for each of the choices.
    const int PRODUCE_ITEMS = 1,
            ADD_EMPLOYEE_ACCOUNT = 2,
            ADD_MUSIC_PLAYER = 3,
            ADD_MOVIE_PLAYER = 4,
            DISPLAY_PRODUCTION_STATISTICS = 5,
            QUIT_CHOICE = 6;

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
            std::cout << "3. Add Music Player\n";
            std::cout << "4. Add Movie Player\n";
            std::cout << "5. Display Production Statistics\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;
        }
        // If the user doesn't want to quit, proceed.
        if (choice != QUIT_CHOICE) {
            //display the menu STUBS.
            switch (choice) {
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
                default:
                    std::cout << "Please select an item from the menu. " << std::endl;

            }
        }
    } while (choice != QUIT_CHOICE);


    // Create vectors
    // vector to store product manufacturer
    std::vector<std::string> productLineManufacturer;
    // a parallel vector to store product name
    std::vector<std::string> productLineName;
    // a parallel vector to store product item type
    // create vector here
    std::vector<std::string> productLineItemType;
    // Add three new products to the product line

    addToProductLine(productLineManufacturer, productLineName, productLineItemType);
    addToProductLine(productLineManufacturer, productLineName, productLineItemType);
    addToProductLine(productLineManufacturer, productLineName, productLineItemType);

    // Output the products in the product line
    std::cout << "The products in the Product Line are:\n";

    for (int productLineItemNum=0; productLineItemNum < 3; productLineItemNum++) {
        std::cout << productLineManufacturer[productLineItemNum] << ", ";
        std::cout << productLineName[productLineItemNum] << ", ";
        std::cout << productLineItemType[productLineItemNum] << "\n";
    }

    // vectors for Product Line
    // vector to store product manufacturer
    std::vector<std::string> product_line_manufacturers;
    // a parallel vector to store product name
    std::vector<std::string> product_line_names;
    // a parallel vector to store product item type
    std::vector<std::string> product_line_item_types;

    add_sample_products(product_line_manufacturers, product_line_names, product_line_item_types);
    output_product_line(product_line_manufacturers, product_line_names, product_line_item_types);
    output_sorted_product_names(product_line_names);
    output_product_line(product_line_manufacturers, product_line_names, product_line_item_types);
    return 0;
}

void addToProductLine(std::vector<std::string> &productLineManufacturer,
                      std::vector<std::string> &productLineName, std::vector<std::string> &productLineItemType)
{
    std::cout << "Adding a new product to the product line\n";

    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
    getline(std::cin, manufacturer);
    // add manufacturer to the vector here

    productLineManufacturer.push_back(manufacturer);

    std::cout << "Enter the Product Name\n";
    std::string prodName;
    getline(std::cin, prodName);
    // add prodName to the vector
    productLineName.push_back (prodName);

    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
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
    productLineItemType.push_back (itemTypeCode);
    std::cin.ignore();
    cout << "Enter the number of items that were produced\n";
    int numProduced;
    cin >> numProduced; // assigns what the user input to numProduced.

    // add a loop to record production, for now simply by
    // outputting production number and serial number
    int i;
    for (i = 1; i <= numProduced; i++) {
        cout << "Production Number: " << i << " Serial Number: "<< manufacturer << itemTypeCode << "0000" << i << endl;
    }    // prints out the production numbers and serial numbers for what the user asked for.

}

void add_sample_products(std::vector<std::string> &product_line_manufacturers,
                         std::vector<std::string> &product_line_names, std::vector<std::string> &product_line_item_types) {
    product_line_manufacturers.push_back("Microsoft");
    product_line_names.push_back("Zune");
    product_line_item_types.push_back("AM");
    product_line_manufacturers.push_back("Apple");
    product_line_names.push_back("iPod");
    product_line_item_types.push_back("AM");
    product_line_manufacturers.push_back("Sylvania");
    product_line_names.push_back("SDVD1187");
    product_line_item_types.push_back("VM");

}

void output_product_line(std::vector<std::string> product_line_manufacturers,
                         std::vector<std::string> product_line_names, std::vector<std::string> product_line_item_types) {
    for (int product_index = 0; product_index < 3; product_index++) {
        std::cout << product_line_manufacturers[product_index] << ",";
        std::cout << product_line_names[product_index] << ",";
        std::cout << product_line_item_types[product_index] << "\n";
    }
}

void output_sorted_product_names(std::vector<std::string> product_line_names) {
    sort(product_line_names.begin(), product_line_names.end());

    for (auto x : product_line_names) {
        std::cout << x << std::endl;
    }

}

void find_manufacturer_of_product(std::vector<std::string> product_line_manufacturers,
                                  std::vector<std::string> product_line_names) {

    std::cout << "Enter a product name to find the manufacturer\n";
    std::string prod_name_to_find;
    std::cin >> prod_name_to_find;

    if (prod_name_to_find == "iPod") {
        std::cout << "The manufacturer of that product is Apple" << std::endl;
    } else if (prod_name_to_find == "ipod"){
        std::cout << "The manufacturer of that product is Apple" << std::endl;
    }else if(prod_name_to_find == "Zune") {
        std::cout << "The manufacturer of that product is Microsoft" << std::endl;
    }else if(prod_name_to_find == "zune") {
        std::cout << "The manufacturer of that product is Microsoft" << std::endl;
    }else if(prod_name_to_find == "SDVD1187") {
        std::cout << "The manufacturer of that product is Sylvania" << std::endl;
    }else if(prod_name_to_find == "sdvd1187") {
        std::cout << "The manufacturer of that product is Sylvania" << std::endl;
    }else{
        std::cout << "That product name was not found." << std::endl;
    }




}

//***********************************************************
//Definition of function showMenu which displays the menu. **
//***********************************************************
void showMenu() {

    std::cout << "1. Produce Items\n";     // these are the choices for the initial menu the user sees.
    std::cout << "2. Add Employee Account\n";
    std::cout << "3. Add Music Player\n";
    std::cout << "4. Add Movie Player\n";
    std::cout << "5. Display Production Statistics\n";
    std::cout << "6. Exit\n";
}


