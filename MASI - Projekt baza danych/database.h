#ifndef DATABASE_H
#define DATABASE_H

#include <QString>

class Database {
public:
    static bool initialize();
    static bool insertRecord(const QString &nazwa,
                             const QString &opis,
                             const QString &val1,
                             const QString &val2,
                             const QString &valW,
                             const QString &valA,
                             const QString &valB,
                             const QString &valU);
};

#endif // DATABASE_H
