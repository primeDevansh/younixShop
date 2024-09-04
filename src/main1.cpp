#include <fstream.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>    // for date
#include <stdlib.h>
#include <iomanip.h>

// Product Class
class product {
private:
    int id;
    char name[100];
    char category[50];
    int quantity;
    float price;

public:
    void input(int);
    void output();
    void output_special_for_buy();
    void output_name();
    void newprice();
    void newquantity();
    void newname();
    void newcat();
    int retquantity();
    int retid();
    void reducequantity(int);
    void retcat(char[]);
    void retname(char[]);
    float retprice();
};

// Customer Class
class customer {
private:
    int id;
    char name[100];
    char phone[11];
    char address[200];
    char password[100];

public:
    void input(int);
    void output();
    void allOutput(); // Displays password as well
    int retid();
    void create_password();
    void retrieve_password(char[]);
    void newname();
    void newphone();
    void newaddress();
    void newpassword();
};

// Bill Class
class bill {
private:
    int bill_no;
    int cust_id;
    int quantity_purchased;
    date d;
    product p;
    float total_cost;

public:
    void input(int, int, int, date, product); // Stores cust_id
    void output();
    int ret_bill_no();
    int ret_customer_id();
    float retrevenue();
    int retquantity();
    int retdate_day();
    int retdate_mon();
    int retdate_year();
    int retProdID();
};

// Product Member Functions
void product::input(int autoid) {
    id = autoid;
    cout << "\n\nProduct ID : " << id << endl;
    cout << "Enter product name : ";
    gets(name);
    cout << "Enter product category : ";
    gets(category);
    cout << "Enter product price : ";
    cin >> price;
    cout << "Enter product quantity : ";
    cin >> quantity;
}

void product::newcat() {
    cout << "\nEnter new category : ";
    gets(category);
}

void product::output_special_for_buy() {
    cout << "\n\nProduct ID : " << id << endl;
    cout << "Name : " << name << endl;
    cout << "Category : " << category << endl;
    cout << "Price : " << price << endl;
    cout << "Quantity left : " << quantity << endl;
}

void product::output() {
    cout << "\n" << setw(3) << id << setw(20) << name << setw(10) << category
         << setw(7) << price << setw(11) << quantity;
}

int product::retquantity() {
    return quantity;
}

void product::reducequantity(int no) {
    quantity -= no;
}

float product::retprice() {
    return price;
}

void product::output_name() {
    cout << "\n" << setw(3) << id << setw(20) << name << setw(7) << price << setw(11) << quantity;
}

int product::retid() {
    return id;
}

void product::newprice() {
    cout << "\nEnter new price : ";
    cin >> price;
}

void product::newname() {
    cout << "\nEnter new name : ";
    gets(name);
}

void product::newquantity() {
    cout << "\nEnter new quantity : ";
    cin >> quantity;
}

void product::retcat(char ret[]) {
    strcpy(ret, category);
}

void product::retname(char ret[]) {
    strcpy(ret, name);
}

// Customer Member Functions
void customer::allOutput() {
    cout << "\n\nCustomer ID : " << id;
    cout << "\nCustomer Name : " << name;
    cout << "\nPhone no. : " << phone;
    cout << "\nAddress : " << address;
    cout << "\nPassword : " << password;
}

void customer::newphone() {
    cout << "\nEnter new phone number : ";
    gets(phone);
}

void customer::newaddress() {
    cout << "\nEnter new address : ";
    gets(address);
}

void customer::newpassword() {
    clrscr();
    char temp_pass[100], temp_pass2[100];

    cout << "\nEnter new password : ";
    gets(temp_pass);

    int len = strlen(temp_pass);

    if (len == 100) {
        cout << "\nPlease enter a shorter password than 100 characters";
        exit(0);
    }

    cout << "\nConfirm your new password : ";
    gets(temp_pass2);

    if (strcmp(temp_pass, temp_pass2) == 0) {
        strcpy(password, temp_pass);
    } else {
        cout << "Password did not match. Restart the process.";
        newpassword();
    }
}

void customer::input(int autoid) {
    id = autoid;
    cout << "\nDEAR CUSTOMER, YOU ARE REQUIRED TO REMEMBER YOUR CUSTOMER ID! FOR FUTURE Reference";
    cout << "\nYour customer ID : " << id;
    cout << "\nDear customer, enter your name : ";
    gets(name);
    cout << "Enter your phone : ";
    cin >> phone;
    cout << "Enter your address : ";
    gets(address);
}

