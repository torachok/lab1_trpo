#include <QCoreApplication>
#include "ILOG/ILog.h"
#include <File/File.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    File temp("test.txt");
    ILog* logger = new ConsoleWriter();
    logger->log(temp.getPath());

    return a.exec();
}
