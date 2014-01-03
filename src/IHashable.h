#ifndef IHASHABLE_H
#define IHASHABLE_H

#include <QString>

/**
 * @brief
 * Interface für Klassen bei denen man einen Hashcode<BR>
 * der Klassen-Instanz generieren können soll
 */
class IHashable
{
public:
    /**
     * @brief Abstrakte Methode zum Generieren eines Hashcodes der Klassen-Instanz
     * @return Hashcode Klassen-Instanz
     */
    virtual QString getHashCode() = 0;
};

#endif // IHASHABLE_H
