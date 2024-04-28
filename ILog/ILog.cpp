#include "ILog.h"


void ConsoleWriter::log(QString str)
{
    QTextStream cout(stdout);
    cout<<str<<Qt::endl;
}
