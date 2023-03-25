#pragma once
#include "../Repository/pharmacy_repository.h"
class Controller
{
private:
    Repository pharmacy_repo;
public:
    Controller(Repository repository);
    void add_product(Medicine prod);
    void delete_product(string name_prod, string origin_prod, int nr);
    std::vector<Medicine> sort_products_with_a_string(string word);
    std::vector<Medicine> get_rare_products(int given_quantity);
    std::vector<Medicine> sort_all_products_by_expiration_date();
    std::vector<Medicine> get_all();
};