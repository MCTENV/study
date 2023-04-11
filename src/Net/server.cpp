// DatagramSocket receive example
#include <iostream>

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
int main(int argc, char** argv) {
  Poco::Net::SocketAddress sa(Poco::Net::IPAddress(), 1514);
  Poco::Net::DatagramSocket dgs(sa, false);
  char buffer[1024];
  for (;;) {
    Poco::Net::SocketAddress sender;
    int n = dgs.receiveFrom(buffer, sizeof(buffer) - 1, sender);
    buffer[n] = '\0';
    std::cout << sender.toString() << ": " << buffer << std::endl;
  }
  return 0;
}