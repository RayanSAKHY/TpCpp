#ifndef POINT_HPP
#define POINT_HPP

// Fichier Point.hpp
// Il manque les gardiens mais je vous laisse les ajouter,
// c'est comme en C et le pragma once c'est nul
class Point {
    // par défaut, tout est privé dans une "class"
    int x;
    int y;

public:
    void init();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void deplacerDe(int x,int y);
    void deplacerVers(int x,int y);

};

#endif