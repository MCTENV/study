/**
 * @file poco-server.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2024-06-21
 */
#include <Poco/Exception.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Util/ServerApplication.h>

#include <iostream>
#include <string>
#include <vector>

class MyConnection : public Poco::Net::TCPServerConnection
{
public:
    MyConnection(const Poco::Net::StreamSocket& socket)
        : Poco::Net::TCPServerConnection(socket)
    {}

    void run() override
    {
        try
        {
            std::string data = "hello world";

            Poco::Net::StreamSocket socket = this->socket();

            socket.sendBytes(data.data(), static_cast<int>(data.size()));

            socket.close();
        }
        catch (const Poco::Exception& exc)
        {
            std::cerr << "Error: " << exc.displayText() << std::endl;
        }
    }
};

class MyConnectionFactory : public Poco::Net::TCPServerConnectionFactory
{
public:
    Poco::Net::TCPServerConnection* createConnection(
        const Poco::Net::StreamSocket& socket) override
    {
        return new MyConnection(socket);
    }
};

class MyServer : public Poco::Util::ServerApplication
{
public:
    int main(const std::vector<std::string>&) override
    {
        Poco::Net::ServerSocket svs(8'080);
        Poco::Net::TCPServer    server(new MyConnectionFactory, svs);
        server.start();
        waitForTerminationRequest();
        server.stop();
        return 0;
    }
};

int main()
{
    MyServer server;
    server.main({});
    return 0;
}
