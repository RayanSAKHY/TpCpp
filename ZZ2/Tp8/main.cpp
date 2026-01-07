#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>

using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::make_pair;
using mss = std::map<string, string> ;

const string& first(const pair<string,string>& p) { return p.first; }

string paire(const pair<string,string>& p) {
    string s = p.first + " : "+p.second;
    return s;
}

void mapCopy(mss& src,mss& dst) {
    mss::iterator it = src.begin();
     while (it!=src.end()) {
         dst[it->first] = it->second;
         ++it;
     }
}

void writeFromStream(std::istream& s, mss& m, std::ostream& o = std::cout) {
    while (!s.eof()) {
        string first, second;
        s >> first >> second;
        //cout << "test : " + first << " " << second << endl;
        m[first] = second;
        o << first << " " << second << endl;
    }
}

string searchFromStream(const string& key,mss& o) {
    string res;
    mss::iterator it = o.find(key);
    if (it == o.end()) res = "non trouvee";
    else res = paire(*it);
    return res;
}

int main(int argc, char ** argv) {

    std::string input = "loic 64\njfnd 0\nvjhbdkf 62\nGHKBRDF 75";
    std::istringstream stream(input);

    mss m;

    m.insert(pair<string,string>("loic", "405042"));
    m.insert(make_pair("isima", "405000"));
    m["secours"]  = "42";

    // mss::iterator it = m.find("loic");
    // if (it==m.end()) cout << "et moi ?";
    //
    //
    //
    // while(it!=m.end()) {
    //     cout << it->first  << " "
    //          << it->second << endl;
    //     ++it;
    // }

    mss liste;

    mapCopy(m,liste);

    mss::iterator it2 = liste.begin();

    while(it2!=liste.end()) {
        cout << it2->first  << " "
             << it2->second << endl;
        ++it2;
    }

    //transform(liste.begin(), liste.end(),
    //  std::ostream_iterator<string>(cout, " \n"), paire);

    if (argc > 0) {
        mss liste2;

        writeFromStream(stream,liste2,std::cout);
        cout << endl;

        cout << searchFromStream(argv[1],liste2) << endl;
    }

    return 0;
}