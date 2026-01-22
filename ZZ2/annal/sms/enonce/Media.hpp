#ifndef __MEDIA__HPP__
#define __MEDIA__HPP__

#include <string>

class Media {
    public:
        virtual std::string afficher() const = 0;
        virtual ~Media() = default;
};

class Image : public Media {
    public:
        std::string afficher() const override;
        ~Image() override = default;
};

class Son : public Media {
    public:
        std::string afficher() const override;
        ~Son() override = default;
};

class Video : public Media {
    public:
        std::string afficher() const override;
        ~Video() override = default;
};

#endif