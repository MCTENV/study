// DatagramSocket send example
#include "Poco/DateTimeFormatter.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Timestamp.h"
int main(int argc, char** argv) {
  Poco::Net::SocketAddress sa("localhost", 1514);
  Poco::Net::DatagramSocket dgs;
  dgs.connect(sa);
  Poco::Timestamp now;
  std::string msg =
      Poco::DateTimeFormatter::format(now, "<14>%w %f %H:%M:%S Hello, world!");
  dgs.sendBytes(msg.data(), msg.size());
  return 0;
}