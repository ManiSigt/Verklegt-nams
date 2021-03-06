#ifndef LINKER_H
#define LINKER_H


class Linker
{
public:
    Linker(int id, int sciId, int comId); // Class constructor for variables.
    int getId() const
    {
        return _id;
    }
    int getSciId() const
    {
        return _sciId;
    }
    int getComId() const
    {
        return _comId;
    }
private:
    int _id;
    int _sciId;
    int _comId;
};

#endif // LINKER_H
