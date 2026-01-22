#include "Media.hpp"

std::string Image::afficher() const {
    return "[[image]]";
}

std::string Son::afficher() const {
    return "[[son]]";
}

std::string Video::afficher() const {
    return "[[video]]";
}