#include "FileManager.h"

FileManager::FileManager(ILog *log) {
    logger = log;
    if(logger) connect(this, &FileManager::changes, logger, &ILog::log);
    else qWarning("Logger is not initialized!");
}

void FileManager::addFile(QString path)
{
    for(int i = 0; i < trackFiles.size(); i++){
        if(trackFiles[i].getPath() == path){
            if(logger)
                logger->log(path + " already exists");
            else
                qWarning("Logger is not initilized");
            return;
        }
    }
    File temp = File(path);
    trackFiles.push_back(temp);
}

void FileManager::updateFile()
{
    for(File& file:trackFiles){
        bool fileState = file.update();
        if(fileState) emit changes(file.getInfo());
    }
}

FileManager::File::File(QString path)
{
    this->path = path; //инициализация поля path
    QFileInfo q(path);
    size = (int)q.size(); //инициализация поля size
    isThere = q.exists(); //инициализация поля isThere
}

int FileManager::File::getSize()
{
    return size;
}

QString FileManager::File::getPath()
{
    return path;
}

bool FileManager::File::getIsThere()
{
    return isThere;
}

bool FileManager::File::update(){
    QFileInfo q(path);

    int prevSize = size;
    int prevThere = isThere;

    size = (int)q.size();
    isThere = q.exists();

    if(prevThere != isThere || prevSize != size) return true;
    else return false;
}

QString FileManager::File::getInfo()
{
    QString info = "";
    if(!isThere){
        info = path + " not exists";
    }
    else{
        QString strSize;
        strSize.setNum(size);
        info = path + " exists, size: " + strSize + " bytes";
    }
    return info;
}
