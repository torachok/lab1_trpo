#ifndef FILE_H
#define FILE_H
#include <QObject>
#include <QString>
#include <QFileInfo>

class File : QObject
{
    Q_OBJECT
private:
    bool isThere;
    int size;
    QString path;
public:
    File(QString path);
    int getSize();
    QString getPath();
    bool getIsThere();
    void update();
signals:
    void changes();
};

#endif // FILE_H
