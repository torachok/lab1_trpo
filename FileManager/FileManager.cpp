#include "FileManager.h"

FileManager::FileManager(ILog *log) {
    logger = log;
    if(logger) connect(this, &FileManager::changes, logger, &ILog::log);
    else qWarning("Logger is not initialized!");
}

void FileManager::addFile(QString path)
{
    File temp = File(path);
    trackFiles.push_back(temp);
}

void FileManager::updateFile()
{
    for(File& file:trackFiles){
        State fileState = file.update();
        if(fileState == thereChanges){
            if(file.getIsThere()) emit  changes(file.getPath() + " created");
            else emit changes(file.getPath() + " deleted");
        }
        else if(fileState == sizeChange) {
            QString temp;
            temp.setNum(file.getSize());
            emit changes(file.getPath() + " new size: " + temp + " bytes");
        }
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

FileManager::State FileManager::File::update(){
    QFileInfo q(path);

    int prevSize = size;
    int prevThere = isThere;

    size = (int)q.size();
    isThere = q.exists();

    if(prevThere != isThere) return thereChanges;
    else if(prevSize != size)return sizeChange;
    else return noChanges;
}