void customer::newname() {
    cout << "\nEnter new name : ";
    gets(name);
}

void customer::retrieve_password(char str[]) {
    strcpy(str, password);
}

void customer::create_password() {
    randomize();
    char random_password[5];
    for (int i = 0; i < 4; i++) {
        random_password[i] = (random(9) + 48);
    }
    random_password[4] = '\0';
    strcpy(password, random_password);
}

void customer::output() {
    cout << "\n\nCustomer ID : " << id;
    cout << "\nCustomer Name : " << name;
    cout << "\nPhone no. : " << phone;
    cout << "\nAddress : " << address;
}

int customer::retid() {
    return id;
}

// Bill Member Functions
int bill::retProdID() {
    int temp_id = p.retid();
    return temp_id;
}

void bill::input(int id, int qty, int c_id, date dop, product s) {
    bill_no = id;
    cust_id = c_id;
    quantity_purchased = qty;
    d = dop;
    p = s;
    total_cost = (quantity_purchased * p.retprice());
}

void bill::output() {
    char prod_name_received[50];
    p.retname(prod_name_received);

    cout << "\n\nBILL NO. : A" << bill_no;
    cout << "\nCUSTOMER ID : " << cust_id;
    cout << "\nDATE OF PURCHASE : " << (int)d.da_day << " / " << (int)d.da_mon << " / " << d.da_year;
    cout << "\nID of PRODUCT PURCHASED : " << p.retid();
    cout << "\nNAME of PRODUCT PURCHASED : " << prod_name_received;
    cout << "\nPRICE per PRODUCT : " << p.retprice();
    cout << "\nQUANTITY PURCHASED : " << quantity_purchased;
    cout << "\nTOTAL COST : " << total_cost;
}

int bill::ret_bill_no() {
    return bill_no;
}

int bill::ret_customer_id() {
    return cust_id;
}

float bill::retrevenue() {
    return total_cost;
}

int bill::retquantity() {
    return quantity_purchased;
}

int bill::retdate_day() {
    return (int)d.da_day;
}

int bill::retdate_mon() {
    return (int)d.da_mon;
}

int bill::retdate_year() {
    return d.da_year;
}

// Non-member Functions Prototypes
int customer_autogeneration();
int autogeneration();
int bill_autogeneration();
void admin();
void addrec();
void listrec();
void listrec_name();
void viewrec();
void delrec();
void buy();
void modifyrec_price();
void modifyrec_quantity();
void modifyrec_name();
void modifyrec_category();
void modifyrec_quantity_customer(int, int);
void searchrec();
int login();
void cust_details();
void search_rec_category();
void bill_generate(int, int, product);
void manageBills();
void view_allBills();
void view_oneBill();
void view_customer_bills(customer);
void customer_account_management();
void sign_up();
void customer_login();
void modifyCustomerName(customer);
void modifyPhoneNumber(customer);
void modifyAddress(customer);
void modifyPassword(customer);
void fullAccountDetails(customer);
void report();
void report_day();
void report_month();
void report_year();
long total_products();
void help();

void main() {
    clrscr();
    int ch1;
    char ch2;

    do {
        clrscr();
        cout << "\t      YOUNIX ONLINE STATIONERY CUSTOMER SHOPPING CENTRE" << endl;
        cout << "\nMAIN MENU\n" << endl;
        cout << "1 - Admin LOGIN" << endl;
        cout << "2 - Customer account MANAGEMENT" << endl;
        cout << "3 - LIST all products" << endl;
        cout << "4 - SEARCH for a category" << endl;
        cout << "5 - VIEW details of a product" << endl;
        cout << "6 - BUY a product" << endl;
        cout << "7 - HELP" << endl;
        cout << "8 - EXIT";
        cout << "\nENTER your choice : ";
        cin >> ch1;

        switch (ch1) {
        case 1:
            admin();
            break;
        case 2:
            customer_account_management();
            break;
        case 3:
            listrec_name();
            break;
        case 4:
            search_rec_category();
            break;
        case 5:
            viewrec();
            break;
        case 6:
            buy();
            break;
        case 7:
            help();
            break;
        case 8:
            cout << "\nEXIT !";
            getch();
            exit(0);
        default:
            cout << "\nWrong Choice. Try Again!";
        }
        cout << "\nDo you want to continue shopping? (Y/N) : ";
        cin >> ch2;
    } while (ch2 == 'Y' || ch2 == 'y');
}

