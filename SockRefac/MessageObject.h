//
// Created by Chapo on 06.01.2019.
//

#ifndef SOCKREFAC_MESSAGEOBJECT_H
#define SOCKREFAC_MESSAGEOBJECT_H
class ClientObject;

#include <string>

class MessageObject{
public:
    MessageObject(std::string data)
    {
        msgData = data;
    }
    std::string Room;
    ClientObject *CObject= nullptr;
    std::string getMsgData(){
        return msgData;
    }
    void setMsgData(std::string val){
        msgData = val;
    }
    void setSender(std::string val)
    {
        sender = val;
    }
private:
    std::string msgData;
    std::string sender;
};
#endif //SOCKREFAC_MESSAGEOBJECT_H
