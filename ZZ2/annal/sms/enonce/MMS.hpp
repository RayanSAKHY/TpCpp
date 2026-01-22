#ifndef __MMS__HPP__
#define __MMS__HPP__

#include "sms.hpp"
#include "Media.hpp"
#include <vector>
#include <sstream>
#include <iterator>

class MMS : public SMS {
    private:
        std::vector<Media *> listMedia = std::vector<Media *>();
    public:
        MMS(std::string exp,std::string dest, std::string date);
        virtual std::string afficher() const override;
        void joindre(Media * media);
        ~MMS();
        std::string getDe() const;
        std::string getA() const;
};

#endif