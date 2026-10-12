#ifndef SERVICE_H
#define SERVICE_H

#include <string>
using namespace std;

class Service
{
private:
    int serviceId;
    string serviceName;
    double cost;

public:
    Service();
    Service(int id, string name, double c);

    void display();

    int getServiceId();
    string getServiceName();
    double getCost();

    void setServiceName(string name);
    void setCost(double c);
};

#endif