#include <QVector>
#include <QDebug>
#include "Contact.h"
#include "Phonebook.h"

Phonebook::Phonebook():contacts(0){
}
Phonebook::Phonebook(const Phonebook& p):contacts(p.getContacts()){
}
Phonebook& Phonebook::operator=(const Phonebook& p){
    if (this == &p)
            return *this;
        this->contacts=p.getContacts();
        return *this;
}
Phonebook::~Phonebook(){
}
bool Phonebook::addContact(const Contact& c){
    if(!isNameExist(c.getName())&&!isNumbersExist(c.getNumbers())){
        contacts.append(c);
        return true;
    }
    return false;
}
void Phonebook::sortContacts(){
    std::sort(contacts.begin(), contacts.end());
}
bool Phonebook::addNumber(const QString& name,const QString& number){
    try {
       return addNumber(getContactByNameP(name),number);
    } catch (QString mess) {
        return false;
    }
}
bool Phonebook::addNumber(Contact& contact,const QString& n){
    QString number(n);
    if(isNumberExist(number))
        return false;
    try {
        return contact.addNumber(number);
    } catch (QString mess) {
        return false;
    }
}
bool Phonebook::deleteContactByName(const QString& name){
    try {
         return contacts.removeOne(getContactByName(name));
    } catch (QString mess) {
        return false;
    }

}
bool Phonebook::deleteNumber(const QString& n){
    QString number(n);
    try {
        Contact& c=getContactByNumberP(number);
        if(c.deleteNumber(number)){
            if(c.numbersSize()==0)
                contacts.removeOne(c);
            return true;
        }
    } catch (QString mess) {
        return false;
    }
    return false;

}
const QVector<Contact> Phonebook::searchByName(const QString& name) const{
    QVector<Contact> searched;
    for(int i=0;i<contacts.size();++i){
        if ( contacts.at(i).getName().toLower().contains(name.toLower()))
            searched.append(contacts[i]);
    }
    return searched;
}
const QVector<Contact> Phonebook::searchByNumber(const QString& n) const{
    QString number(n);
    number.replace("+","");
    QVector<Contact> searched;
    for(int i=0;i<contacts.size();++i){
        for(int j=0;j<contacts.at(i).numbersSize();++j)
        if (contacts.at(i).getNumbers()[j].contains(number)){
            searched.append(contacts[i]);
            break;
        }
    }
    return searched;
}
bool Phonebook::editNumber(const QString& oldNumber,const QString& newNumber){
    if(!isNumberExist(newNumber))
            try {
                return getContactByNumberP(oldNumber).changeNumber(oldNumber,newNumber);
            } catch (QString mess) {
                return false;
            }
        return false;
}
bool Phonebook::editName(const QString& oldName,const QString& newName){
        if(!isNameExist(newName))
            try {
                return getContactByNameP(oldName).setName(newName);
            } catch (QString mess) {
                return false;
            }
        return false;

}
const Contact& Phonebook::getContactByName(const QString& name) const{
    for(int i=0;i<contacts.size();++i){
        if ( QString::compare( contacts.at(i).getName(), name, Qt::CaseInsensitive)==0)
            return contacts.at(i);
    }
    throw "You don`t have a contact with a name "+name;
}
const Contact& Phonebook::getContactByNumber(const QString& number) const{
    for(int i=0;i<contacts.size();++i){
        if (contacts.at(i).getNumbers().contains(number))
            return contacts.at(i);
    }
    throw "You don`t have a contact with a number "+number;
}
Contact& Phonebook::getContactByNameP(const QString& name){
    for(int i=0;i<contacts.size();++i){
        if ( QString::compare( contacts.at(i).getName(), name, Qt::CaseInsensitive)==0)
            return contacts[i];
    }
    throw "You don`t have a contact with a name "+name;
}
Contact& Phonebook::getContactByNumberP(const QString& number){
    for(int i=0;i<contacts.size();++i){
        if (contacts.at(i).getNumbers().contains(number))
            return contacts[i];
    }
    throw "You don`t have a contact with a number "+number;
}
int Phonebook::size() const{
    return contacts.length();
}
const QVector<Contact>& Phonebook::getContacts()const{
    return contacts;
}
bool Phonebook::isNameExist(const QString& name){
    foreach(Contact c, contacts){
        if ( QString::compare( c.getName(), name, Qt::CaseInsensitive)==0)
            return true;
    }
    return false;
}
bool Phonebook::isNumbersExist(const QStringList& numbers){
    foreach(QString number, numbers){
        if (isNumberExist(number))
            return true;
    }
    return false;
}
bool Phonebook::isNumberExist(const QString& n){
    QString number(n);
    number.replace("+","");
    foreach(Contact c, contacts){
        foreach(QString n, c.getNumbers()){
            n.replace("+","");
            if ( QString::compare(n, number)==0)
                return true;
        }
    }
    return false;
}
