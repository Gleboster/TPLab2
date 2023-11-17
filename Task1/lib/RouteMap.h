
#ifndef LAB2_ROUTEMAP_H
#define LAB2_ROUTEMAP_H

#include "Sorted_collection/SortedList.h"
#include "Route.h"

class RouteMap {
    const int needLength = 8;
    Sorting::SortedList<Route*> *base;

public:
    RouteMap();

    void insert(Route *route);

    void operator+(Route *route);

    void removeByNumber(int numberRoute);

    void operator-(int numberRoute);

    void outputRouteBy(string point);

    friend ostream &operator<<(ostream &os, RouteMap &routeMap);
};


#endif //LAB2_ROUTEMAP_H
