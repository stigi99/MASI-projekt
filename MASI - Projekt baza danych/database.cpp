#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>



static QSqlDatabase db;
bool Database::initialize() {


QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("moja_baza.db");
    if (!db.open()) {
        qDebug() << "Błąd otwierania bazy:" << db.lastError().text();
        return false;
    }

    QSqlQuery query(db);
    return query.exec(R"(
        CREATE TABLE IF NOT EXISTS zapisy (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nazwa TEXT NOT NULL,
            opis TEXT,
            val1 TEXT,
            val2 TEXT,
            valW TEXT,
            valA TEXT,
            valB TEXT,
            valU TEXT


        )
    )");
}

bool Database::insertRecord(const QString &nazwa,
                            const QString &opis,
                            const QString &val1,
                            const QString &val2,
                            const QString &valW,
                            const QString &valA,
                            const QString &valB,
                            const QString &valU) {

    QSqlQuery query(db);
    query.prepare("INSERT INTO zapisy (nazwa, opis, val1, val2, valW, valA, valB, valU) VALUES (:nazwa, :opis, :val1, :val2, :valW, :valA, :valB, :valU)");
    query.bindValue(":nazwa", nazwa);
    query.bindValue(":opis", opis);
    query.bindValue(":val1", val1);
    query.bindValue(":val2", val2);
    query.bindValue(":valW", valW);
    query.bindValue(":valA", valA);
    query.bindValue(":valB", valB);
    query.bindValue(":valU", valU);
    if (!query.exec()) {
        qDebug() << "Błąd zapisu:" << query.lastError().text();
        return false;
    }
    return true;
}
