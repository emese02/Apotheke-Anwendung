#include <iostream>
#include "pharmacy_ui.h"
using namespace std;

UI::UI(Controller _productController) : product_controller(_productController){};

void UI::show_menu()
{
    cout<<"1. Add product\n";
    cout<<"2. Delete product\n";
    cout<<"3. Search products with a word (sorted)\n";
    cout<<"4. Search rare products\n";
    cout<<"5. Show products sorted by expiration date\n";
    cout<<"6. Show all products\n";
}

string UI::get_choice() {
    cout<<"\nChoose a number from the list: \n";
    UI::show_menu();
    int user_choice;
    cout<<"\nrequired functionality: ";
    cin>>user_choice;
    string word, name_prod, origin_prod;
    int nr;

    bool stop = false;
    while (!stop) {
        switch (user_choice) {
            case 1:
                cout << "Add product\n";
                this->product_controller.add_product(UI::read_in_product());
                break;
            case 2:
                cout << "Delete product\n";
                UI::read_in_name_origin_nr(name_prod, origin_prod, nr);
                this->product_controller.delete_product(name_prod, origin_prod, nr);
                cout << "Product deleted\n";
                break;
            case 3:
                cout << "Search products with a word(sorted): ";
                cin >> word;
                cout<<"\n\nMatching products: \n";
                UI::show_products(this->product_controller.sort_products_with_a_string(word));
                break;
            case 4:
                int number;
                cout << "Give the quantity: ";  cin >> number;
                cout<<"\n\nRare products: \n";
                UI::show_products(this->product_controller.get_rare_products(number));
                break;
            case 5:
                cout << "\n\nSorted by expiration date: \n";
                UI::show_products(this->product_controller.sort_all_products_by_expiration_date());
                break;
            case 6:
                cout << "Showing all products: \n";
                UI::show_products(this->product_controller.get_all());
                break;
            case 100:
                stop = true;
                break;
            default:
                cout<< "No such option";
                break;
        }
        cout<<"\n\nChoose a number from the list: \n";
        UI::show_menu();
        cout<<"\nrequired functionality: ";
        cin>>user_choice;
    }
}

Medicine UI::read_in_product()
{
    // Informationen von der Tastatur einlesen
    string name_prod, origin_prod;
    int quantity_prod;
    float price_prod;
    int year_exp, month_exp;

    cout << "\nname: ";
    cin >> name_prod;
    cout << "origin: ";
    cin >> origin_prod;
    cout << "expiration date - year: ";
    cin >> year_exp;
    cout << "expiration date - month: ";
    cin >> month_exp;
    cout << "quantity: ";
    cin >> quantity_prod;
    cout << "price: ";
    cin >> price_prod;
    return Medicine(name_prod,origin_prod,{year_exp,month_exp},quantity_prod,price_prod);
}

void UI::read_in_name_origin_nr(string &name_prod, string &origin_prod, int &nr)
{
    cout << "\nname: ";
    cin >> name_prod;
    cout << "origin: ";
    cin >> origin_prod;
    cout << "quantity: ";
    cin >> nr;
}

void UI::show_products(std::vector<Medicine> products)
{
    // Inhalt einer Vektor zeigen
    for (Medicine med: products)
        med.print_product();
}