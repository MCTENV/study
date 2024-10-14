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

    Poco::Net::SocketAddress sa(Poco::Net::AddressFamily::IPv4, "localhost", 8'080);
    sa.family();
    try {
        socket.connect(sa);
    } catch (const Poco::Exception& exc) {
        std::cerr << "Error: " << exc.displayText() << std::endl;
        return 1;
    }

    std::array<char, 1'024> buffer;

    int len = socket.receiveBytes(buffer.data(), buffer.size());

    std::cout << std::string(buffer.data(), len) << std::endl;
    return 0;
}
