#ifndef ECOMPMATRIX_H
#define ECOMPMATRIX_H


class ECompMatrix
{
private:
    int nLine;
public:
    ECompMatrix(int line):nLine(line) {};
    void msg();
    virtual ~ECompMatrix();
protected:
private:
};

#endif // ECOMPMATRIX_H
