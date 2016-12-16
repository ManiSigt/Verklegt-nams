#include "images.h"

Images::Images()
{

}
Images::Images(int id, string name, QPixmap outPixmap, int sciId, int comId)
{
    _id = id;
    _fileName = name;
    _image = outPixmap;
    _sciId = sciId;
    _comId = comId;
}
