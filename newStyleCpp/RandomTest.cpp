#include "RandomTest.h"
#include <random>
#include <vector>
#include <array>

namespace RandomTest
{
	using namespace std;

	bool RandomTest::test()
	{
		// 1.bernouli_distribution
		{
			double p = 0.5;
			mt19937 gen(1729);
			bernoulli_distribution distr(p);
			cout << distr.p() << endl;
			distr(gen);
		}
		// 2.binomial_distribution
		{
			int t = 1;
			double p = 0.5;
			mt19937 gen(1729);
			binomial_distribution<> distr(t, p);
			cout << distr.p() << distr.t() << endl;
			distr(gen);
		}
		// 3.cauchy_distribution
		{
			double a = 0.0, b = 1;
			mt19937 gen(1701);
			cauchy_distribution<> distr(a, b);
			cout << distr.min() << distr.max() << distr.a() << distr.b() << endl;
			distr(gen);
		}
		// 4.chi_squared_distribution
		{
			double n = 0.5;
			mt19937 gen(1701);
			chi_squared_distribution<> distr(n);
			cout << distr.min() << distr.max() << distr.n() << endl;
			distr(gen);
		}
		// 5.discard_block_engine
		// 6.discrete_distribution
		{
			mt19937 gen(1701);
			discrete_distribution<> distr({ 1, 2, 3, 4, 5 });
			cout << distr.min() << distr.max() << endl;
			vector<double> p = distr.probabilities();
			distr(gen);
		}
		// 7.exponential_distribution
		{
			double l = 0.5;
			mt19937 gen(1701);
			exponential_distribution<> distr(l);
			cout << distr.min() << distr.max() << distr.lambda() << endl;
			distr(gen);
		}
		// 8.extreme_value_distribution
		{
			double a = 0.0;
			double b = 1;
			mt19937 gen(1701);
			extreme_value_distribution<> distr(a, b);
			cout << distr.min() << distr.max() << distr.a() << distr.b() << endl;
			distr(gen);
		}
		// 9.fisher_f_distribution
		{
			double m = 1, n = 1;
			mt19937 gen(1701);
			fisher_f_distribution<> distr(m, n);
			cout << distr.min() << distr.max() << distr.m() << distr.n() << endl;
			distr(gen);
		}
		// 10.gamma_distribution
		{
			double a = 0, b = 1;
			mt19937 gen(1701);
			gamma_distribution<> distr(a, b);
			cout << distr.min() << distr.max() << distr.alpha() << distr.beta() << endl;
			distr(gen);
		}
		// 11.independent_bits_engine
		{
			double p = 0.5;
			mt19937 gen(1701);
			geometric_distribution<> distr(p);
			cout << distr.min() << distr.max() << distr.p() << endl;
			distr(gen);
		}
		// 12.linear_congruential_engine
		{
			minstd_rand0 rand0;
			minstd_rand rand;
		}
		// 13.lognormal_distribution
		{
			double m = 1;
			double s = 1;
			mt19937 gen(1701);
			lognormal_distribution<> distr(m, s);
			cout << distr.min() << distr.max() << distr.m() << distr.s() << endl;
			distr(gen);
		}
		// 14.mersenne_twister_engine
		{
			mt19937 mt19937;
			mt19937_64 mt19937_64;
		}
		// 15.negative_binomial_distribution
		{
			int k = 1;
			double p = 0.5;
			mt19937 gen(1729);
			negative_binomial_distribution<> distr(k, p);
			cout << distr.k() << distr.p() << endl;
			distr(gen);
		}
		// 16.normal_distribution
		{
			double m = 1;
			double s = 1;
			mt19937 gen(1701);
			normal_distribution<> distr(m, s);
			cout << distr.min() << distr.max() << distr.mean() << distr.stddev() << endl;
			distr(gen);
		}
		// 17.piecewise_constant_distribution
		{
			mt19937 gen(1701);
			vector<double> intervals{ 0, 1, 6, 15 };
			vector<double> weights{ 1, 5, 10 };
			piecewise_constant_distribution<double> distr(intervals.begin(), intervals.end(), weights.begin());
			cout << distr.min() << distr.max() << endl;
			vector<double> i = distr.intervals();
			vector<double> d = distr.densities();
			distr(gen);
		}
		// 18.piecewise_linear_distribution
		{
			mt19937 gen(1701);
			vector<double> intervals{ 0, 1, 6, 15 };
			vector<double> weights{ 1, 5, 6, 10 };
			piecewise_linear_distribution<double> distr(intervals.begin(), intervals.end(), weights.begin());
			cout << distr.min() << distr.max() << endl;
			vector<double> i = distr.intervals();
			vector<double> d = distr.densities();
			distr(gen);
		}
		// 19.poisson_distribution
		{
			double p = 1.0;
			mt19937 gen(1701);
			poisson_distribution<> distr(p);
			cout << distr.min() << distr.max() << distr(gen) << endl;
		}
		// 20.random_device
		{
			// 1.runs more sloly than generators created from engines and engine adaptors
			// 2.Generally, random_device is used to seed other generators created with engines or engine adaptors
			random_device gen;
			cout << gen.entropy() << gen.min() << gen.max() << gen() << endl;
		}
		// 21.seed_seq
		{
			seed_seq sseq = { 1701, 1729, 1791 };
			array<unsigned int, 5> seq;
			sseq.generate(seq.begin(), seq.end());
			// seed_seq::param()
			ostream_iterator<seed_seq::result_type> out(cout, " ");
			sseq.param(out);
		}
		// 22.shuffle_order_engine
		{

		}
		// 23.student_t_distribution
		{
			double n = 0.5;
			mt19937 gen(1701);
			student_t_distribution<> distr(n);
			distr(gen);
		}
		// 24.subtract_with_carry_engine
		{

		}
		// 25.uniform_int_distribution
		{
			int a = 1;
			int b = 10;
			mt19937 gen(1729);
			uniform_int_distribution<> distr(a, b);
			distr(gen);
		}
		// 26.uniform_real_distribution
		{
			double a = 1.0;
			double b = 1.5;
			mt19937 gen(1729);
			uniform_real_distribution<> distr(a, b);
			distr(gen);
		}
		// 27.weibull_distribution
		{
			double a = 1;
			double b = 1;
			mt19937 gen(1701);
			weibull_distribution<> distr(a, b);
			distr(gen);
		}

		return true;
	}
}