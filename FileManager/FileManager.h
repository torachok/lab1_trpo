#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include "ILog/ILog.h"
#include <QFileInfo>

class FileManager : public QObject
{
    Q_OBJECT
private:
    class File
    {
    private:
        bool isThere;
        int size;
        QString path;
    public:
        File(QString path);
        int getSize();
        QString getPath();
        bool getIsThere();
        bool update();
        QString getInfo();
    };
private:
    QVector<File> trackFiles;
    ILog *logger;
public:
    void addFile(QString path);
    void deleteFile(QString path);
    void updateFile();

    static FileManager& Instance(ILog* log){
        static FileManager fn(log);
        return fn;
    }

private:
    FileManager(ILog* log);
    FileManager(FileManager&);
    FileManager&operator=(FileManager&);
    ~FileManager(){}
signals:
    void changes(QString str);
};

#endif // FILEMANAGER_H
