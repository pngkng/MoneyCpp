// Money.h
#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <stdexcept>
#include <cppunit/portability/Stream.h>    // or <iostream> if portability is not an issue

/** IncompatibleMoneyError
 *
 */
class IncompatibleMoneyError : public std::runtime_error
{
public:
   IncompatibleMoneyError() : std::runtime_error( "Incompatible moneys" )
  {
  }
};

/**
 * Money Main test object class
 */
class Money
{
public:
  Money( double amount, std::string currency )
    : m_amount( amount )
    , m_currency( currency )
  {
	interest_rate=0.03;
  }
  /**
   * getInterest : calculate the interest by the number of year
   *
   */
  double getInterest(int year) const
  {
		double interest=m_amount;
		for(int i=0;i<year;i++){
			interest*=(1+interest_rate);
		}
		return interest;
  }
  
  double getAmount() const
  {
    return m_amount;
  }

  std::string getCurrency() const
  {
    return m_currency;
  }

  bool operator ==( const Money &other ) const
  {
    return m_amount == other.m_amount  &&  
           m_currency == other.m_currency;
  }

  bool operator !=( const Money &other ) const
  {
    return !(*this == other);
  }

  Money &operator +=( const Money &other )
  {
    if ( m_currency != other.m_currency )
      throw IncompatibleMoneyError();

    m_amount += other.m_amount;
    return *this;
  }

private:
  double m_amount;
  std::string m_currency;
  double interest_rate;
};


// The function below could be prototyped as:
// inline std::ostream &operator <<( std::ostream &os, const Money &value )
// If you know that you will never compile on a platform without std::ostream
// (such as embedded vc++ 4.0; though even that platform you can use STLPort)
inline CPPUNIT_NS::OStream &operator <<( CPPUNIT_NS::OStream &os, const Money &value )
{
    return os << "Money< value =" << value.getAmount() << "; currency = " << value.getCurrency() << ">";
}


#endif
