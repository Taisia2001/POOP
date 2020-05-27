#ifndef UTILS_H
#define UTILS_H
class QString;
class Phonebook;
int chooseAction();
void showMainMenu();
const QString chooseOneName(const Phonebook& pb);
const QString chooseOneNumber(const Phonebook& pb);

#endif // UTILS_H
