#include <iostream>
#include "productcatalog.h"
#include "inventory.h"
#include "userinterface.h"
#include "FileParser.h"

int main() {
    ProductCatalog productCatalog;
    Inventory inventory(productCatalog);

    if (!FileParser::parseConfigFile("products.txt", productCatalog)) {
        std::cerr << "Error parsing configuration file. Exiting." << std::endl;
        return 1;
    }

    UserInterface userInterface(productCatalog, inventory);
    userInterface.run();

    return 0;
}
