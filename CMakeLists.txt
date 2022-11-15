CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(VENDORMACHINE)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

SET(APP_EXE vendingMachine)

INCLUDE_DIRECTORIES (
    ${CMAKE_SOURCE_DIR}/includes
)

ADD_EXECUTABLE(${APP_EXE}
    sources/main.cpp
    sources/CashManager.cpp
    sources/InputsManager.cpp
    sources/InventoryManager.cpp
    sources/Product.cpp
    sources/VendingMachineCore.cpp
)