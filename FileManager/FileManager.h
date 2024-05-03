#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include "File/File.h"
#include "ILog/ILog.h"
#include <QSet>

class FileManager : public QObject
{
    Q_OBJECT
private:

    enum State{
        sizeChange,
        thereChanges,
        noChanges,
    };

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
        State update();
    };
private:
    QVector<File> trackFiles;
    ILog *logger;
public:
    FileManager(ILog * log);

    void addFile(QString path);
    void deleteFile(QString path);
    void updateFile();
signals:
    void changes(QString str);
};

#endif // FILEMANAGER_H
