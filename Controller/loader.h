#ifndef LOADER_H
#define LOADER_H

#include <QMap>
#include <QLibrary>

enum MODULE{
    GameHall
};

struct moduleInformation{
    MODULE id;
    const char *name;
};

class Loader
{
public:
    Loader();

    //bool callModuleFunction(MODULE r_module, char *r_functionName);

private:
    QMap<MODULE, QLibrary> m_librarys;
};

#endif // LOADER_H
