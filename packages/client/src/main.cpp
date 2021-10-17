#include "../include/engine/Core.hpp"
#include "../include/Error.hpp"
#include "../include/Global.hpp"
#include <iostream>

int main(int _gc, char *_gv[]) {
    if (_gc == 2 && std::string(_gv[1]) == "--help") {
        return EXIT_SUCCESS;
    }
    if (_gc != 3)
        return EXIT_FAILURE;
    try {
        Core launcher((std::string(_gv[1])), std::string(_gv[2]));

        launcher.checkConnection();
        launcher.init();
        launcher.run();

    } catch (Error &e) {
        std::cout << "Error caught" << std::endl;
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}