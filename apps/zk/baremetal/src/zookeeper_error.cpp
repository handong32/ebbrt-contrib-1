#include "zookeeper_error.hpp"
#include <cstring>
#include <zookeeper.h>

namespace zookeeper {

ZooException::ZooException(int code)
: std::runtime_error(zerror(code)), zoo_error_code_(code) {
}

ZooException::ZooException(int code, const char* what)
: std::runtime_error(what), zoo_error_code_(code) {
}

ZooException ZooSystemErrorFromErrno(int ec) {
  return ZooException(ZSYSTEMERROR, strerror(ec));
}

}
