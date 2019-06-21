/** @file main.cpp
 *  @brief This is a procedural project for COP 2001
 *
 *  This is a program that, once finished, will be able to keep track of what products are produced
 * for a media player production facility.
 *
 *  @author Owen Rose
 *  @bug you have to first add items (selection 3) in order to
 *  produce items the first time the program is run on your computer.
 *  Otherwise the program will crash because it doesn't not have the data it needs.
 *
 *  @bug The serial number restarts at 0 when the program is run again.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

/* struct Product {
    string manufacturer;
    string name;
    string type;
};
*/
//prototype

/** @brief This function prints out the menu screen.
 *
 *  The showMenu function creates the menu that the user will use to travel through
 *  to create serial numbers for the media players made.
 *
 *
 *  @return void
 */
void show_menu();

/** @brief This function prints out a string of code.
 *
 *  The addToProductLine functions allows the user to input the manufacturer,
 *  item name, and what type of product the item is and then prints out
 *  in a single line what they inputted.
 *
 *  @param productLineManufacturer: this vector contains the manufacturers of the product
 *  @param productLineName: this vector contains the name of the product
 *  @param productLineItemType: this vector contains the item type of the product.
 *
 *  @return void
 */
void add_to_product_line(std::vector<std::string> &,
                         std::vector<std::string> &,
                         std::vector<std::string> &);

/** @brief This function prints out a string of code.
 *
 *  The production_log function allows the user to select one of the products made from the add item section
 *  and tell the system how many of the item were made. The computer then outputs a serial number containing
 *  the manufacturer,  the item type, and a 5 digit serial number for that type produced.
 *
 *  @param std::vector<int> &production_number: this keeps track of the items produced
    @param std::vector<std::string> &production_manufacturers: this keeps track of the manufacturer when an item is produced
    @param std::vector<std::string> &production_names: this keeps track of the name of the item when it is produced
    @param std::vector<std::string> &production_item_types: this keeps track of the item type (AM) when the item is produced
    @param std::vector<std::string> &production_serial_num: this creates a incrementing number for every item created
    @param std::vector<std::string> manufacturers: saves all the manufacturers to a vector
    @param std::vector<std::string> names: saves all the names to a vector
    @param std::vector<std::string> item_types:saves all the item types to a vector
    @param int &MM_num: an incrementing number for the serial number
    @param int &AM_num: an incrementing number for the serial number
    @param int &VI_num: an incrementing number for the serial number
    @param int &VM_num: an incrementing number for the serial number
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
                    int &VI_num, int &VM_num,
                    int &production_num);

/** @brief This function adds sample data for the user to use in multiple selections
 *
 *  The add_sample_products function adds 3 products from multiple manufacturers to be
 *  used in the produce items section of the menu.
 *
 *  @param std::vector<std::string> &manufacturers: gives the address for the manufacturers vector
 *  @param std::vector<std::string> &names: gives the address for the names vector
 *  @param std::vector<std::string> &item_types: gives the address for the item_types vector
 *
 *
 *  @return void
 */
void load_products(std::vector<std::string> &manufacturers,
                   std::vector<std::string> &names,
                   std::vector<std::string> &item_types);

/** @brief This function prints out a string of code.
 *
 *  The output_sorted_product_names takes the products produced and arranges them in alphabetical order.
 *
 *  @param std::vector<std::string> names: used to acsess the names vector to put them in order.
 *
 *  @return void
 */
void output_sorted_product_names(std::vector<std::string> &);

/** @brief This function prints out a string of code.
 *
 *  The find_manufacturer_of_product function asked for user input of a product and looks though
 *  the vectors to fine the matching manufacturer and prints out that manufacturer.
 *
 *  @return void
 */
void find_manufacturer_of_product();

/** @brief this function creates the user name for the user.
 *
 *  The create_user function asks for the users first and last name and creates a user name consisting of the
 *  first letter of the users name and the entire last name as one word and as lowercase letters.
 *
 *  @return void
 */
void create_user();

/** @brief This function creates the password for the user.
 *
 *  The create_password function prints out a set of rules for creating a password that consists of at least 1
 *  capital and lower case letter and a number. It then go through a for loop to check
 *  that each character meets the requirements
 *
 *  @return void
 */
void create_password();

