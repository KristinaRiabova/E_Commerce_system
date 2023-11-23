#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "productcatalog.h"
#include "Electronics.h"
#include "books.h"
#include "clothing.h"
#include "utils.h"

class FileParser {
public:
    static bool parseConfigFile(const std::string& filename, ProductCatalog& productCatalog);
};

#endif // FILE_PARSER_H
