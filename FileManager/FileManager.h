#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include "File/File.h"
#include "ILog/ILog.h"

class FileManager : public QObject
{
private:
    QVector<File*> trackFiles;
    ILog *logger;
public:
    FileManager(ILog * log);
    ~FileManager();

    void addFile(QString path);
    void deleteFile(QString path);
    void updateFile();
};

#endif // FILEMANAGER_H
