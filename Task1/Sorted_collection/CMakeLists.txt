project(Sorted_collection)

set(HEADER_FILES
        SortedList.h
        Order.h
        Comparer.h
)

set(SOURCE_FILES
        SortedList.cpp
)

add_library(Sorted_collection STATIC ${SOURCE_FILES} ${HEADER_FILES})