#include "Task1/lib/RouteMap.h"

void pause() {
    system("pause");
}

void clear() {
    system("cls");
}

int menuTask() {
    std::cout << "Choose action Task:" << endl;
    std::cout << "\t 1. Task1" << endl;
    std::cout << "\t 2. Task2" << endl;

    int choice = 0;
    std::cout << "Your Choice: ";
    std::cin >> choice;
    return choice;
}

namespace Task1 {
    RouteMap *routeMap;

    void printRouteMap() {
        std::cout << *routeMap;
    }

    void printRouteMapWithTerminus() {
        string terminus;
        std::cout << "Input terminus: ";
        std::cin >> terminus;
        routeMap->outputRouteBy(terminus);
    }

    void AddRoute() {
        int numberRoute;
        string startPoint, endPoint;
        std::cout << "Input number of route: ";
        std::cin >> numberRoute;
        std::cout << "Input start point of route: ";
        std::cin >> startPoint;
        std::cout << "Input end point of route: ";
        std::cin >> endPoint;

        routeMap->insert(new Route(startPoint, endPoint, numberRoute));
        std::cout << "Route successfully append";
    }

    void RemoveRoute() {
        int numberRoute;
        std::cout << "Input number of route: ";
        std::cin >> numberRoute;

        routeMap->removeByNumber(numberRoute);
        std::cout << "Route successfully removed";
    }

    int muneTask1() {
        std::cout << "Choose Task:" << endl;
        std::cout << "\t 1. Print all routes" << endl;
        std::cout << "\t 2. Find rotes with need terminus" << endl;
        std::cout << "\t 3. Add new route" << endl;
        std::cout << "\t 4. Remove route by number" << endl;

        int choice = 0;
        std::cout << "Your choice: ";
        std::cin >> choice;
        return choice;
    }

    void startTask1() {
        routeMap = new RouteMap();

        while (true) {
            clear();
            int choice = muneTask1();
            switch (choice) {
                case 1:
                    printRouteMap();
                    break;
                case 2:
                    printRouteMapWithTerminus();
                    break;
                case 3:
                    AddRoute();
                    break;
                case 4:
                    RemoveRoute();
                    break;
                default:
                    std::cout << "Task1 finished" << std::endl;
                    return;
            }
            pause();
        }

    };
}

namespace Task2 {
    void startTask2() {

    };
}

int main() {

    while (true) {
        clear();
        int choiseTask = menuTask();
        switch (choiseTask) {
            case 1:
                Task1::startTask1();
                break;
            case 2:
                Task2::startTask2();
                break;
            default:
                return 0;
        }
        pause();
    }
}
