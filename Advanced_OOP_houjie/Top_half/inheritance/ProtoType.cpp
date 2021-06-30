#include <vector>
#include <iostream>

enum ImageType{
    LAST, SPOT
};

class Image{
public:
    virtual void draw() = 0;
    static Image* findAndClone(ImageType);

protected:
    virtual ImageType returnType() = 0;
    virtual Image* clone() = 0;
    static void addProtoType(Image* im) {
        protolist.push_back(im);
    }

private:
    static std::vector<Image*> protolist;
};

std::vector<Image*> Image::protolist;

Image* Image::findAndClone(ImageType it) {
    for (auto p : protolist)
        if(p->returnType() == it)
            return p->clone();
}

class LandSatImage : public Image {
public:
    void draw() { std::cout << "LandSatImage::draw" << id << '\n'; }
    ImageType returnType() {
        return LAST;
    }
    Image* clone() {
        return new LandSatImage(1);
    }

protected:
    LandSatImage(int dummy) {
        id = count++;
    }

private:
    static LandSatImage _landSatImage;
    LandSatImage(){
        addProtoType(this);
    }
    int id;
    static int count;
};

LandSatImage LandSatImage::_landSatImage;
int LandSatImage::count = 1;

class SpotImage : public Image {
public:
    void draw() { std::cout << "SpotImage::draw" << id << '\n'; }
    ImageType returnType() {
        return SPOT;
    }
    Image* clone() {
        return new SpotImage(1);
    }

protected:
    SpotImage(int dummy) {
        id = count++;
    }

private:
    static SpotImage _spotImage;
    SpotImage(){
        addProtoType(this);
    }
    int id;
    static int count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::count = 1;