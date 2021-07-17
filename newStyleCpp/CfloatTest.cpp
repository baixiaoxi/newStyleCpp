#include "CfloatTest.h"
#include <cfloat>

namespace CfloatTest
{
	using namespace std;

	bool CfloatTest::test()
	{
		int result;

		result = FLT_ROUNDS;
		result = FLT_EVAL_METHOD;
		result = FLT_HAS_SUBNORM;
		result = DBL_HAS_SUBNORM;
		result = LDBL_HAS_SUBNORM;
		result = FLT_RADIX;
		result = FLT_MANT_DIG;
		result = DBL_MANT_DIG;
		result = LDBL_MANT_DIG;
		result = FLT_DECIMAL_DIG;
		result = DBL_DECIMAL_DIG;
		result = DECIMAL_DIG;
		result = FLT_DIG;
		result = DBL_DIG;
		result = LDBL_DIG;
		result = FLT_MIN_EXP;
		result = DBL_MIN_EXP;
		result = LDBL_MIN_EXP;
		result = FLT_MIN_10_EXP;
		result = DBL_MIN_10_EXP;
		result = LDBL_MIN_10_EXP;
		result = FLT_MAX_EXP;
		result = DBL_MAX_EXP;
		result = LDBL_MAX_EXP;
		result = FLT_MAX_10_EXP;
		result = DBL_MAX_10_EXP;
		result = LDBL_MAX_10_EXP;
		result = FLT_MAX;
		result = DBL_MAX;
		result = LDBL_MAX;
		result = FLT_EPSILON;
		result = DBL_EPSILON;
		result = LDBL_EPSILON;
		result = FLT_MIN;
		result = DBL_MIN;
		result = LDBL_MIN;
		result = FLT_TRUE_MIN;
		result = DBL_TRUE_MIN;
		result = LDBL_TRUE_MIN;

		return true;
	}
}