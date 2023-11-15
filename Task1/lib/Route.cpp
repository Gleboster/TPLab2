
#include "Route.h"

Route::Route(const string &start, const string &end, int number) {
    start_point = start;
    end_point = end;
    route_number = number;
}

string Route::getStartPoint() {
    return start_point;
}

string Route::getEndPoint() {
    return end_point;
}

int Route::getRouteNumber() const {
    return route_number;
}

void Route::setStartPoint(const string &start) {
    start_point = start;
}

void Route::setEndPoint(const string &end) {
    end_point = end;
}

void Route::setRouteNumber(int number) {
    route_number = number;
}
