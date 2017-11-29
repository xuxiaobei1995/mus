#include "musTestApp.h"
#include "musApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<musTestApp>()
{
  InputParameters params = validParams<musApp>();
  return params;
}

musTestApp::musTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  musApp::registerObjectDepends(_factory);
  musApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  musApp::associateSyntaxDepends(_syntax, _action_factory);
  musApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    musTestApp::registerObjects(_factory);
    musTestApp::associateSyntax(_syntax, _action_factory);
  }
}

musTestApp::~musTestApp() {}

void
musTestApp::registerApps()
{
  registerApp(musApp);
  registerApp(musTestApp);
}

void
musTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
musTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
musTestApp__registerApps()
{
  musTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
musTestApp__registerObjects(Factory & factory)
{
  musTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
musTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  musTestApp::associateSyntax(syntax, action_factory);
}
