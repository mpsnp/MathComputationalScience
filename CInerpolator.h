//
// Created by mpsnp on 29.05.16.
//

#ifndef COMPUTATIONALSCIENCE_CBASICINERPOLATOR_H
#define COMPUTATIONALSCIENCE_CBASICINERPOLATOR_H

#include <vector>

struct Point {
    double x;
    double y;

    Point(double ax, double ay) : x(ax), y(ay) { }
};

typedef std::vector<Point> PointVector;

class CInerpolator {
public:
    virtual void Interpolate(PointVector &input) = 0;

    virtual Point CalculateValue(double x) = 0;

    virtual PointVector CalculateValues(double x0, double xn, double step) = 0;
};

#endif //COMPUTATIONALSCIENCE_CBASICINERPOLATOR_H
