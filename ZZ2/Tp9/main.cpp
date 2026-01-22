//#include "ComparateurZZ.hpp"
#include <iostream>
#include <queue>
#include <set>
#include "Rand_0_100.hpp"
#include <algorithm>
#include <iterator>


int main() {
    /*
    ZZ zz1("a","ds fd",4);
    ZZ zz2("fgskbj","dds============",7);
    //std::cout << (zz1 < zz2) << std::endl;
    ComparateurZZ comp;
    std::cout << comp(zz1,zz2) << std::endl;

    std::priority_queue<ZZ,std::vector<ZZ>,ComparateurZZ> Ordre;
    std::priority_queue<ZZ,std::vector<ZZ>,std::greater<ZZ>> OrdreLexico;

    Ordre.push(zz1);
    Ordre.push(zz2);

    std::cout << Ordre.top() << std::endl;

    OrdreLexico.push(zz1);
    OrdreLexico.push(zz2);

    std::cout << OrdreLexico.top() << std::endl;

    std::set<ZZ> set;
    set.insert(zz1);
    set.insert(zz2);

    std::set<ZZ>::iterator it = set.begin();

    std::cout << *it << std::endl;
    it++;
    std::cout << *it << std::endl;
    */
    std::vector<int> v(50);
    Rand_0_100 rand;
    std::generate(v.begin(),v.end(),rand);

    //std::vector<int> v2;
    //std::generate_n(v2.begin(),50,rand);

    int moy = (std::accumulate(v.begin(),v.end(),0))/50;
    std::cout << moy << std::endl;

    int min = *std::min_element(v.begin(),v.end());
    std::cout << min << std::endl;

    int max = *std::max_element(v.begin(),v.end());
    std::cout << max << std::endl;
}