#pragma once
#include <vector>
#include "../Domain/medicine.h"
class Repository
{
private:
    std::vector <Medicine> products;
public:
    // Repository initialisieren
    void initialize_repository();
    // Produkt hinzufuegen
    void add_medicine(Medicine prod);
    // Product loeschen
    void delete_medicine(const string& name_prod, const string& origin_prod, int nr);
    // zurueckgeben Produkten
    std::vector<Medicine>* get_list();
    std::vector <Medicine> get_all();
};