#include "babbler2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
babbler2App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babbler2App::babbler2App(InputParameters parameters) : MooseApp(parameters)
{
  babbler2App::registerAll(_factory, _action_factory, _syntax);
}

babbler2App::~babbler2App() {}

void
babbler2App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<babbler2App>(f, af, s);
  Registry::registerObjectsTo(f, {"babbler2App"});
  Registry::registerActionsTo(af, {"babbler2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
babbler2App::registerApps()
{
  registerApp(babbler2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
babbler2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babbler2App::registerAll(f, af, s);
}
extern "C" void
babbler2App__registerApps()
{
  babbler2App::registerApps();
}
