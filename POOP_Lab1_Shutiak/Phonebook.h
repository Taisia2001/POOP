#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <QVector>
#include "Contact.h"
class Phonebook{
public:
    Phonebook();
    Phonebook(const Phonebook&);
    Phonebook& operator=(const Phonebook&);
    ~Phonebook();
    void sortContacts();
    bool addContact(const Contact& );
    bool addNumber(Contact&,const QString&);
    bool addNumber(const QString&,const QString&);
    bool deleteContactByName(const QString&);
    bool deleteNumber(const QString&);
    const QVector<Contact> searchByName(const QString&) const;
    const QVector<Contact> searchByNumber(const QString&)const;
    const Contact& getContactByName(const QString&) const;
    const Contact& getContactByNumber(const QString&) const;
    bool editNumber(const QString& ,const QString& );
    bool editName(const QString&,const QString& );
    int size() const;
    const QVector<Contact>& getContacts()const;
    bool isNameExist(const QString&);
    bool isNumbersExist(const QStringList&);
    bool isNumberExist(const QString&);
private:
    QVector<Contact> contacts;
    Contact& getContactByNameP(const QString&);
    Contact& getContactByNumberP(const QString&);

};
QDebug operator<<(QDebug, const Phonebook&);
#endif // PHONEBOOK_H
