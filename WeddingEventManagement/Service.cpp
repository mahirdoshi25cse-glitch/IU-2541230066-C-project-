#include "Service.h"
#include <iostream>
using namespace std;

Service::Service()
{
    serviceId = 0;
    serviceName = "";
    cost = 0;
}

Service::Service(int id, string name, double c)
{
    serviceId = id;
    serviceName = name;
    cost = c;
}

void Service::display()
{
    cout << "Service ID: " << serviceId << endl;
    cout << "Service Name: " << serviceName << endl;
    cout << "Cost: " << cost << endl;
}

int Service::getServiceId()
{
    return serviceId;
}

string Service::getServiceName()
{
    return serviceName;
}

double Service::getCost()
{
    return cost;
}

void Service::setServiceName(string name)
{
    serviceName = name;
}

void Service::setCost(double c)
{
    cost = c;
}