#ifndef MUSTESTAPP_H
#define MUSTESTAPP_H

#include "MooseApp.h"

class musTestApp;

template <>
InputParameters validParams<musTestApp>();

class musTestApp : public MooseApp
{
public:
  musTestApp(InputParameters parameters);
  virtual ~musTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MUSTESTAPP_H */
