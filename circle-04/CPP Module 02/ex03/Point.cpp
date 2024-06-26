// Copyright @bigpel66

#include "Point.hpp"

const Fixed& Point::getX(void) const {
  return _x;
}

const Fixed& Point::getY(void) const {
  return _y;
}

Point& Point::operator=(const Point& p) {
  if (this != &p) {
    const_cast<Fixed&>(_x) = p.getX();
    const_cast<Fixed&>(_y) = p.getY();
  }
  return *this;
}

Point::Point(void)
  : _x(0), _y(0) {}

Point::Point(const float x, const float y)
  : _x(x), _y(y) {}

Point::Point(const Point& p)
  : _x(p.getX()), _y(p.getY()) {}

Point::~Point(void) {}

std::ostream& operator<<(std::ostream& o, const Point& p) {
  return o << "( " << p.getX().toFloat() << ", " << p.getY().toFloat() << " )";
}
