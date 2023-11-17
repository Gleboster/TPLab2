
#include "RouteMap.h"

RouteMap::RouteMap() {
    std::cout << "Input " << needLength << " routes";

    Route **routes = new Route *[needLength];

    std::cout << "Input route: Start point, End point, Number route (Start/End points without space)" << endl;
    for (int i = 0; i < needLength; ++i) {
        int numberRoute;
        string startPoint, endPoint;
        std::cout << "Input number of route: ";
        std::cin >> numberRoute;
        std::cout << "Input start point of route: ";
        std::cin >> startPoint;
        std::cout << "Input end point of route: ";
        std::cin >> endPoint;

        routes[i] = new Route(startPoint, endPoint, numberRoute);
    }


    base = new Sorting::SortedList<Route *>(routes,
                                            needLength,
                                            new function<bool(Route *, Route *)>
                                                    (
                                                            [](Route* a, Route* b) {
                                                                return a->getRouteNumber() <= b->getRouteNumber();
                                                            }
                                                    ));
    delete[] routes;
}

void RouteMap::insert(Route *route) {
    base->insert(route);
}

void RouteMap::operator+(Route *route) {
    insert(route);
}

void RouteMap::removeByNumber(int numberRoute) {
    int i = 0;
    for (Route *route: *base) {
        if (route->getRouteNumber() == numberRoute)
            base->remove(i);
        i++;
    }
}

void RouteMap::operator-(int numberRoute) {
    removeByNumber(numberRoute);
}

void RouteMap::outputRouteBy(string point) {
    bool notFound = true;

    for (Route *route: *base) {
        if (route->getStartPoint() == point || route->getEndPoint() == point) {
            std::cout << *route;
            notFound = false;
        }
    }

    if (notFound)
        std::cout << "\033[31m" << "No routes found with this terminus" << "\033[0m" << endl;
}

ostream &operator<<(ostream &os, RouteMap &routeMap) {
    for (Route *route: *routeMap.base)
        std::cout << *route << "------------------" << endl;
    return os;
}