void admin() {
    char mypass[100];
    int flag = 0;
    int ch1;
    char ch2;

    do {
        clrscr();
        cout << "Dear Admin, enter your password : ";

        for (int p = 0; p < 6; p++) {
            mypass[p] = getch();
            cout << "*";
            if (p == 5) getch();
        }

        mypass[6] = '\0';

        if (strcmp(mypass, "iamdr7") != 0) {
            cout << "\nWRONG PASSWORD!!! TRY AGAIN";
            cout << "\nTries left : " << 2 - flag << " out of 3";
            cout << "\nTo continue press ENTER";
            getch();
        } else {
            cout << "\nAccess granted! Press any key to continue";
            break;
        }

        flag++;
    } while (flag < 3);

    if (flag == 3) {
        cout << "\n\nTries exceeded. Exit!";
        getch();
        exit(0);
    }

    do {
        clrscr();
        cout << "\n\t\tYOUNIX ONLINE ADMIN INTERFACE" << endl;
        cout << "MAIN MENU" << endl;
        cout << "1 - ADD a new product" << endl;
        cout << "2 - LIST all products" << endl;
        cout << "3 - DELETE a product" << endl;
        cout << "4 - SEARCH for a product" << endl;
        cout << "5 - MODIFY name of a product" << endl;
        cout << "6 - MODIFY category of a product" << endl;
        cout << "7 - MODIFY price of a product" << endl;
        cout << "8 - MODIFY quantity of a product" << endl;
        cout << "9 - GENERATE report" << endl;
        cout << "10 - VIEW customer details" << endl;
        cout << "11 - BILL management interface" << endl;
        cout << "12 - RETURN to customer interface" << endl;
        cout << "13 - EXIT" << endl;
        cout << "Enter your choice : ";
        cin >> ch1;

        switch (ch1) {
            case 1: cout << "\nAdd a product"; addrec(); break;
            case 2: cout << "\nLIST all products"; listrec(); break;
            case 3: cout << "\nDELETE a product"; delrec(); break;
            case 4: cout << "\nSEARCH for a product"; searchrec(); break;
            case 5: cout << "\nMODIFY name of a product"; modifyrec_name(); break;
            case 6: cout << "\nMODIFY category of a product"; modifyrec_category(); break;
            case 7: cout << "\nMODIFY price of a product"; modifyrec_price(); break;
            case 8: cout << "\nMODIFY quantity of a product"; modifyrec_quantity(); break;
            case 9: report(); break;
            case 10: cust_details(); break;
            case 11: manageBills(); break;
            case 12: return;
            case 13: cout << "\nExit"; getch(); exit(0);
            default: cout << "\nWrong choice. Try again";
        }
        cout << "\nDo you want to continue with admin interface? (Y/N) : ";
        cin >> ch2;
    } while (ch2 == 'Y' || ch2 == 'y');
}

void listrec_name() {
    clrscr();
    cout << "LIST ALL PRODUCTS" << endl << endl;
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading!";
        getch();
        exit(1);
    }

    cout << "ID               NAME     PRICE(Rs)  QUANTITY" << endl;
    while (f.read((char*)&s, sizeof(s))) {
        s.output_name();
    }
    f.close();
    cout << "\n";
}

