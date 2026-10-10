cmake_minimum_required(VERSION 3.12)
project(encryption_aes LANGUAGES CXX)

find_package(OpenSSL REQUIRED)

add_executable(
   ${PROJECT_NAME}
      main.cpp
)

target_link_libraries(
   ${PROJECT_NAME}
   PRIVATE
      OpenSSL::Crypto
      OpenSSL::SSL
)

set_target_properties(
   ${PROJECT_NAME} 
   PROPERTIES
      CXX_STANDARD 17
      CXX_STANDARD_REQUIRED YES
      CXX_EXTENSIONS NO
)
