cmake_minimum_required(VERSION 3.5)
project(MyList)
set(SOURCES
    main.cpp
    
)
set(HEADERS
    Headers/MyList.h
)
add_executable(MyList ${SOURCES} ${HEADERS})
set_target_properties(
    MyList PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQURIED ON
)