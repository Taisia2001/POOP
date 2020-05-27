#include <QCoreApplication>
#include "Contact.h"
#include "Phonebook.h"
#include "utils.h"
#include <QStringList>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int action=-1;
    Phonebook pb;
    while(action != 0){
        showMainMenu();
        action = chooseAction();
        pb.sortContacts();
        switch (action) {
        case 0:{
            std::cout<<"Goodbye!"<<std::endl;
            break;
        }
        case 1:
            foreach(Contact c,pb.getContacts())
                std::cout<<c<<std::endl;
            break;
        case 2:{
            Contact c;
            std::cout<<"Enter name: ";
            std::string n;
            std::cin>>n;
            while(!Contact::isValidName(QString::fromStdString(n))||pb.isNameExist(QString::fromStdString(n))){
                  std::cout<<"Whitespaces can`t be a name, you can`t create contacts with identical name, enter name: ";
                  std::cin>>n;
            }
            c.setName(QString::fromStdString(n));
            int addNumber=0;
            do{
                  std::cout<<"Enter number: ";
                  std::cin>>n;
                  while(true){
                        if(Contact::isValidNumber(QString::fromStdString(n))&&!pb.isNumberExist(QString::fromStdString(n))){
                                if(c.addNumber(QString::fromStdString(n)))
                                        break;
                         }
                        std::cout<<"Number can contain + and from 3 to 15 digits, can`t be identical numbers, enter number, to exit enter 0: ";
                        std::cin>>n;
                        if(n=="0"){
                            if(c.numbersSize()==0)
                                std::cout<<"you have to add at least one number"<<std::endl;
                            else
                                break;
                        }
                  }
                  if(n=="0"){
                      break;
                  }
                  std::cout<<"exit - 0, add number - another digit: ";
                  addNumber= chooseAction();
            }while(addNumber);
            pb.addContact(c);
            break;
            }
        case 3:{
            const QString s = chooseOneName(pb);
            if(s!="0"){
                std::string n;
                int addNumber=0;
                do{
                      std::cout<<"Enter number: ";
                      std::cin>>n;
                      while(!pb.addNumber(s,QString::fromStdString(n))){
                            std::cout<<"Number can contain + and from 3 to 15 digits, can`t be identical numbers, enter number, to exit enter 0: ";
                            std::cin>>n;
                            if(n=="0")
                                break;
                      }
                      if(n=="0")
                          break;
                      std::cout<<"exit - 0, add number - another digit: ";
                      addNumber= chooseAction();
                }while(addNumber);
                std::cout<<pb.getContactByName(s)<<std::endl;
            }else{
                 std::cout<<"you don`t choose any contact!";
            }
            break;
        }
        case 4:{
            std::cout<<"Enter name for searching contacts: ";
            std::string n;
            std::cin>>n;
            QVector<Contact> res(pb.searchByName(QString::fromStdString(n)));
            if(res.size()==0)
                std::cout<<"There are no names which contain "+n<<std::endl;
            else
                foreach(Contact c, res)
                    std::cout<<c<<std::endl;
            break;
        }
        case 5:{
            std::cout<<"Enter number for searching contacts: ";
            std::string n;
            std::cin>>n;
            QVector<Contact> res(pb.searchByNumber(QString::fromStdString(n)));
            if(res.size()==0)
                std::cout<<"There are no numbers which contain "+n<<std::endl;
            else
                foreach(Contact c, res)
                    std::cout<<c<<std::endl;
            break;
        }
            //edit name
        case 6:{
            const QString s = chooseOneName(pb);
            if(s!="0"){
                std::string n;
                std::cout<<"Enter name, to exit enter 0: ";
                std::cin>>n;
                if(n!="0"){
                     if(pb.editName(s,QString::fromStdString(n)))
                          std::cout<<pb.getContactByName(QString::fromStdString(n))<<std::endl;
                     else
                         std::cout<<"you can`t change name to "+n+", maybe this name has already exist"<<std::endl;
                }

            }else{
                 std::cout<<"you don`t choose any contact!";
            }
            break;
        }
            //edit number
        case 7:{
            const QString s = chooseOneNumber(pb);
            if(s!="0"){
                std::string n;
                while(true){
                std::cout<<"Number can contain + and from 3 to 15 digits, can`t be identical numbers";
                std::cout<<"Enter new number, to exit enter 0:";
                std::cin>>n;
                if(n!="0"){
                     if(pb.editNumber(s,QString::fromStdString(n))){
                          std::cout<<pb.getContactByNumber(QString::fromStdString(n))<<std::endl;
                          break;
                     }else
                         std::cout<<"you can`t change number to "+n+", maybe it has already exist"<<std::endl;
                }else{
                    break;
                }

            }
            }else{
                 std::cout<<"you don`t choose any contact!";
            }
            break;
        }
            //del number
        case 8:{
            const QString s = chooseOneNumber(pb);
            if(s!="0"){
                std::string n;
                std::cout<<"to exit enter 0, to delete number enter another digit: ";
                std::cin>>n;
                if(n!="0"){
                     if(pb.deleteNumber(s))
                          std::cout<<"Number deleted"<<std::endl;
                     else
                         std::cout<<"oops, soething was wrong, check phonebook and try again"<<std::endl;
                }
            }else{
                 std::cout<<"you don`t choose any contact!";
            }
            break;
        }
            //del contact
        case 9:{
            const QString s = chooseOneName(pb);
            if(s!="0"){
                std::string n;
                std::cout<<"to exit enter 0, to delete enter any digit: ";
                std::cin>>n;
                if(n!="0"){
                     if(pb.deleteContactByName(s))
                          std::cout<<"contact deleted"<<std::endl;
                     else
                         std::cout<<"oops, soething was wrong, check phonebook and try again"<<std::endl;
                }
            }else{
                 std::cout<<"you don`t choose any contact!";
            }
            break;
        }
        default:
            std::cout<<"You entered incorrect action, try again"<<std::endl;
        }
        std::cout<<std::endl;
    }

    return a.exec();
}


