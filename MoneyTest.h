// MoneyTest.h
#ifndef MONEYTEST_H
#define MONEYTEST_H

#include <cppunit/extensions/HelperMacros.h>

/**
 *  MoneyTest
 */
class MoneyTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( MoneyTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testEqual );
  CPPUNIT_TEST( testAdd );
  CPPUNIT_TEST( testGetInterest1Year );
  CPPUNIT_TEST( testGetInterest2Year );
  CPPUNIT_TEST( testAddThrow );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();
  void testConstructor();
  void testEqual();
  void testGetInterest1Year();
  void testGetInterest2Year();
  void testAdd();
  void testAddThrow();
};

#endif  // MONEYTEST_H
