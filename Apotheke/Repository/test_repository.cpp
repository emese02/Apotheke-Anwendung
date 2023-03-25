#include "test_repository.h"
#include <cassert>
#include <iostream>
#include "pharmacy_repository.h"
#include <memory>
void test_initialize_repository()
{
    auto repo = std::make_unique<Repository>();
    repo->initialize_repository();
    assert(repo->get_all().size() == 10);
}

void test_add_medicine()
{
    auto repo = std::make_unique<Repository>();
    repo->initialize_repository();
    // neues Produkt -> neues Element hinfuegen
    Medicine med1("Nurofen", "RECKITT", {2024, 7}, 31, 15.7);
    repo->add_medicine(med1);
    assert(repo->get_list()->size() == 11 );
    // vorhandenes Produkt -> wird nicht noch einmal hinzugefuegt werden, nur die Anzahl der Elemente wird erhoeht
    Medicine med2("Beres", "Beres_Pharmaceuticals", {2023, 12}, 100, 25);
    repo->add_medicine(med2);
    assert(repo->get_list()->size() == 11 );
    assert(repo->get_list()->begin()->get_quantity() == 125);
}

void test_delete_medicine()
{
    auto repos = std::make_unique<Repository>();
    repos->initialize_repository();
    assert(repos->get_list()->size() == 10 );
    // Produkte loeschen, aber es bleibt noch einige -> die Menge verringern
    assert(repos->get_list()->end()->get_quantity() == 31);
    repos->delete_medicine("Nurofen","RECKITT", 10);      //vorher: 31 ->   31-10 = 21
    assert(repos->get_list()->end()->get_quantity() == 21);
    assert(repos->get_list()->size() == 10 );
    // definitive Loeschung -> Produkt entfernen
    repos->delete_medicine("Aerius", "ORGANON", 32);
    assert(repos->get_list()->size() == 9 );
}

void test_repository()
{
    test_initialize_repository();
    test_add_medicine();
    test_delete_medicine();
    cout<<"\nRepository was tested succesfully!\n";
}