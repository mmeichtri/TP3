#ifndef LOGFILE_H_INCLUDED
#define LOGFILE_H_INCLUDED
#include <string>
#include "personaje.h"
class LogFile{
private:

public:

    /*
    pre:
    post:
    */
    LogFile();

    /*
    pre:
    post: actualiza el log, agregando un nuevo movimento
    */
    void actualizarLog(Personaje* );
};

#endif // LOGFILE_H_INCLUDED
