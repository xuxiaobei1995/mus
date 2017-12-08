#include "musApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

#include "ExampleConstConvection.h"  // a convection kernel

template <>
InputParameters
validParams<musApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

musApp::musApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  musApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  musApp::associateSyntax(_syntax, _action_factory);
}

musApp::~musApp() {}

void
musApp::registerApps()
{
  registerApp(musApp);
}

void
musApp::registerObjects(Factory & factory)
{
  /* Uncomment Factory parameter and register your new production objects here! */
	registerKernel(ExampleConstConvection);  // register a convection kernel
}

void
musApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
musApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
musApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
musApp__registerApps()
{
  musApp::registerApps();
}

extern "C" void
musApp__registerObjects(Factory & factory)
{
  musApp::registerObjects(factory);
}

extern "C" void
musApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  musApp::associateSyntax(syntax, action_factory);
}