void search_rec_category() {
    product s;
    char temp_category[50], category_substitute[50], name_substitute[50];
    int flag = 0, namecount = 0;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    cout << "\nEnter type of product you want : ";
    gets(temp_category);

    clrscr();
    while (f.read((char*)&s, sizeof(s))) {
        s.retcat(category_substitute);
        s.retname(name_substitute);
        if (namecount == 0) {
            cout << "ID               NAME    PRICE(Rs)  QUANTITY" << endl;
            namecount = 1;
        }
        if (strcmpi(category_substitute, temp_category) == 0 ||
            strcmpi(temp_category, name_substitute) == 0) {
            flag = 1;
            s.output_name();
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nThis type of product doesn't exist. Please try again.";
    cout << endl;
}

void viewrec() {
    cout << "\nVIEW A PRODUCT" << endl << endl;
    product s;
    int flag = 0, temp_id;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    cout << "\nEnter product ID to view product : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            clrscr();
            flag = 1;
            cout << "ID               NAME    CATEGORY  PRICE(Rs)  QUANTITY" << endl;
            s.output();
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist";
}

void buy() {
    clrscr();
    cout << "\nBUY A PRODUCT" << endl << endl;
    int temp_id, flag = 0, cust_id_to_pass;
    char ch2;
    int no;
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened!";
        getch();
        exit(1);
    }

    cout << "\nEnter ID of product which you want to buy : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            cout << "\nYou want to buy ";
            s.output_special_for_buy();
            flag = 1;
            break;
        }
    }

    f.close();

    if (flag == 0) {
        cout << "\nProduct doesn't exist! Returning to main menu";
        getch();
        return;
    }

    cout << "\nEnter quantity of product : ";
    cin >> no;

    cout << "\nAre you sure you want to buy " << no << " quantity of this product ? (Y/N) : ";
    cin >> ch2;

    switch (ch2) {
        case 'Y':
        case 'y':
            if (s.retquantity() == 0) {
                cout << "\nQuantity Over. Please buy something else";
                cout << "\nReturning to main menu";
                return;
            } else if (s.retquantity() < no) {
                cout << "\nQuantity exceeded";
                cout << "\nOnly " << s.retquantity() << " products left.";
                cout << "\nReturning to main menu";
                return;
            }
            modifyrec_quantity_customer(temp_id, no);
            cust_id_to_pass = login();
            bill_generate(no, cust_id_to_pass, s);
            break;

        case 'N':
        case 'n':
            cout << "\nReturn to main menu";
            main();
            exit(0);

        default:
            cout << "\nWrong Choice !! Try again";
    }
}

void modifyrec_name() {
    int temp_id, flag = 0;
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    cout << "\nEnter product ID of which name is to be modified : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newname();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist";

    cout << "\nName modified successfully!\n";
}

void modifyrec_category() {
    int temp_id, flag = 0;
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    cout << "\nEnter product ID of which category is to be modified : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newcat();
            f.write((char*)&s, sizeof(s));
            flag = 1;
            break;
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist";

    cout << "\nCategory modified successfully!\n";
}

void modifyrec_quantity_customer(int temp_id, int no) {
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.reducequantity(no);
            f.write((char*)&s, sizeof(s));
            break;
        }
    }

    f.close();
}

void addrec() {
    int autoid = autogeneration();
    product s;
    fstream f;

    f.open("Project.dat", ios::binary | ios::app);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for writing.";
        exit(1);
        getch();
    }

    s.input(autoid);
    f.write((char*)&s, sizeof(s));
    f.close();

    cout << "\nProduct added successfully!\n";
}

void listrec() {
    clrscr();
    product s;
    fstream f;

    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        getch();
        exit(1);
    }
    cout << endl;
    cout << "ID               NAME    CATEGORY  PRICE(Rs)  QUANTITY" << endl;
    while (f.read((char*)&s, sizeof(s)))
        s.output();

    f.close();
}

void delrec() {
    int temp_id, flag = 0;
    product s;
    fstream fo; // Original file

    fo.open("Project.dat", ios::binary | ios::in);

    if (fo.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    fstream fc; // Copy file
    fc.open("temp.dat", ios::binary | ios::out);

    if (fc.fail()) {
        cerr << "\nFile cannot be opened for writing.";
        exit(1);
        getch();
    }

    cout << "\nEnter ID of product to be deleted : ";
    cin >> temp_id;

    while (fo.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            flag = 1;
            continue;
        }
        fc.write((char*)&s, sizeof(s));
    }

    fo.close();
    fc.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist! Try again.";

    remove("Project.dat");
    rename("temp.dat", "Project.dat");

    cout << "\nProduct deleted successfully!\n";
}

void modifyrec_price() {
    int temp_id, flag = 0;
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    cout << "\nEnter product ID of which price is to be modified : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newprice();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist";

    cout << "\nPrice modified successfully!\n";
}

void modifyrec_quantity() {
    int temp_id, flag = 0;
    product s;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    cout << "\nEnter product ID of which quantity is to be modified : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newquantity();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist";

    cout << "\nQuantity modified successfully!\n";
}

void searchrec() {
    product s;
    int flag = 0, temp_id;

    fstream f;
    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    cout << "\nEnter product ID to search for : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            clrscr();
            flag = 1;
            cout << "ID               NAME    CATEGORY  PRICE(Rs)  QUANTITY";
            s.output();
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nProduct doesn't exist";
}

