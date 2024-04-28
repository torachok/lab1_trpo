#ifndef ILOG_H
#define ILOG_H

#include <QObject>
#include <QTextStream>

class ILog:public QObject
{
    Q_OBJECT
public slots:
    virtual void log(QString str) = 0;
};

class ConsoleWriter : public ILog{
    Q_OBJECT
public slots:
    void log(QString str) override;
};

#endif // ILOG_H
