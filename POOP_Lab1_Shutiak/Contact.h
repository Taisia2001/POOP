#ifndef CONTACT_H
#define CONTACT_H
#include <QString>
#include <QStringList>
class Contact{
public:
    Contact(const QString& ,const QStringList&);
    Contact(const QString& ,const QString&);
    Contact(const Contact&);
    Contact();
    Contact& operator=(const Contact&);
    ~Contact();
    bool addNumber(const QString& );
    bool deleteNumber(QString& );
    bool changeNumber(const QString& ,const QString& );
    bool setName(const QString& );
    int numbersSize() const;
    const QString& getName()const;
    const QStringList& getNumbers()const;
    static bool isValidName(const QString& );
    static bool isValidNumber(const QString& );
private:
    QString name;
    QStringList numbers;
    bool isValid();
    bool isValidNumbers();

};
std::ostream& operator<<(std::ostream&, const Contact&);
bool operator==(const Contact&, const Contact&);
bool operator<(const Contact&, const Contact&);
#endif // CONTACT_H
