#ifndef MYCOMPARISON_H
#define MYCOMPARISON_H
#include "nodos.h"
class mycomparison
{
  bool reverse;
public:

  mycomparison(const bool& revparam=false)
    {reverse=revparam;}

  bool operator() (const Nodos& lhs, const Nodos&rhs) const
  {
    if (reverse) return (lhs.valor>rhs.valor);
    else return (lhs.valor<rhs.valor);
  }
};



#endif // MYCOMPARISON_H