int login() {
    char get_pass[100], mypass[100];
    int flag = 0;
    int autoid = customer_autogeneration();
    int temp_id_to_return;
    int temp_id;
    customer s;
    customer c;
    char ch1;

    cout << "\nAre you an existing customer? (Y/N) : ";
    cin >> ch1;

    fstream f;
    f.open("Customer.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for adding records";
        getch();
        exit(1);
    }

    if (ch1 == 'n' || ch1 == 'N') {
        s.input(autoid);
        s.create_password();
        f.seekp(0, ios::end); 
        f.write((char*)&s, sizeof(s));
        clrscr();
        cout << "\nFINALIZED Particulars - \n";
        s.allOutput();
        cout << "\nPlease note this password down for future reference";

        cout << "\nYour details have been added successfully!\n";
        temp_id_to_return = s.retid();
        cout << "\nPress any key to generate bill";
        getch();
    } else if (ch1 == 'y' || ch1 == 'Y') {
        cout << "Enter your customer ID : ";
        cin >> temp_id;

        f.seekg(0, ios::beg);

        while (f.read((char*)&c, sizeof(c))) {
            if (temp_id == c.retid()) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            f.close();
            clrscr();
            cout << "\nSuch an ID doesn't exist. Returning to main menu";
            getch();
            main();
            exit(0);
        }

        do {
            flag = 0;
            clrscr();

            c.retrieve_password(get_pass);

            int pass_len = strlen(get_pass);

            cout << "Dear Customer, enter your password : ";

            for (int p = 0; p < pass_len; p++) {
                mypass[p] = getch();
                cout << "*";

                if (p == pass_len - 1)
                    getch();
            }

            mypass[pass_len] = '\0';

            if (strcmp(mypass, get_pass) != 0) {
                cout << "\nWRONG PASSWORD!!! TRY AGAIN";
                cout << "\nTries left : " << 2 - flag << " out of 3";
                cout << "\nTo continue press ENTER";
                getch();
            } else {
                cout << "\nAccess granted! Press any key to continue";
                break;
            }

            flag++;
        } while (flag < 3);

        if (flag == 3) {
            cout << "Tries exceeded. Exit!";
            getch();
            exit(0);
        }

        clrscr();
        cout << "\nYour particulars are : \n";
        c.output();

        cout << "\nPress any key to generate bill";
        getch();

        temp_id_to_return = temp_id;
    }
    f.close();

    return temp_id_to_return;
}

void cust_details() {
    customer s;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    while (f.read((char*)&s, sizeof(s))) {
        clrscr();
        s.allOutput();
        cout << "\nPress any key to move to details of next customer";
        getch();
    }

    f.close();
}

int autogeneration() {
    product s;
    int temp_id, temp;
    fstream f;

    f.open("Project.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekg(0, ios::end);
    int pos = f.tellg();

    if (pos == 0) {
        temp_id = 101;
    } else {
        f.seekg((int)-sizeof(s), ios::end);
        f.read((char*)&s, sizeof(s));
        temp = s.retid();
        temp_id = ++temp;
    }

    f.close();
    return temp_id;
}

void bill_generate(int qty, int cust_id, product s) {
    clrscr();
    int autoid = bill_autogeneration();
    date da;
    getdate(&da);

    bill b;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::app);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for writing.";
        exit(1);
        getch();
    }

    b.input(autoid, qty, cust_id, da, s);
    f.write((char*)&b, sizeof(b));
    f.close();

    cout << "\nBill stored successfully!" << endl;
    b.output();
    cout << "\nPress any key to continue.";
    getch();
}

int bill_autogeneration() {
    bill s;
    int temp_id, temp;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekg(0, ios::end);
    int pos = f.tellg();

    if (pos == 0) {
        temp_id = 1001;
    } else {
        f.seekg((int)-sizeof(s), ios::end);
        f.read((char*)&s, sizeof(s));
        temp = s.ret_bill_no();
        temp_id = ++temp;
    }

    f.close();
    return temp_id;
}

int customer_autogeneration() {
    customer s;
    int temp_id, temp;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekg(0, ios::end);
    int pos = f.tellg();

    if (pos == 0) {
        temp_id = 1;
    } else {
        f.seekg((int)-sizeof(s), ios::end);
        f.read((char*)&s, sizeof(s));
        temp = s.retid();
        temp_id = ++temp;
    }

    f.close();
    return temp_id;
}

