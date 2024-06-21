/**
 * @file poco-client.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2024-06-21
 */

#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>

#include <array>
#include <iostream>

int main(int argc, char** argv)
{
    Poco::Net::StreamSocket socket;

    Poco::Net::SocketAddress sa("localhost", 8'080);
    socket.connect(sa);

    std::array<char, 1'024> buffer;

    int len = socket.receiveBytes(buffer.data(), buffer.size());

    std::cout << std::string(buffer.data(), len) << std::endl;
    return 0;
}
