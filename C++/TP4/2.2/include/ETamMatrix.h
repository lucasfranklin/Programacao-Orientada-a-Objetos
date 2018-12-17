#ifndef ETAMMATRIX_H
#define ETAMMATRIX_H


class ETamMatrix
{
private:
    int nLine;
public:
    ETamMatrix(int errorLine) : nLine(errorLine) {};
    void msg();
    virtual ~ETamMatrix();
protected:
private:
};

#endif // ETAMMATRIX_H
