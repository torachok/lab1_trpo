#include <QCoreApplication>
#include "ILog/ILog.h"
#include <File/File.h>
#include "FileManager/FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    File temp("test.txt");
    ILog* logger = new ConsoleWriter();
    FileManager fileManager(logger);
    fileManager.addFile("C:\\Users\\User\\Documents\\qtcreator_projects\\lab_1\\lab1_trpo\\test.txt");

    while (true){
        fileManager.updateFile();
    }

    return a.exec();
}
