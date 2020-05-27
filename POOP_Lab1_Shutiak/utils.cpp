#include "utils.h"
#include "Phonebook.h"
#include <QStringList>
#include <iostream>
#include <string>

int chooseAction(){
    int i;
    std::cin>>i;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
        return 0;
    }else{
        return i;
    }
}
void showMainMenu(){
    std::cout<<"To choose action press a button: "<<std::endl;
    std::cout<<"0 Exit"<<std::endl;
    std::cout<<"1 Show phonebook"<<std::endl;
    std::cout<<"2 Add contact"<<std::endl;
    std::cout<<"3 Add number to existing contact"<<std::endl;
    std::cout<<"4 Search by name"<<std::endl;
    std::cout<<"5 Search by number"<<std::endl;
    std::cout<<"6 Edit name"<<std::endl;
    std::cout<<"7 Edit number"<<std::endl;
    std::cout<<"8 Delete a number from contact"<<std::endl;
    std::cout<<"9 Delete contact"<<std::endl;
    std::cout<<"Choose action: ";
 }
const QString chooseOneName(const Phonebook& pb){
     std::string n;
     QVector<Contact> res;
     int i;
     int choice;
    do{

        std::cout<<"Enter name until you choose only one result, to exit enter 0: ";
        std::cin>>n;
        if(n=="0")
         return "0";
        res =pb.searchByName(QString::fromStdString(n));
        for(i=0;i<res.size();i++){
            std::cout<<(i+1)<<". "<<res.at(i)<<std::endl;
        }
        if(res.size()==1)
            return res.at(0).getName();
        std::cout<<"Change name - enter 0, choose from list - enter number: ";
        choice = chooseAction();
        while(choice>i||choice<0){
                std::cout<<"you enter wrong number"<<std::endl;
                std::cout<<"Change number - enter 0, choose from list - enter name: ";
                choice = chooseAction();
        }
        if(choice!=0){
            return res[choice-1].getName();
        }
     }
    while(true);
    return "0";
}
const QString chooseOneNumber(const Phonebook& pb){
    std::string n;
    QVector<Contact> res;
    QString s;
    int k;
    QStringList finded;
    int choice;
   do{
       std::cout<<"Enter number until you choose only one result, to exit enter 0: ";
       std::cin>>n;
       res =pb.searchByNumber(QString::fromStdString(n));
       k=0;
       for(int i=0;i<res.size();++i){
           std::cout<<res.at(i).getName().toStdString()<<std::endl;
           for(int j=0;j<res[i].numbersSize();++j){
               if(res[i].getNumbers()[j].contains(QString::fromStdString(n))){
                   k++;
                   finded<<res[i].getNumbers()[j];
                   std::cout<<k<<". "<<res[i].getNumbers()[j].toStdString()<<std::endl;
                   s=res[i].getNumbers()[j];
               }
           }
       }
       std::cout<<"Change number - enter 0, choose from list - enter number: ";
      choice = chooseAction();
       while(choice>k||choice<0){
               std::cout<<"you enter wrong number"<<std::endl;
               std::cout<<"Change number - enter 0, choose from list - enter number: ";
               choice = chooseAction();
       }
       if(choice!=0){
           return finded[choice-1];
       }
    }while(n!="0");
   if(n=="0")
    return "0";
   return s;

}
