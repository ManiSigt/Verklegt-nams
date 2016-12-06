#ifndef LINKER_H
#define LINKER_H


class Linker
{
public:
    Linker(int id, int sciId, int comId);
    int _getId() const
    {
        return _id;
    }
    int _getSciId() const
    {
        return _sciId;
    }
    int _getComId() const
    {
        return _comId;
    }
private:
    int _id;
    int _sciId;
    int _comId;
};

#endif // LINKER_H