void manageBills(void) {
    int ch1;
    char ch2;

    do {
        clrscr();
        cout << "\nMain Menu";
        cout << "\n1 - VIEW all bills";
        cout << "\n2 - VIEW a particular bill";
        cout << "\n3 - RETURN to admin interface";
        cout << "\n4 - EXIT";
        cout << "\nEnter your choice : ";
        cin >> ch1;
        switch (ch1) {
            case 1: view_allBills(); break;
            case 2: view_oneBill(); break;
            case 3: return;
            case 4: cout << "\nCOMPLETE EXIT!"; getch(); exit(0);
            default: cout << "\nWRONG CHOICE! Try again";
        }
        cout << "\nDo you want to continue with bill management? (Y/N) : ";
        cin >> ch2;
    } while (ch2 == 'Y' || ch2 == 'y');
}

void view_allBills() {
    bill s;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    while (f.read((char*)&s, sizeof(s))) {
        clrscr();
        s.output();
        cout << "\nPress any key to move to next bill";
        getch();
    }

    f.close();
}

void view_oneBill() {
    bill s;
    int flag = 0, temp_id;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    cout << "\nEnter bill no to search for : A";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.ret_bill_no()) {
            flag = 1;
            s.output();
        }
    }

    f.close();

    if (flag == 0)
        cout << "\nBILL doesn't exist";
}

void customer_account_management() {
    clrscr();
    int ch1;
    char ch2;

    do {
        clrscr();
        cout << "\nCUSTOMER ACCOUNT MANAGEMENT";
        cout << "\n1 - SIGN UP";
        cout << "\n2 - LOGIN";
        cout << "\n3 - RETURN to shopping interface";
        cout << "\n4 - EXIT";
        cout << "\n\nPlease Note: A customer can change his name, phone and address from option 2";
        cout << "\nENTER your choice : ";
        cin >> ch1;

        switch (ch1) {
            case 1: sign_up(); break;
            case 2: customer_login(); break;
            case 3: return;
            case 4: cout << "\nComplete Exit"; getch(); exit(0);
            default: cout << "\nWrong choice. TRY AGAIN";
        }
        cout << "\nDo you want to continue with account management? (Y/N) : ";
        cin >> ch2;
    } while (ch2 == 'y' || ch2 == 'Y');
    if (ch2 == 'n' || ch2 == 'N')
        return;
}

void sign_up() {
    int autoid = customer_autogeneration();
    customer s;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::app);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for writing.";
        exit(1);
        getch();
    }

    s.input(autoid);
    s.create_password();
    f.write((char*)&s, sizeof(s));
    f.close();

    clrscr();
    cout << "\nFinalized particulars are given below:-\n";
    s.allOutput();
    cout << "\nPlease do not share this password with anyone";

    cout << "\nRecord added successfully!" << endl;
    getch();
}

void customer_login() {
    clrscr();
    customer s;
    int ch1, temp_id, flag = 0;
    char ch2, mypass[100], get_pass[100];
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "File cannot be opened for reading";
        getch();
        exit(1);
    }

    clrscr();
    cout << "Dear Customer, enter your customer ID : ";
    cin >> temp_id;

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            flag = 1;
            break;
        }
    }
    f.close();

    if (flag == 0) {
        cout << "\nDear customer, such an ID doesn't exist. Please sign up!";
        getch();
        main();
        exit(0);
    }

    flag = 0;
    do {
        clrscr();
        s.retrieve_password(get_pass);

        int pass_len = strlen(get_pass);

        cout << "Dear Customer, enter your password : ";

        for (int p = 0; p < pass_len; p++) {
            mypass[p] = getch();
            cout << "*";
            if (p == pass_len - 1)
                getch();
        }

        mypass[pass_len] = '\0';

        if (strcmp(mypass, get_pass) != 0) {
            cout << "\nWRONG PASSWORD!!! TRY AGAIN";
            cout << "\nTries left : " << 2 - flag << " out of 3";
            cout << "\nTo continue press ENTER";
            getch();
        } else {
            cout << "\nAccess granted! Press any key to continue";
            break;
        }

        flag++;
    } while (flag < 3);

    if (flag == 3) {
        cout << "Tries exceeded. Exit!";
        getch();
        exit(0);
    }

    do {
        clrscr();
        cout << "\tCUSTOMER ACCOUNT MANAGEMENT";
        cout << "\nMAIN MENU" << endl;
        cout << "CUSTOMER ID : " << s.retid() << endl;
        cout << "1 - VIEW my full account" << endl;
        cout << "2 - MODIFY customer name" << endl;
        cout << "3 - MODIFY phone number" << endl;
        cout << "4 - MODIFY address" << endl;
        cout << "5 - MODIFY password" << endl;
        cout << "6 - VIEW all of my bills" << endl;
        cout << "7 - RETURN to shopping interface" << endl;
        cout << "8 - EXIT" << endl;
        cout << "ENTER your choice : ";
        cin >> ch1;

        switch (ch1) {
            case 1: fullAccountDetails(s); break;
            case 2: modifyCustomerName(s); break;
            case 3: modifyPhoneNumber(s); break;
            case 4: modifyAddress(s); break;
            case 5: modifyPassword(s); break;
            case 6: view_customer_bills(s); break;
            case 7: main(); exit(0);
            case 8: cout << "\nCOMPLETE EXIT"; exit(0);
            default: cout << "\nWRONG Choice!";
        }
        cout << "\nDo you want to continue with personalized account management? (Y/N) : ";
        cin >> ch2;
    } while (ch2 == 'Y' || ch2 == 'y');
    if (ch2 == 'n' || ch2 == 'N')
        return;
}

