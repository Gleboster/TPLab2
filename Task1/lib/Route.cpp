
#include "Route.h"

Route::Route(const string &start, const string &end, int number) {
    start_point = start;
    end_point = end;
    route_number = number;
}

Route::Route() : Route("", "", -1) {
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

istream &operator>>(istream &is, Route &route) {
    is >> route.start_point >> route.end_point >> route.route_number;
    return is;
}

ostream &operator<<(ostream &os, Route &route) {
    os << "Route number is " << route.route_number << endl;
    os << "\t Start point: " << route.start_point << endl;
    os << "\t Etart point: " << route.end_point << endl;
    return os;
}

bool Route::operator<(Route &other) {
    return this->route_number < other.route_number;
}
