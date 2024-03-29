/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** run.cpp
*/

#include "Arcade/Core.hpp"
#include "Arcade/Constants.hpp"
#include "Arcade/RuntimeException.hpp"

constexpr char const *NO_DISPLAY = "DISPLAY environment variable is not set";

constexpr std::string_view UNKNOW_ERROR = "Unknown error";
constexpr std::string_view CORE_EXCEPT = "Core exception: ";
constexpr std::string_view RUNTIME_EXCEPT = "Runtime exception: ";

int Arcade::Core::runArcade(const std::string &path)
{
    if (getenv("DISPLAY") == nullptr) {
        throw CoreException{NO_DISPLAY};
    }
    try {
        switchLib<IRenderer>(path);
        getLibraries(path);
        _renderer->getWindow()->openWindow(WIDTH, HEIGHT);
        loadMenu();
        mainLoop();
    } catch (CoreException &e) {
        std::cerr << CORE_EXCEPT << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (const RuntimeException &e) {
        std::cerr << RUNTIME_EXCEPT << e.what() << '\n';
        return EPITECH_ERROR;
    } catch (...) {
        std::cerr << UNKNOW_ERROR << '\n';
        return EPITECH_ERROR;
    }
    return SUCCESS;
}