void view_customer_bills(customer p) {
    clrscr();
    int temp_id = p.retid();
    int flag1 = 0;
    bill s;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.ret_customer_id()) {
            flag1 = 1;
            clrscr();
            s.output();
            cout << "\nPress any key to move to next bill";
            getch();
        }
    }

    f.close();
    if (flag1 == 0) {
        cout << "\nDear Customer, you did not buy anything yet.\nGo to main menu to buy products.\nHappy Shopping\nTeam,\nYounix Online Stationers";
    }
}

void modifyCustomerName(customer s) {
    clrscr();
    cout << "\nModify Name\n";
    int temp_id = s.retid();
    int flag = 0;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newname();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 1)
        cout << "\nName modified successfully!\n";
}

void modifyPhoneNumber(customer s) {
    clrscr();
    cout << "\nModify Phone Number\n";
    int temp_id = s.retid();
    int flag = 0;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newphone();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 1)
        cout << "\nNumber modified successfully!\n";
}

void modifyAddress(customer s) {
    clrscr();
    cout << "\nModify Address\n";
    int temp_id = s.retid();
    int flag = 0;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newaddress();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 1)
        cout << "\nAddress modified successfully!\n";
}

void modifyPassword(customer s) {
    clrscr();
    cout << "\nModify Password\n";
    int temp_id = s.retid();
    int flag = 0;
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in | ios::out);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    f.seekp(0, ios::beg);

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            f.seekp((int)-sizeof(s), ios::cur);
            s.newpassword();
            f.write((char*)&s, sizeof(s));
            flag = 1;
        }
    }

    f.close();

    if (flag == 1)
        cout << "\nPassword modified successfully!\n";
}

void fullAccountDetails(customer s) {
    int temp_id = s.retid();
    fstream f;

    f.open("Customer.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        exit(1);
        getch();
    }

    while (f.read((char*)&s, sizeof(s))) {
        if (temp_id == s.retid()) {
            cout << "\nFull DETAILS : \n";
            s.allOutput();
            cout << "\nPlease don't share this password with anyone";
        }
    }

    f.close();
}

void help() {
    clrscr();
    cout << "\t\tYOUNIX CUSTOMER HELP CENTER\n";
    cout << "Please note the following points : -" << endl;
    cout << "a. If you forgot your customer ID, then please contact admin." << endl;
    cout << "b. If you forgot your PASSWORD, then please contact admin." << endl;
    cout << "c. To RESET your password, \n\tCUSTOMER ACCOUNT MANAGEMENT > LOGIN > RESET PASSWORD" << endl;
    cout << "d. To VIEW complete details of a product, \n\tMAIN MENU > VIEW DETAILS OF A PRODUCT" << endl;
    cout << "\n\nSTORE OWNED, CREATED and DESIGNED BY\nDEVANSH RASTOGI\n12-C" << endl;
}

