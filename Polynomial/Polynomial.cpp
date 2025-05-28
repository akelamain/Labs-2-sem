#include "Polynomial.hpp"
#include "../Term/Term.hpp"

#include <algorithm>
#include <cstring>
#include <sstream>
void Polynomial::sort(bool increase) {
  order_ = increase;
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if ((increase && poly[j].exponent > poly[j + 1].exponent) ||
          (!increase && poly[j].exponent < poly[j + 1].exponent)) {
        std::swap(poly[j], poly[j + 1]);
      }
    }
  }
}

Polynomial::Polynomial() : poly(nullptr), degree(), size(0), order_(true) {}

Polynomial::Polynomial(int p) : degree(0), size(1), order_(true) {
  poly = new Term[1];
  poly[0] = Term(p, 0);
}

Polynomial::Polynomial(const Term &t)
    : degree(t.exponent), size(1), order_(true) {
  poly = new Term[1];
  poly[0] = t;
}

Polynomial::Polynomial(const Polynomial &p) {
  degree = p.degree;
  size = p.size;
  order_ = p.order_;

  poly = new Term[size];

  for (int i = 0; i < size; ++i) {
    poly[i] = p.poly[i];
  }
}

Polynomial::~Polynomial() { delete[] poly; }

Polynomial &Polynomial::operator=(const Polynomial &p) {
  if (this == &p)
    return *this;

  delete[] poly;
  size = p.size;
  degree = p.degree;
  poly = new Term[size];
  for (int i = 0; i < size; i++) {
    poly[i] = p.poly[i];
  }
  return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &p) {
  for (int i = 0; i < p.size; ++i) {
    bool found = false;
    for (int j = 0; j < size; ++j) {
      if (poly[j].exponent == p.poly[i].exponent) {
        poly[j] = poly[j] + p.poly[i];
        found = true;
        break;
      }
    }

    if (!found) {
      Term *newPoly = new Term[size + 1];
      for (int j = 0; j < size; ++j) {
        newPoly[j] = poly[j];
      }
      newPoly[size] = p.poly[i];

      delete[] poly;
      poly = newPoly;
      ++size;
    }
  }

  for (int i = 0; i < size; ++i) {
    if (poly[i].GetCoefficient() == 0) {
      for (int j = i; j < size - 1; ++j) {
        poly[j] = poly[j + 1];
      }
      --size;
      --i;
    }
  }

  degree = std::max(degree, p.degree);
  return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &p) {
  Polynomial result;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < p.size; ++j) {
      result += poly[i] * p.poly[j];
    }
  }

  *this = result;
  return *this;
}

Polynomial operator+(const Polynomial &p1, const Polynomial &p2) {
  Polynomial result = p1;
  result += p2;
  return result;
}

Polynomial operator*(const Polynomial &p1, const Polynomial &p2) {
  Polynomial result = p1;
  result *= p2;
  return result;
}

Polynomial operator-(const Polynomial &p1, Polynomial &p2) {
  Polynomial result = p1;
  Term t1(-1);
  p2 *= t1;
  result += p2;
  return result;
}

std::istream &operator>>(std::istream &in, Polynomial &p) {
  delete[] p.poly;
  p.poly = nullptr;
  p.size = 0;
  p.degree = 0;

  char buffer[256];
  in.getline(buffer, 256);

  char *token = buffer;
  char sign = '+';

  if (*token == '+' || *token == '-') {
    sign = *token;
    ++token;
  }

  while (*token) {
    while (*token == ' ') {
      ++token;
    }

    if (!*token) {
      break;
    }

    char *nextOperator = std::strchr(token, '+');
    char *minusOperator = std::strchr(token, '-');

    if (minusOperator && (!nextOperator || minusOperator < nextOperator)) {
      nextOperator = minusOperator;
    }

    char termBuffer[50];
    termBuffer[0] = sign;

    if (nextOperator) {
      size_t length = nextOperator - token;
      std::strncpy(termBuffer + 1, token, length);
      termBuffer[1 + length] = '\0';
      token = nextOperator + 1;
      sign = *nextOperator;
    } else {
      std::strcpy(termBuffer + 1, token);
      token += std::strlen(token);
    }
    std::istringstream tempStream(termBuffer);
    Term temp;
    tempStream >> temp;
    p += Polynomial(temp);
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, Polynomial &p) {
  if (p.size == 0) {
    return out << "0";
  }

  bool firstTerm = true;
  for (int i = 0; i < p.size; ++i) {
    if (p.poly[i].GetCoefficient() == 0) {
      continue;
    }

    if (!firstTerm && p.poly[i].GetCoefficient() > 0) {
      out << "+";
    }

    out << p.poly[i];
    firstTerm = false;
  }

  return out;
}