/** @brief This function encrypts the password entered.
 *
 *  The encrypt_string function uses a type of cypher to shift all the characters of the password entered +3 characters
 *  and prints out the encrypted password.
 *
 *  @param string: the password that was entered into create password.
 *
 *  @return void
 */
string encrypt_string(string);

/** @brief This function decrypts the encrypted password
 *
 *  The decrypt_string function reverses the encryption of the encrypt_string function
 *  and prints out the decrypted password
 *
 *  @param string: the encrypted password.
 *
 *  @return void
 */
string decrypt_string(string);

/** @brief This function adds products to the struct Product
 *
 *  The add_product function allows the user to input the manufacturer,
 *  item name, and what type of product the item is and then prints out
 *  in a single line what they inputted.
 *
 *  @param vector<Product> &products: this is a vector using the struct
 *  Product to do the same thing as the Production_log when asking
 *  for the manufacturer name and item_type.
 *
 *  @return void
 */
 // THIS FUNCTIONS USES STRUCT, BUT I PERSONALLY PREFER TO USE VECTORS.
//void add_product(vector<Product> &products);

/** @brief This function prints out the data inputted by the add_product function
 *
 *  The print_product_line function reads the struct Product
 *  and the vector products to output the items added.
 *
 *  @param const vector<Product> &: prints out what was inputted for the add_product function.
 *
 *  @return void
 */
// THIS FUNCTIONS USES STRUCT, BUT I PERSONALLY PREFER TO USE VECTORS.
//void print_product_line(const vector<Product> &);

/** @brief This function loads the production log from a file.
 *
 *  The load_production_log function opens the ProductionLog.csv file
 *  and reads all the lines that are in there to get the production_num
 *  and to get the serial_num based on the substring of the serial number
 *  written to the file.
 *
 * @param &MM_num
 */
void load_product_log(int &MM_num, int &AM_num,
                      int &VI_num, int &VM_num,
                      int &production_num);