void report() {
    clrscr();
    int ch1;
    char ch2;
    long no_of_products = total_products();

    do {
        clrscr();
        cout << "\t      YOUNIX ONLINE REPORT GENERATION INTERFACE" << endl << endl;
        cout << "TOTAL PRODUCTS AVAILABLE : " << no_of_products << endl;
        cout << "\nMAIN MENU" << endl;
        cout << "1 - GENERATE day-wise report" << endl;
        cout << "2 - GENERATE month-wise report" << endl;
        cout << "3 - GENERATE year-wise report" << endl;
        cout << "4 - RETURN to admin interface" << endl;
        cout << "5 - RETURN to main menu" << endl;
        cout << "6 - EXIT" << endl;
        cout << "ENTER your choice : ";
        cin >> ch1;

        switch (ch1) {
            case 1: report_day(); break;
            case 2: report_month(); break;
            case 3: report_year(); break;
            case 4: return;
            case 5: main(); exit(0);
            case 6: exit(0);
            default: cout << "\nWrong Choice. Try again";
        }
        cout << "\nDo you want to continue with report management? (Y/N) : ";
        cin >> ch2;
    } while (ch2 == 'Y' || ch2 == 'y');
}

void report_day() {
    clrscr();
    bill s;
    int day, mon, year, flag = 0, flag2, temp_id, ch1;
    char ch2;
    float revenue;
    long quantity;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        getch();
        exit(1);
    }

    cout << "\nEnter the day to search for : ";
    cin >> day;
    cout << "\nEnter month : ";
    cin >> mon;
    cout << "\nEnter year : ";
    cin >> year;

    while (f.read((char*)&s, sizeof(s))) {
        flag2 = 0;

        if ((day == s.retdate_day()) && (mon == s.retdate_mon()) && (year == s.retdate_year())) {
            flag = 1;
            flag2 = 1;
        }

        if (flag2 == 1) {
            temp_id = s.ret_bill_no();
            revenue = s.retrevenue();
            quantity = s.retquantity();
            cout << "\nBill No. : A" << temp_id;
            cout << "\nRevenue Generated : Rs." << revenue;
            cout << "\nNo. of Products Sold : " << quantity;
            cout << "\n----------------------------------------";
        }
    }

    f.close();
    if (flag == 0)
        cout << "\nNo records available for this date";
}

void report_month() {
    clrscr();
    bill s;
    int mon, year, flag = 0, flag2, temp_id, ch1;
    char ch2;
    float revenue;
    long quantity;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        getch();
        exit(1);
    }

    cout << "\nEnter month to search for : ";
    cin >> mon;
    cout << "\nEnter year : ";
    cin >> year;

    while (f.read((char*)&s, sizeof(s))) {
        flag2 = 0;

        if ((mon == s.retdate_mon()) && (year == s.retdate_year())) {
            flag = 1;
            flag2 = 1;
        }

        if (flag2 == 1) {
            temp_id = s.ret_bill_no();
            revenue = s.retrevenue();
            quantity = s.retquantity();
            cout << "\nBill No. : A" << temp_id;
            cout << "\nRevenue Generated : Rs." << revenue;
            cout << "\nNo. of Products Sold : " << quantity;
            cout << "\n----------------------------------------";
        }
    }

    f.close();
    if (flag == 0)
        cout << "\nNo records available for this month";
}

void report_year() {
    clrscr();
    bill s;
    int year, flag = 0, flag2, temp_id, ch1;
    char ch2;
    float revenue;
    long quantity;
    fstream f;

    f.open("Bills.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        getch();
        exit(1);
    }

    cout << "\nEnter year to search for : ";
    cin >> year;

    while (f.read((char*)&s, sizeof(s))) {
        flag2 = 0;

        if (year == s.retdate_year()) {
            flag = 1;
            flag2 = 1;
        }

        if (flag2 == 1) {
            temp_id = s.ret_bill_no();
            revenue = s.retrevenue();
            quantity = s.retquantity();
            cout << "\nBill No. : A" << temp_id;
            cout << "\nRevenue Generated : Rs." << revenue;
            cout << "\nNo. of Products Sold : " << quantity;
            cout << "\n----------------------------------------";
        }
    }

    f.close();
    if (flag == 0)
        cout << "\nNo records available for this year";
}

long total_products() {
    product s;
    int count = 0;
    fstream f;

    f.open("Project.dat", ios::binary | ios::in);

    if (f.fail()) {
        cerr << "\nFile cannot be opened for reading.";
        getch();
        exit(1);
    }

    while (f.read((char*)&s, sizeof(s))) {
        count++;
    }

    f.close();
    return count;
}
