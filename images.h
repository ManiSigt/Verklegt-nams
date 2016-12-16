#ifndef IMAGES_H
#define IMAGES_H
#include <string>
#include <QPixmap>

using namespace std;

class Images
{
public:
    Images();
    Images(int id, string name, QPixmap outPixmap, int sciId, int comId);
    int getId()
    {
        return _id;
    }
    QPixmap getImage()
    {
        return _image;
    }
    int getSciId()
    {
        return _sciId;
    }
    int getComId()
    {
        return _comId;
    }
    string getFileName()
    {
        return _fileName;
    }

private:
    string _fileName;
    QPixmap _image;
    int _sciId;
    int _comId;
    int _id;
};

#endif // IMAGES_H
