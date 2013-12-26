#ifndef IHASHABLE_H
#define IHASHABLE_H

#include <QString>

class IHashable
{
public:
    virtual QString getHashCode() = 0;
};

#endif // IHASHABLE_H
