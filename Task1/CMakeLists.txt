project(Task1)

set(HEADER_FILES
        lib/Route.h
        lib/RouteMap.cpp
)

set(SOURCE_FILES
        lib/Route.cpp
        lib/RouteMap.h
)
add_library(Task1 STATIC ${SOURCE_FILES} ${HEADER_FILES})

include_directories(Sorted_collection)
add_subdirectory(Sorted_collection)

target_link_libraries(Task1 Sorted_collection)