#ifndef MUSAPP_H
#define MUSAPP_H

#include "MooseApp.h"

class musApp;

template <>
InputParameters validParams<musApp>();

class musApp : public MooseApp
{
public:
  musApp(InputParameters parameters);
  virtual ~musApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MUSAPP_H */
