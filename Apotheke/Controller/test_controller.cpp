#include "test_controller.h"
#include "pharmacy_controller.h"
#include <string>
#include <iostream>
#include <cassert>
#include <memory>

void test_sort_products_with_a_string()
{
    std::string word = "for";
    auto repository = std::make_unique<Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller> controller = std::make_unique<Controller>(*repository);
    assert(controller->sort_products_with_a_string("for").size() == 2);
    assert(controller->sort_products_with_a_string("ri").size() == 2);
    assert(controller->sort_products_with_a_string("ab").empty());
    assert(controller->sort_products_with_a_string("ton").size() == 1);
}

void test_get_rare_products()
{
    auto repository = std::make_unique<Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller> controller = std::make_unique<Controller>(*repository);
    assert (controller->get_rare_products(50).size() == 4);
    assert (controller->get_rare_products(100).size() == 7);
    assert (controller->get_rare_products(10).empty());
}

void test_sort_all_products_by_expiration_date()
{
    auto repository = std::make_unique<Repository>();
    repository->initialize_repository();
    std::unique_ptr<Controller> controller = std::make_unique<Controller>(*repository);
    std::vector<Medicine> sorted = controller->sort_all_products_by_expiration_date();
    assert(sorted.begin()->get_name() == "Atoris");
    assert((sorted.begin()+1)->get_name() == "Lipantil");
    assert((sorted.begin()+8)->get_name() == "Roswera");
}

void test_controller()
{
    test_sort_products_with_a_string();
    test_sort_all_products_by_expiration_date();
    test_get_rare_products();
    cout<<"\nController was tested succesfully!\n";
}