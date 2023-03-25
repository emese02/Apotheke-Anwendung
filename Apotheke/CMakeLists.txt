cmake_minimum_required(VERSION 3.21)
project(labor4)

set(CMAKE_CXX_STANDARD 14)

add_executable(labor4 Main.cpp Repository/pharmacy_repository.cpp Domain/medicine.cpp Controller/pharmacy_controller.cpp UI/pharmacy_ui.cpp Repository/test_repository.cpp Controller/test_controller.cpp)
