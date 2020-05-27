#include "Contact.h"
#include <QRegExp>
#include <QStringList>
#include <iostream>
Contact::Contact(const QString&  name,const QStringList& numbers):name(name),numbers(numbers)
{
if(!isValid()){
    throw "Illegal contact!!!";
    this->name= "unknown";
    this->numbers.clear();
}
}
Contact::Contact(const QString& name ,const QString& number):name(name), numbers(){
    numbers.append(number);
    if(!isValid()){
        throw "Illegal contact!!!";
        this->name= "unknown";
        this->numbers.clear();
    }
}
Contact::Contact(const Contact& c):name(c.getName()), numbers(c.getNumbers()){

}
Contact::Contact():name("unknown"), numbers(){

}
Contact& Contact::operator=(const Contact& c){
    if (this == &c)
            return *this;
        this->name=c.getName();
        this->numbers=c.getNumbers();
        return *this;
}
Contact::~Contact(){
}
bool Contact::isValid(){
    return isValidName(this->name)&&isValidNumbers();
}
bool Contact::isValidName(const QString& name){
    return name.trimmed().length()!=0;
}
bool Contact::isValidNumbers(){

    foreach(QString number, numbers){
        if(!isValidNumber(number))
            return false;
    }
    return true;
}
bool Contact::isValidNumber(const QString& num){
    QRegExp re("[+]?\\d{3,15}");
    return re.exactMatch(num);
}
bool Contact::addNumber(const QString&  number){
if(isValidNumber(number)&&!(numbers.contains(number)||numbers.contains("+"+number)||(number.startsWith("+")&&numbers.contains(number.mid(1,number.length()-1))))){
    numbers.append(number);
    return true;
}
return false;
}
bool Contact::deleteNumber(QString& number){
    number.replace("+","");
    return numbers.removeOne(number)||numbers.removeOne("+"+number);
}
bool Contact::changeNumber(const QString&  oldNumber,const QString& newNumber){
if(isValidNumber(newNumber)&&numbers.contains(oldNumber)){
    numbers.removeOne(oldNumber);
    numbers.append(newNumber);
    return true;
}
return false;
}
bool Contact::setName(const QString&  name){
    if(isValidName(name)){
        this->name=name;
        return  true;
    }
    return false;
}

int Contact::numbersSize() const{
    return numbers.length();
}
const QString& Contact::getName()const{
    return name;
}
const QStringList& Contact::getNumbers()const{
    return numbers;
}

std::ostream& operator<<(std::ostream& os, const Contact& c){
    os<<c.getName().toStdString()<<std::endl;
    foreach(QString number, c.getNumbers()){
        os<<number.toStdString()<<std::endl;
    }
    return os;
}

bool operator==(const Contact& c1, const Contact& c2){
    return  QString::compare(c1.getName(),c2.getName(), Qt::CaseInsensitive)==0&&c1.getNumbers()==c2.getNumbers();
}
bool operator<(const Contact& c1, const Contact& c2){
    return c1.getName()<c2.getName();
}
