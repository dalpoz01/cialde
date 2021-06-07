#ifndef XMLMANAGEMENT_H
#define XMLMANAGEMENT_H

#include<QFile>
#include<QXmlStreamReader>
#include<QXmlStreamWriter>
#include<QMessageBox>
#include<QDir>
#include<QSaveFile>
#include<QIODevice>
#include <QtXml>

#include <sstream>

#include "container.h"
#include "deepptr.h"
#include "wafflebox.h"
#include "circlebox.h"
#include "conebox.h"
#include "ventagliobox.h"
#include "cannolobox.h"
#include "covered.h"
#include "branded.h"

class XmlManagement {
private:
    std::string path;
    std::string fileName;

    static std::string DoubleToString(double);
    static std::string UIntToString(unsigned int);
public:
    XmlManagement(const std::string& = "../cialde/Data/Xml/", const std::string& = "products.xml");

    //Metodo per leggere Xml
    Container<DeepPtr<WaffleBox>> read() const;
    //Metodo per scrivere xml
    void write(const Container<DeepPtr<WaffleBox>>&) const;

    std::string getXmlPath() const;
    std::string getXmlFileName() const;
};

#endif // XMLMANAGEMENT_H
