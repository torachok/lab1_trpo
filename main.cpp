#include <QCoreApplication>
#include "ILog/ILog.h"
#include <File/File.h>
#include "FileManager/FileManager.h"
#include <thread>

QVector<QString> inputFilePath(ILog* logger){
    QTextStream cin(stdin);
    if(logger){
        int fileAmount;
        logger->log("Enter amount of files: ");
        cin >> fileAmount;

        QVector<QString> pathes;
        for(int i = 0; i< fileAmount;i++){
            QString filePath;
            cin>>filePath;
            pathes.push_back(filePath);
        }
        return pathes;
    }
    else{
        qWarning("inputFilePath method: Logger was not initialized.");
        return QVector<QString>();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    File temp("test.txt");
    ILog* logger = new ConsoleWriter();
    FileManager fileManager(logger);
    //fileManager.addFile("C:\\Users\\User\\Documents\\qtcreator_projects\\lab_1\\lab1_trpo\\test.txt");

    QVector<QString> pathes = inputFilePath(logger);
    for(QString & path : pathes) fileManager.addFile(path);

    while (true){
        fileManager.updateFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return a.exec();
}
