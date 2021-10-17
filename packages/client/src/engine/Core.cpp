#include "../../include/engine/Core.hpp"
#include "../../include/Event.hpp"
#include "../../include/Error.hpp"
#include "../../include/Global.hpp"

Core::Core(std::string ip, std::string port)
    : _ip(ip), _port(port) {
}

Core::~Core() {
    if (interface)
        delete interface;
}

void Core::checkConnection() {
    bool connected = true; // juste test file

    if (!connected)
        throw Error("Please entrer correct ip adresse or port");
    this->interface = new Interface();
}

void Core::init() {

}

void Core::run() {
    Event event;

    //if (DEBUG_CONTROLLER)
    std::cout << "[Client] Run core engine" << std::endl;
    interface->init();
    while (interface->isOn() != false) {
        interface->update();
        interface->clearScreen();
        event = interface->handleEvent();
        interface->render();
        interface->refreshScreen();

        if (event == Event::quit)
            break;
    }
    //if (DEBUG_CONTROLLER)
    std::cout << "[Client] Close launcher" << std::endl;
}