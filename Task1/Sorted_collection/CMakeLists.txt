project(Sorted_collection)

set(HEADER_FILES
        SortedList.h
        mathSorting.h
)

set(SOURCE_FILES
        SortedList.cpp
        mathSorting.cpp
)

add_library(Sorted_collection STATIC ${SOURCE_FILES} ${HEADER_FILES})