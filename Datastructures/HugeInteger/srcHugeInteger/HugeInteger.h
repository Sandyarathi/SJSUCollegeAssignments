/*
 * HugeInteger.h
 *
 *  Created on: Sep 24, 2014
 *      Author: sandyarathidas
 */

#ifndef HUGEINTEGER_H_
#define HUGEINTEGER_H_

#include<vector>
#include<string>

using namespace std;

const int MAXSIZE=40;


class HugeInteger {
public:
	// constructor: converts a long integer into a HugeInteger object
	HugeInteger( long = 0 );
	// constructor: converts a string representing a large int to a HugeInteger object
	HugeInteger( const std::string & );
	// Addition operator: HugeInteger + HugeInteger
	// If overflow, print “Error: Addition overflow” and return 0 (as HugeInteger)
	HugeInteger add( const HugeInteger & ) const;
	// Addition operator: HugeInteger + int
	// If overflow, print “Error: Addition overflow” and return 0 (as HugeInteger)
	HugeInteger add( int ) const;
	// Addition operator: HugeInteger + string representing large integer value
	// If overflow, print “Error: Addition overflow” and return 0 (as HugeInteger)
	HugeInteger add( const std::string & ) const;
	// subtraction operator (subtract op2 from *this); op1 – op2
	// where op1 is a HugeInteger and op2 is also a HugeInteger
	// if op1 < op2, print “Error: Tried to subtract larger value from smaller value”
	// and return 0 (as HugeInteger).
	HugeInteger subtract( const HugeInteger & op2 ) const;
	// subtraction operator (subtract op2 from *this); op1 – op2
	// where op1 is a HugeInteger and op2 is int
	// if op1 < op2, print “Error: Tried to subtract larger value from smaller value”
	// and return 0 (as HugeInteger).
	HugeInteger subtract( int op2 ) const;
	// subtraction operator; subtract op2 from *this); op1 – op2
	// where op1 is a HugeInteger and op2 is a string representing large integer value
	// if op1 < op2, print “Error: Tried to subtract larger value from smaller value”
	// and return 0 (as HugeInteger).
	HugeInteger subtract( const std::string & op2) const;
	// comparison or predicate function between two HugeInteger operators.
	// return true if the relationship holds, else return false
	bool isEqualTo( const HugeInteger & ) const; // is equal to
	bool isNotEqualTo( const HugeInteger & ) const; // not equal to
	bool isGreaterThan( const HugeInteger & ) const; // greater than
	bool isLessThan( const HugeInteger & ) const; // less than
	bool isGreaterThanOrEqualTo( const HugeInteger & ) const; // greater than or equal to
	bool isLessThanOrEqualTo( const HugeInteger & ) const; // less than or equal
	bool isZero() const; // is zero?
	// convert a string representing a large integer into a HugeInteger
	void input( const std::string & );
	// display the HugeInteger, skip leading zeros
	void output() const;



private :
	void convertLongToVec(long);
	//convert a string to a vector
	void convertStrToVec(string);
	//converts a int to a vector
	vector<short> convertIntToVec(int);

	vector<short> integerVector;

};

#endif /* HUGEINTEGER_H_ */
