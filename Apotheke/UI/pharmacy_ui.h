#pragma once
#include "../Controller/pharmacy_controller.h"
class UI
{
private:
    Controller product_controller;
public:
    UI(Controller _productController);
    string get_choice();
    void show_menu();
    Medicine read_in_product();
    void read_in_name_origin_nr(string &name_prod, string &origin_prod, int &nr);
    void show_products(std::vector<Medicine> products);
};