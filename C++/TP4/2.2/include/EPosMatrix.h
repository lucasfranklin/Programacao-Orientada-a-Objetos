#ifndef EPOSMATRIX_H
#define EPOSMATRIX_H


class EPosMatrix
{
private:
    int nLine;
public:
    EPosMatrix(int line) : nLine(line) {};
    void msg();
    virtual ~EPosMatrix();
protected:
private:
};

#endif // EPOSMATRIX_H
