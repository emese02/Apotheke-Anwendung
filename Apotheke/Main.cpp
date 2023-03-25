#include "Repository/pharmacy_repository.h"
#include "Controller/pharmacy_controller.h"
#include "UI/pharmacy_ui.h"
#include "Repository/test_repository.h"
#include "Controller/test_controller.h"
#include <memory>
#include <iostream>
int main()
{
    std::unique_ptr<Repository> repository = std::make_unique<Repository> ();
    repository->initialize_repository();
    std::unique_ptr<Controller> controller = std::make_unique<Controller>(*repository);
    unique_ptr<UI> interface = std::make_unique<UI>(*controller);

    interface->get_choice();
    return 0;
}