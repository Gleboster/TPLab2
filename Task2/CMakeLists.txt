project(Task2)

set(HEADER_FILES
        Function.h
)

set(SOURCE_FILES
        Function.cpp
)
add_library(Task2 STATIC ${SOURCE_FILES} ${HEADER_FILES})

