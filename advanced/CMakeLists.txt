cmake_minimum_required(VERSION 3.22)
project(advanced)

set(CMAKE_CXX_STANDARD 20)

add_executable(advanced main.cpp template.h TemplateClass.h TemplateInherent.h splitfile.cpp splitfile.h FriendTemplate.h CommonArray.h)
