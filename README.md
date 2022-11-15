# JPB-vendingMachine

## How is the machine working ?

The vending machine is just a prompt machine waiting for your actions to answer and act as much as possible as a classic vending machine.

If you enter a number (float) (0.25 | 0.10 | 0.05 to respect the possible coins) it will add money to the machine (to buy something)

You can enter the name of the product you want (Cola | Chips | Candy) (it's not case sensitive) the product will be set as "to buy" if enough money is present in the machine, it will consume your money. Else it wait for another product to be selected or more money to be added.

When a product is bought, if more money was present it send you back money (precising what coins is sent back)

At the begining of the program and every single buy, the machine display the number of product still present

Hope I handle as much errors as possible

## How to compile and run the machine ?

For Linux just run the Makefile with a simple `make -j` command then you can run the executable using `./vendingMachine`


For Windows create a build folder `mkdir build` enter this newly created directory `cd build` and use the following cmake commands to get the executable:
`cmake ..` and `cmake --build .`
