#ifndef __UTILS__
#define __UTILS__

#ifndef PI
    #define PI 3.14159265358979323846
#endif

#include <math.h>
#include <stdio.h>
#include <string.h>

#define GLEW_STATIC

#include <stdio.h>
#include <map>

#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Vector : public sf::Vector3f
{
    public:
        Vector();
        Vector(const Vector &v);
        Vector(double _x, double _y, double _z);

        double Length() const;
        Vector Normalize();

        double operator[](unsigned int index) const;

        bool operator==(const Vector &v);

        void operator=(const Vector &v);

        void operator+=(const Vector &v);
        void operator+=(double s);

        void operator-=(const Vector &v);
        void operator-=(double s);

        void operator*=(double s);

        void operator/=(double s);

        Vector operator+(const Vector &v);

        Vector operator-(const Vector &v);

        double operator*(const Vector &v);
        Vector operator*(double s);

        Vector operator/(double s);

        Vector DotProduct(const Vector &v);
        Vector Rotate(Vector axis, double Angle);
};

double Degree(double radians);
double Radians(double degrees);
double NumBounds(double value);

std::string IntToStr(int val);
std::string FloatToStr(float val);

sf::Vector3f ScreenToSpace(sf::Vector2i pos);
sf::Vector3f ScreenToSpace(int x, int y);

#endif
