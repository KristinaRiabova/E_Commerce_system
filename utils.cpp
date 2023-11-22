#include "utils.h"

bool parseInt(const std::string& str, int& result) {
    try {
        result = std::stoi(str);
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    }
}

bool parseDouble(const std::string& str, double& result) {
    try {
        result = std::stod(str);
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    }
}
