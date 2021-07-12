#include "ChronoTest.h"
#include <chrono>

namespace ChronoTest
{
	using namespace std;

	bool ChronoTest::test()
	{
		// 1.literal
		constexpr auto day = 14d;
		constexpr auto twoDays = 48h;
		constexpr auto week = 24h * 7;
		constexpr auto my_duration_unit = 108ms;
		constexpr auto theYear = 2021y;
		// 2.from_stream
		istringstream str{ "22" };
		basic_istream<char> stream{ str.rdbuf() };
		chrono::day d;
		chrono::from_stream(stream, "%d", d);
		cout << d << "\n";
		// 3.operator
		chrono::day d1{ 1 };
		cout << d1 + chrono::days(2) << '\n';
		chrono::month m{ 11 };
		cout << m + chrono::months(3) << '\n';
		chrono::weekday wd = chrono::Thursday;
		cout << wd + chrono::days(1) << '\n';
		chrono::year_month_weekday ymw{ chrono::year(1997) / chrono::January / chrono::Wednesday[1] };
		cout << ymw + chrono::months{ 1 } << '\n';
		cout << ymw + chrono::years{ 1 } << '\n';
		chrono::year_month_weekday_last ymwl{ chrono::year{1997} / chrono::January / chrono::Wednesday[chrono::last] };
		cout << ymwl + chrono::months{ 1 } << '\n';
		cout << ymwl + chrono::years{ 1 } << '\n';
		// 4.day
		chrono::day day1{ 1 };
		const chrono::day day2{ 1 };
		day1 += chrono::days(2);
		day1 -= chrono::days{ 3 };
		day1++;
		cout << day1 << boolalpha << day1.ok() << endl;
		// 5.duration
		chrono::duration<int, ratio<1, 3>> dur;
		chrono::duration<int> dur2{ 1000 };
		dur.max();
		dur.min();
		dur.zero();
		dur.count();
		dur += dur2;
		// 6.duration_values
		chrono::duration_values<int>::max();
		chrono::duration_values<int>::min();
		chrono::duration_values<int>::zero();
		// 7.hh_mm_ss
		chrono::hh_mm_ss hms(dur);
		hms.is_negative();
		chrono::hours hour = hms.hours();
		chrono::minutes min = hms.minutes();
		chrono::seconds sec = hms.seconds();
		chrono::hh_mm_ss<chrono::duration<int, ratio<1, 3>>>::precision prec = hms.subseconds();
		chrono::hh_mm_ss<chrono::duration<int, ratio<1, 3>>>::precision prec2 = hms.to_duration();
		// 8.high_resolution_clock
		bool is_steady = chrono::high_resolution_clock::is_steady;
		auto now = chrono::high_resolution_clock::now();
		// 9.leap_second
		auto ss = chrono::sys_seconds::max();
		chrono::leap_second ls(ss, false, 11s);
		chrono::sys_seconds date1 = ls.date();
		chrono::seconds value1 = ls.value();
		// 10.leap_second_info
		chrono::leap_second_info lsi = chrono::get_leap_second_info(chrono::utc_time<chrono::duration<int>>());
		bool isLeapSecond = lsi.is_leap_second;
		chrono::seconds elapsed = lsi.elapsed;
		// 11.month
		chrono::month month1{ 12 };
		month1.ok();
		month1 = chrono::January;
		month1 = chrono::December;
		// 12.month_day
		chrono::month_day monthDay{ chrono::January, chrono::day{12} };
		chrono::month_day monthDay2(30d / chrono::July);
		cout << monthDay << monthDay.ok() << monthDay.month() << monthDay.day() << endl;
		// 13.month_day_last
		chrono::month_day_last monthDayLast{ chrono::July / chrono::last };
		cout << monthDayLast << monthDayLast.month() << monthDayLast.ok() << endl;
		// 14.month_weekday
		chrono::month_weekday monthWeekday{ chrono::July / chrono::Monday[1] };
		cout << monthWeekday << monthWeekday.ok() << monthWeekday.month() << monthWeekday.weekday_indexed() << endl;
		// 15.month_weekday_last
		chrono::month_weekday_last monthWeekdayLast{ chrono::January / chrono::Monday[chrono::last] };
		cout << monthWeekdayLast << monthWeekdayLast.ok() << monthWeekdayLast.month() << monthWeekdayLast.weekday_last() << endl;
		// 16.steady_clock
		// A steady_clock isn't subject to these adjustments, making it the preferred way to keep track of elapsed time
		chrono::steady_clock::duration duration = 11ns;
		bool isSteady = chrono::steady_clock::is_steady;
		chrono::steady_clock::time_point now1 = chrono::steady_clock::now();
		// 17.system_clock
		chrono::system_clock::time_point now2 = chrono::system_clock::now();
		isSteady = chrono::system_clock::is_steady;
		chrono::system_clock::time_point timePoint;
		chrono::system_clock::to_time_t(timePoint);
		time_t timeT{ };
		chrono::system_clock::from_time_t(timeT);
		// bool isMonotonic = chrono::system_clock::is_monotonic;
		// 18.time_point
		chrono::system_clock::time_point now3 = chrono::system_clock::now();
		chrono::system_clock::time_point maxPoint = now3.max();
		chrono::system_clock::time_point minPoint = now3.min();
		chrono::system_clock::duration dur1 = now3.time_since_epoch();
		// 19.time_zone
		// chrono::time_zone timeZone = chrono::system_clock::time_point
		// 20.treat_as_floating_point
		cout << typeid(chrono::treat_as_floating_point<float>::type).name() << endl;
		// 21.weekday
		constexpr auto ymd{ chrono::November / 15 / 2021 };
		auto today = chrono::sys_days{ floor<chrono::days>(chrono::system_clock::now()) };
		auto localToday = chrono::local_days{ today.time_since_epoch() };
		chrono::weekday weekDay{ 1 };
		weekDay = { chrono::Wednesday };
		weekDay = { today };
		weekDay = (chrono::weekday)localToday;
		weekDay.c_encoding();
		weekDay.iso_encoding();
		weekDay.ok();
		constexpr auto firstMondayInJanuary = chrono::year_month_day{ chrono::Monday[2] / chrono::January / 2021y };
		cout << firstMondayInJanuary << "\n";
		constexpr auto lastMondayInJanuary = chrono::year_month_day{ chrono::Tuesday[chrono::last] / chrono::January / 2021y };
		cout << lastMondayInJanuary << "\n";
		// 22.weekday_indexed
		constexpr chrono::weekday_indexed wdi = chrono::weekday_indexed{ chrono::Monday, 1 };
		chrono::weekday_indexed wdi2 = chrono::Monday[2];
		cout << wdi.ok() << wdi.index() << wdi.weekday() << endl;
		// 23.weekday_last
		constexpr chrono::weekday_last wdl{ chrono::Monday[chrono::last] };
		cout << wdl.ok() << wdl.weekday() << endl;
		// 24.year
		chrono::year y{ 2021 };
		cout << y << y.is_leap() << y.max() << y.min() << y.ok() << endl;
		// 25.year_month
		chrono::year_month ym{ 2021y / chrono::June };
		cout << ym.year() << ym.month() << ym.ok() << endl;
		// 26.year_month_day
		chrono::year_month_day ymd2{ chrono::April / 4 / 1975 };
		chrono::from_stream(cin, "%d", ymd2);
		cout << ymd2 << ymd2.ok() << ymd2.month() << ymd2.day() << ymd2.year()
			<< static_cast<chrono::local_days>(ymd2) << static_cast<chrono::sys_days>(ymd2) << endl;
		// 27.year_month_day_last
		chrono::year_month_day_last ymdl{ chrono::April / chrono::last / 1975 };
		cout << ymdl << ymdl.ok() << ymdl.day() << static_cast<chrono::local_days>(ymdl) << ymdl.month()
			<< ymdl.month_day_last() << static_cast<chrono::sys_days>(ymdl) << ymdl.year() << endl;
		// 28.year_month_weekday
		chrono::year_month_weekday ymw2{ 1997y / chrono::January / chrono::Wednesday[1] };
		cout << ymw2 << ymw2.ok() << ymw2.index() << ymw2.month() << ymw2.year() << static_cast<chrono::sys_days>(ymw2) <<
			static_cast<chrono::local_days>(ymw2) << ymw2.weekday() << ymw2.weekday_indexed() << endl;
		// 28.year_month_weekday_last
		chrono::year_month_weekday_last ymwl2{ 1997y / chrono::January / chrono::Wednesday[chrono::last] };
		cout << ymwl2 << ymwl2.ok() << ymwl2.month() << ymwl2.year() << static_cast<chrono::sys_days>(ymwl2) <<
			static_cast<chrono::sys_days>(ymwl2) << ymwl2.weekday() << ymwl2.weekday_last() << endl;

		return true;
	}
}