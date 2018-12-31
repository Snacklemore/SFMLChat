#include <iostream>
#include <list>
#include <SFML/Network.hpp>
/////////////////////////////////////////////////////////////////
//basic chat with sfml, one socket for server, one socket for client
//threaded sending and receiving,nametag for client, servertag for server
//no reconnecting to server -.-



/////////////////////////////////////////////////////////////////
class Client{
public:
    Client(int nameid,sf::TcpSocket *cSocket){
        nameID = nameid+3*11;
        clientSocket = cSocket;

    }
    int nameID;
    sf::TcpSocket* clientSocket;
};


//const unsigned short PORT = 5000;
//const std::string IPADDRESS("127.0.0.1");//change to suit your needs

std::string msgSend;

sf::TcpSocket socket;
sf::Mutex globalMutex;
bool quit = false;
std::vector<Client> clientList;
std::string* nameTagCopy;
bool ClientBool,ServerBool;
bool isClient()
{
    return ClientBool;
}
bool isServer()
{
    return ServerBool;
}
void DoStuff(void)//needs a clientList+loops to send data to all clients,
{
    static std::string oldMsg;
    while(!quit)
    {
        sf::Packet packetSend;
        globalMutex.lock();
        if (isClient()){

            if(!msgSend.empty())
                msgSend = *nameTagCopy + msgSend;
            packetSend << msgSend;
            msgSend.clear();

        }else
        {
            if(!msgSend.empty())
                msgSend = *nameTagCopy + msgSend;
            packetSend << msgSend;
            msgSend.clear();



        }
        globalMutex.unlock();


        socket.send(packetSend);
        //globalMutex.lock();
       // msgSend.clear();
        //globalMutex.unlock();


        std::string msg;
        sf::Packet packetReceive;
        std::string teststr = *nameTagCopy+"exit";
        socket.receive(packetReceive);
        if ((packetReceive >> msg) && oldMsg != msg && !msg.empty() && (msg != *nameTagCopy+"exit"))
        {
            std::cout << msg << std::endl;
            oldMsg = msg;
        }else if (msg == *nameTagCopy+"exit")
        {
            sf::Packet exitPacket;
            exitPacket << "exit0";
            if (socket.send(exitPacket))
                socket.disconnect();
            std::cout << "Client Disconnected"<< std::endl;
            quit = true;
        }else if(msg == *nameTagCopy+"exit0")
        {

            std::cout << "Server shutdown connection" << std::endl;
            quit = true;
        }
    }
}
std::string* buildNameTag(int num){//1client2server
    if ( num == 1)
    {
        std::cin.clear();
        std::cin.sync();
        const int inputSize = 256;
        char inputBuf[inputSize] ={0};
        char nameBuf[inputSize] ={0};
        std::string* nametag = new std::string(": ");
        std::cout << "Please enter nickname";
        std::cin.getline(nameBuf,inputSize);
        *nametag = (std::string)nameBuf + *nametag;
        std::transform(nametag->begin(),nametag->end(),nametag->begin(), ::tolower);
        std::cout << *nametag << std::endl;
        return  nametag;
    }else if (num == 2)
    {
        std::string* serverstr = new std::string("server: ");
        return serverstr;


    }
    return nullptr;

}
void Server()//needs to be threaded, to listen for all connections
{
    unsigned short PORT;
    std::string porthlp;
    std::cin.clear();
    std::cin.sync();
    std::cout << "\nEnter Port, please";

    getline(std::cin,porthlp);
    PORT = std::stoi(porthlp);
    sf::TcpListener listener;
    listener.listen(PORT);
    listener.accept(socket);
    sf::TcpSocket* sockPtr= &socket;

    std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
    nameTagCopy=buildNameTag(2);
    globalMutex.lock();
    Client curClient(clientList.size(),sockPtr);
    clientList.emplace_back(curClient);
    globalMutex.unlock();
    ServerBool=true;
    ClientBool=false;
}


bool Client()//set name then fork to multiuser
{
    std::string IPADDRESS,porthlp;
    unsigned short PORT;
    std::cin.clear();
    std::cin.sync();
    std::cout << "\nEnter IP, please:";

    getline(std::cin, IPADDRESS);
    std::cout << "\nEnter Port, please";

    getline(std::cin,porthlp);
    PORT = std::stoi(porthlp);
    nameTagCopy=buildNameTag(1);
    ClientBool = true;
    ServerBool = false;
    if(socket.connect(IPADDRESS, PORT) == sf::Socket::Done)
    {
        std::cout << "Connected to " << socket.getRemoteAddress() << std::endl;
        return true;
    }
    return false;

}

void GetInput()
{
    std::string s;
    std::cout << "\nEnter \"exit\" to quit or message to send: ";
    getline(std::cin,s);
   // if(s == "exit")
    //    quit = true;
    globalMutex.lock();
    msgSend = s;
    globalMutex.unlock();
}


int main(int argc, char* argv[])
{
    sf::Thread* thread = 0;

    char who;
    std::cout << "Do you want to be a server (s) or a client (c) ? ";
    std::cin  >> who;

    if (who == 's')
        Server();
    else
        Client();

    thread = new sf::Thread(&DoStuff);
    thread->launch();
    globalMutex.lock();
    std::cout << clientList.size()<< std::endl;
    globalMutex.unlock();
    while(!quit)
    {
        GetInput();
    }

    if(thread)
    {
        thread->wait();
        delete thread;
    }
    return 0;
}