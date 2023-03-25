#include <algorithm>
#include <string.h>
#include <iostream>
#include "pharmacy_controller.h"

Controller::Controller(Repository repository) {
    this->pharmacy_repo = repository;
}

// bei Produkt loeschen und hinzufuegen Methoden der Repository werden aufgeruft werden
void Controller::add_product(Medicine prod) {
    this->pharmacy_repo.add_medicine(prod);
}

void Controller::delete_product(string name_prod, string origin_prod, int nr) {
    this->pharmacy_repo.delete_medicine(name_prod, origin_prod, nr);
}

std::vector<Medicine> Controller::sort_products_with_a_string(string word) {
    // wir zaehlen wie viele Produkten es gibt mit der angegebenem Wort
    int count = std::count_if(pharmacy_repo.get_list()->begin(), pharmacy_repo.get_list()->end(),
                              [word](Medicine med)
                              {
                                return strstr(med.get_name().c_str(), word.c_str()) != nullptr;
                              });
    // wir machen "Platz" in die neuer Container
    std::vector<Medicine> searched_products;
    while (count > 0)
    {
        searched_products.push_back(Medicine("","",{0,0},0,0));
        count--;
    }
    // wir kopieren die Produkten, die die angagebene  Bedingung erfuellen
    std::copy_if( pharmacy_repo.get_list()->begin(), pharmacy_repo.get_list()->end(), searched_products.begin(),
                            [word](Medicine med)
                            {
                                return strstr(med.get_name().c_str(), word.c_str()) != nullptr;
                            });

    // wir sortieren die neue Vector nach Name
   sort(searched_products.begin(), searched_products.end(),
         [](Medicine med1, Medicine med2)
         { return med1.get_name() < med2.get_name(); });

   // sortierte vector zurueckgeben
   return searched_products;
}

std::vector<Medicine> Controller::get_rare_products(int given_quantity) {
    // wir zaehlen wie viele Produkten es gibt mit kleiner als given_quantity
    int count = std::count_if(pharmacy_repo.get_list()->begin(), pharmacy_repo.get_list()->end(),
                              [given_quantity](Medicine med)
                              {
                                  int actual_quantity = med.get_quantity();
                                  return actual_quantity < given_quantity;
                              });
    // wir machen Platz in der neuer Container
    std::vector<Medicine> rare_products ;
    while (count > 0)
    {
     rare_products.push_back(Medicine("","",{0,0},0,0));
     count --;
    }
    // wir kopieren die Werte
    std::copy_if(pharmacy_repo.get_list()->begin(), pharmacy_repo.get_list()->end(), rare_products.begin(),
                            [given_quantity] (Medicine med)
                            {
                                int actual_quantity = med.get_quantity();
                                return actual_quantity < given_quantity;
                            });
    // neue vector zurueckgeben
    return rare_products;
}

std::vector<Medicine> Controller::sort_all_products_by_expiration_date() {
    // wir kopieren alle Produkten und danach sortieren
    std::vector<Medicine> sorted = this->pharmacy_repo.get_all();

    sort(sorted.begin(), sorted.end(),
         [](Medicine med1, Medicine med2)
         {
             int year1 = med1.get_date().year, year2 = med2.get_date().year;
             int month1 = med1.get_date().month, month2 = med2.get_date().month;
             return year1 < year2 || (year1 == year2 && month1 < month2);
         });
    return sorted;
}

std::vector<Medicine> Controller::get_all()
{
    return this->pharmacy_repo.get_all();
}