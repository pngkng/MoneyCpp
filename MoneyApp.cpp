#include <iostream>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/XmlOutputter.h>

using namespace std;
using namespace CppUnit;

int main()
{
   TestResult    result;
   TestResultCollector controller;
   result.addListener(&controller);
   
  // Get the top level suite from the registry
  CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CPPUNIT_NS::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );
  // Run the test.
  runner.run(result);

   // output test result to xml file
   ofstream xmlFileOut("cpptestresults.xml");
   XmlOutputter xmlOut(&controller, xmlFileOut);
   xmlOut.write();
  // Return error code 1 if the one of test failed.
  return 0;
}

