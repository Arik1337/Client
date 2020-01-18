//
// Created by arik on 13.1.2020.
//

#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <string>
#include <queue>
#include "connectionHandler.h"
#include "BlockingQueue.h"
#include "Transmitter.h"
#include <thread>
class Client {
public:
    Client();
    virtual ~Client();
    Client(const Client &aClient);
private:
    void start();
    void readNextLine();
    ConnectionHandler *handler;
    bool connectedSocket;
    std::string processUserCommand(std::string &userCommand);
    Transmitter transmitter;
    ClientProtocol protocol;
    std::string* name;
    bool inputRec;
    std::string processLoginCommand(std::vector<std::string> &command);
    std::string processJoinCommand(std::vector<std::string> &command);
    std::string processExitCommand(std::vector<std::string> &command);
    std::string processAddCommand(std::vector<std::string> &command);
    std::string processBorrowCommand(std::vector<std::string> &command);
    std::string processLogoutCommand();
    std::string processStatusCommand(std::vector<std::string> &command);
    std::string processReturnCommand(std::vector<std::string> &command);
};
#endif //CLIENT_CLIENT_H
