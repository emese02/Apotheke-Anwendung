#include "pharmacy_repository.h"
#include <iostream>
#include <algorithm>

void Repository::initialize_repository() {
    // Repository initialisieren
    this->products.push_back(Medicine("Beres", "Beres_Pharmaceuticals", {2023, 12}, 25, 25));
    this->products.push_back(Medicine("Roswera", "KRKA", {2024, 6}, 160, 14.7));
    this->products.push_back(Medicine("Trombex", "Zentiva", {2024, 3}, 112, 28));
    this->products.push_back(Medicine("Nebilet", "BERLIN-CHEMIE_AG", {2024, 5}, 201, 12.5));
    this->products.push_back(Medicine("Lipantil", "MYLAN_MEDICAL_SAS", {2023, 4}, 80, 55));
    this->products.push_back(Medicine("Aerius", "ORGANON", {2023, 9}, 32, 25));
    this->products.push_back(Medicine("Siofor", "BERLIN-CHEMIE AG", {2024, 4}, 81, 45));
    this->products.push_back(Medicine("Merckformin", "Merck", {2023, 9}, 71, 27.34));
    this->products.push_back(Medicine("Atoris", "KRKA", {2023, 2}, 21, 13));
    this->products.push_back(Medicine("Cavinton", "Richter_Gedeon", {2025, 1}, 12, 9));
}

void Repository::add_medicine(Medicine prod) {
    // Name, Hersteller identifiziert Produkt
    string new_name, new_origin;
    new_name = prod.get_name();
    new_origin = prod.get_origin();

    // wir ueberprufen ob das Produkt ist schon in auf der Lagerliste ("name" und "origin" muessen gleich sein)
    vector<Medicine>::iterator pointer = find_if(this->products.begin(), this->products.end(),
                                                 [new_name, new_origin](Medicine med) {
                                                     string old_name, old_origin;
                                                     old_name = med.get_name();
                                                     old_origin = med.get_origin();
                                                     return old_name == new_name && old_origin == new_origin;
                                                 });
    // falls das Produkt ist nicht gefunden -> neues Produkt hinfuegen
    if (pointer == this->products.end())
        this->products.push_back(prod);
    // sonst Menge aktualisieren (quantity)
    else {
        int old_quantity = pointer->get_quantity();
        int new_quantity = prod.get_quantity();
        pointer->set_quantity(old_quantity + new_quantity);
    }
}

void Repository::delete_medicine(const string& name_prod, const string& origin_prod, int nr){
    int initial_size = this->products.size();
    // wir ueberprufen ob ein Produkt definitiv geloescht werden muss
    this->products.erase(std::remove_if(this->products.begin(), this->products.end(),
                                      [name_prod, origin_prod, nr](Medicine med) {
                                          string actual_name, actual_origin;
                                          actual_name = med.get_name();
                                          actual_origin = med.get_origin();
                                          int actual_quantity = med.get_quantity();

                                          return actual_name == name_prod && actual_origin == origin_prod &&
                                                 actual_quantity <= nr;
                                      }), this->products.end());

    // falls keine definitive Loeschung  - > Anzahl der Menge wird dekrementiert
    if (this->products.size() == initial_size)
    {
        // Produkt finden
       auto decreased_product = std::find_if(this->products.begin(), this->products.end(),
                                             [name_prod, origin_prod, nr](Medicine med) {
                                                 string actual_name, actual_origin;
                                                 actual_name = med.get_name();
                                                 actual_origin = med.get_origin();
                                                 int actual_quantity = med.get_quantity();
                                                 return actual_name == name_prod && actual_origin == origin_prod &&
                                                        actual_quantity > nr;
                                             });
       // dekrementieren
       decreased_product->set_quantity(decreased_product->get_quantity() - nr);
    }
}

std::vector <Medicine>  Repository::get_all() {
    return this->products;
}

std::vector<Medicine>* Repository::get_list()
{
    return &this->products;
}