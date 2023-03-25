#include <string>
#include <iostream>
#include "medicine.h"
using namespace std;

Medicine::Medicine(string name, string origin, Date expiration_date, int quantity, float price)
{
    this->name = name;
    this->origin = origin;
    this->expiration_date = expiration_date;
    this->quantity = quantity;
    this->price = price;
}

string Medicine::get_name() const
{
    return this->name;
}

string Medicine::get_origin() const
{
    return this->origin;
}

int Medicine::get_quantity() const
{
    return this->quantity;
}

void Medicine::set_quantity(int value)
{
    this->quantity = value;
}

Date Medicine::get_date() {
    return this->expiration_date;
}

void Medicine::print_product() {
    cout << "\nProduct name: " << this->name << "  --   origin: " << this->origin << " --   quantity: " << this->quantity
         << "  --   Expiration date: " << this->expiration_date.year << " / " << this->expiration_date.month
         << "  -- Price " << this->price;
}