int main() {
    int choice; //to hold the menu choice.

    ofstream product_line_file;
    product_line_file.open("ProductLine.csv", std::fstream::app);
    product_line_file << "Apple" << "," << "iPod" << "," << "AM" << endl;
    product_line_file << "Apple" << "," << "iPad" << "," << "VM" << endl;
    product_line_file << "Apple" << "," << "Mac" << "," << "VI" << endl;
    product_line_file.close();

    int AM_num = 0;
    int MM_num = 0;
    int VI_num = 0;
    int VM_num = 0;
    int production_num = 0;
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

    //std::vector<Product> products;

    //these are the constants for each of the choices.
    const int PRODUCE_ITEMS = 1,
            ADD_EMPLOYEE_ACCOUNT = 2,
            ADD_ITEM = 3,
            DISPLAY_PRODUCTION_STATISTICS = 4,
            QUIT_CHOICE = 5;

    load_products(manufacturers, names, item_types);
    load_product_log(MM_num, AM_num, VI_num, VM_num, production_num);

    std::cout << "Production Line Tracker\n"; //Title
    std::cout << "\n";

    do {
        //Display the menu and get user's choice.
        show_menu();
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
                    production_log(production_number,
                                   production_manufacturers,
                                   production_names,
                                   production_item_types,
                                   production_serial_num,
                                   manufacturers,
                                   names,
                                   item_types,
                                   MM_num, AM_num,
                                   VI_num, VM_num,
                                   production_num);
                    break;
                case ADD_EMPLOYEE_ACCOUNT:
                    create_user();
                    create_password();
                    break;
                case ADD_ITEM:
                    add_to_product_line(manufacturers, names, item_types); // uses vectors
                    //add_product(products); //uses struct
                    //print_product_line(products); // uses struct
                    break;
                case DISPLAY_PRODUCTION_STATISTICS:
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
//Definition of function show_menu which displays the menu. **
//***********************************************************
void show_menu() {
    std::cout << "\nProduction Line Tracker\n";
    std::cout << "1. Produce Items\n";     // these are the choices for the initial menu the user sees.
    std::cout << "2. Add Employee Account\n";
    std::cout << "3. Add Item\n";
    std::cout << "4. Display Production Statistics\n";
    std::cout << "5. Exit\n";
}

void add_to_product_line(std::vector<std::string> &product_line_manufacturer,
                         std::vector<std::string> &product_line_name,
                         std::vector<std::string> &product_line_Item_type) {
    std::cout << "Adding a new product to the product line\n";
    std::cin.ignore();
    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
    getline(std::cin, manufacturer);
    // adds manufacturer to the vector here

    product_line_manufacturer.push_back(manufacturer);

    std::cout << "Enter the Product Name\n";
    std::string prod_name;
    getline(std::cin, prod_name);
    // add prod_name to the vector
    product_line_name.push_back(prod_name);

    std::cout << "Enter the item type\n";
    std::cout <<
              "1. Audio\n" <<
              "2. Visual\n" <<
              "3. Audio Mobile\n" <<
              "4. Visual Mobile\n";

    int itemTypeChoice;

    std::cin >> itemTypeChoice;
    std::string item_type_code;
    switch (itemTypeChoice) {
        case 1:
            item_type_code = "MM";
            break;
        case 2:
            item_type_code = "VI";
            break;
        case 3:
            item_type_code = "AM";
            break;
        case 4:
            item_type_code = "VM";
            break;
        default:
            std::cout << "Not a valid selection\n";
            std::cout << "Setting type to 'NA'\n";
            item_type_code = "NA";
            break;
    }
    // add item_type_code to the vector
    product_line_Item_type.push_back(item_type_code);
    std::cin.ignore();

    cout << manufacturer << "," << prod_name << "," << item_type_code << endl << endl;

    ofstream product_line_file;
    product_line_file.open("ProductLine.csv", std::fstream::app);
    product_line_file << manufacturer << "," << prod_name << "," << item_type_code << endl;
    product_line_file.close();
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
                    int &VI_num, int &VM_num,
                    int &production_num) {

    int production_line_num;
    cout << "Select one of the following:" << endl;
    for (production_line_num = 0; production_line_num < manufacturers.size();
         production_line_num++) {
        cout << production_line_num + 1 << ". " << manufacturers[production_line_num]
             << ", " << names[production_line_num] << endl;
    }
    int choice;
    cin >> choice;

    int amount_made;
    cout << "Amount Made:" << endl;
    cin >> amount_made;
    for (int i = 0; i < amount_made; i++) {
        production_number.push_back(production_line_num + 1);

        production_manufacturers.push_back(manufacturers[choice - 1]);

        production_names.push_back(names[choice - 1]);

        production_item_types.push_back(item_types[choice - 1]);

        unsigned int serial_num; // serial_num will be assigned the number associated with the selected item_type.
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
        } else {
            cout << "unexpected item type. \n";
        }
        std::stringstream serial;
        string Resize_manufacturer = manufacturers[choice - 1];
        Resize_manufacturer.resize(3);

        serial << Resize_manufacturer + item_types[choice - 1] << setfill('0') << setw(5)
               << serial_num; //serial_num is initialized when the production_log function is run.
        production_serial_num.push_back(serial.str());

        cout << serial.str() << ", " << (production_num++ + 1) << endl;

        //the following code below writes the serial.str() to a file called ProductLog.csv
        ofstream product_line_file;
        product_line_file.open("ProductLog.csv", std::fstream::app);
        product_line_file << serial.str() << "," << production_num << endl;
        product_line_file.close();

    }


}

//the following code below reads the file called ProductLog.csv and loads it into memory to be used
void load_products(std::vector<std::string> &manufacturers,
                   std::vector<std::string> &names,
                   std::vector<std::string> &item_types) {
    string line;
    ifstream load_product_file("ProductLine.csv");
    if (load_product_file.is_open()) {
        while (getline(load_product_file, line)) {
            stringstream ss(line);
            std::string load_manufacturer;                    //This program opens the ProductLine.csv file to
            std::string load_name;                            //gather all the items made in earlier selections.
            std::string load_item_types;

            std::getline(ss, load_manufacturer, ',');
            std::getline(ss, load_name, ',');
            std::getline(ss, load_item_types);
            manufacturers.push_back(load_manufacturer);
            names.push_back(load_name);
            item_types.push_back(load_item_types);
            //cout << "pushing item_type. \n" << load_item_types <<endl;
        }
        load_product_file.close();
    } else cout << "No products to load\n \n";

}

void load_product_log(int &MM_num, int &AM_num,
                      int &VI_num, int &VM_num,
                      int &production_num) {
    string line;
    ifstream load_product_log("ProductLog.csv");
    if (load_product_log.is_open()) {
        while (getline(load_product_log, line)) {

            std::string load_item_types = line.substr(3, 2);
            //cout << "load_item_types = " << load_item_types << endl;
            production_num++;
            //cout << "production_num = " << production_num << endl;
            if (load_item_types == "AM") {
                AM_num++;

            } else if (load_item_types == "VI") {
                VI_num++;

            } else if (load_item_types == "MM") {
                MM_num++;

            } else if (load_item_types == "VM") {
                VM_num++;

            } else {
                cout << "could not find serial numbers \n";
            }

        }
        load_product_log.close();
    } else cout << "No products to load\n \n";
}

void output_sorted_product_names(std::vector<std::string> &names) {
    sort(names.begin(), names.end());
    //This program sorts the product names in alphabetical order.
    for (auto const x : names) {
        std::cout << x << std::endl;
    }

}

void find_manufacturer_of_product() { // as the name says this program uses input of a product to find the manufacturer

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

void create_user() {
    std::cout << "Enter employee's full name\n";

    std::string first_name;
    std::cin >> first_name;
    std::string last_name;
    std::cin >> last_name;

    std::string user_name;

    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);

    std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);

    user_name = first_name[0] + last_name;
    std::cout << "User name: " + user_name + "\n \n";
    cin.ignore();

    ofstream User_file;
    User_file.open("Users.txt", std::fstream::app);
    User_file << user_name << ", ";
    User_file.close();
}

