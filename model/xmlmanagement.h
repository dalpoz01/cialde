#ifndef XMLMANAGEMENT_H
#define XMLMANAGEMENT_H

#include<QFile>
#include<QXmlStreamReader>
#include <QMessageBox>

#include <iostream>
#include <string>
#include <sstream>

#include<string>
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
public:
    XmlManagement(const std::string&, const std::string&);
    //Metodo per leggere Xml
    Container<DeepPtr<WaffleBox>> read() const;
};

#endif // XMLMANAGEMENT_H
