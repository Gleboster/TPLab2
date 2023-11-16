
#ifndef LAB2_ROUTE_H
#define LAB2_ROUTE_H


#include <string>
#include <iostream>

using namespace std;

class Route {
private:
    string start_point;
    string end_point;
    int route_number;

public:

    Route();

    Route(const string &start, const string &end, int number);

    string getStartPoint();

    string getEndPoint();

    int getRouteNumber() const;

    void setStartPoint(const string &start);

    void setEndPoint(const string &end);

    void setRouteNumber(int number);

    bool operator<(Route& other);

    friend istream &operator>>(istream &is, Route &route);
    friend ostream &operator<<(ostream &os, Route &route);
};


#endif //LAB2_ROUTE_H