void create_password() {
    bool valid = false;

    std::cout << "Enter employee's password.\n";
    std::cout << "Must contain a number and lowercase and uppercase letters.\n";

    const int SIZE = 30;
    char password[SIZE];
    int count = 0;

    bool Capital_Found = false;
    bool Lower_Found = false;
    bool Number_Found = false;
    bool Space_Found = false;

    std::cin.getline(password, SIZE);

    // code to check if valid
    for (count = 0; count < strlen(password); count++) {
        if (isupper(password[count])) {
            Capital_Found = true;
        } else if (islower(password[count])) {
            Lower_Found = true;
        } else if (isdigit(password[count])) {
            Number_Found = true;
        } else if (isspace(password[count])) {
            Space_Found = true;
        } else {
            valid = false;
        }
    }
    //std::cout << "character looked at: " << password[count] << std::endl;

    if (Capital_Found && Lower_Found && Number_Found) {
        valid = true;
    }
    if (Capital_Found && Lower_Found && Number_Found && Space_Found) {
        // this will change valid to false if a space was found
        valid = false;
    }
    if (valid) {
        std::cout << "valid \n \n";
    } else {
        std::cout << "invalid \n Try again \n \n";
    }

    string encrypted_str = encrypt_string(password);
    //cout << "Encrypted password: " << encrypted_str << endl;
    //cout << "Decrypted password: " << decrypt_string(encrypted_str) << endl;

    //the following code below writes encrypted_str to a file called Users.txt
    ofstream User_file;
    User_file.open("Users.txt", std::fstream::app);
    User_file << encrypted_str << endl;
    User_file.close();
}

string encrypt_string(string str) {
    if (str.length() == 1) {
        return str;
    } else {
        return char((int) str[0] + 3) + encrypt_string(str.substr(1, str.length() - 1));
    }
}

string decrypt_string(string str) {
    if (str.length() == 1) {
        return str;
    } else {
        return char((int) str[0] - 3) + decrypt_string(str.substr(1, str.length() - 1));

    }
}

/*
void add_product(vector<Product> &products) {
    cout << "Enter manufacturer: ";
    string input_manufacturer;
    cin >> input_manufacturer;
    cout << "Enter product name: ";
    string input_name;
    cin >> input_name;
    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
    int itemTypeChoice;
    cin >> itemTypeChoice;
    string itemTypeCode;
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
            cout << "Not a valid selection\n";
            cout << "Setting type to 'NA'\n";
            itemTypeCode = "NA";
            break;
    }
    Product Items;
    Items.manufacturer = input_manufacturer;
    Items.name = input_name;
    Items.type = itemTypeCode;

    products.push_back(Items);
}

void print_product_line(const vector<Product> &products) {
    for (int i = 0; i < products.size(); i++) {
        cout << products[i].manufacturer << " " << products[i].name << " " << products[i].type << endl;
    }
}
*/