
#ifndef LAB2_ROUTE_H
#define LAB2_ROUTE_H


#include <string>
using namespace std;

class Route {
private:
    string start_point;
    string end_point;
    int route_number;

public:
    Route(const string& start, const string& end, int number);

    string getStartPoint();
    string getEndPoint();
    int getRouteNumber() const;

    void setStartPoint(const string& start);
    void setEndPoint(const string& end);
    void setRouteNumber(int number);
};


#endif //LAB2_ROUTE_H
