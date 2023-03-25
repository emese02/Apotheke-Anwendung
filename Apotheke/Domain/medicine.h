#pragma once
#include <string>
using namespace std;

struct Date
{
    int year, month;
};

class Medicine
{
private:
    string name;
    string origin;
    Date expiration_date;
    int quantity;
    float price;

public:
    // Konstruktor
    Medicine(string name, string origin, Date expiration_date, int quantity, float price);
    // Name getter
    string get_name() const;
    // Hersteller getter
    string get_origin() const;
    // Menge getter
    int get_quantity() const;
    // Menge setter
    void set_quantity(int value);
    // Datum getter
    Date get_date();
    // Informationen ueber Produkt zeigen
    void print_product();

};