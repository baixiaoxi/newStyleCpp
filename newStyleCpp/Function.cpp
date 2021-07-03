#include "Function.h"
#include <stdarg.h>

bool Function::Function::test() {
	std::string s = "hello";

	if (s < "hello")
	{
		std::cout << s << " < default" << std::endl;
	}
	else if (s == "hello")
	{
		std::cout << s << " == default" << std::endl;
	}
	else
	{
		std::cout << s << " > default" << std::endl;
	}

	auto a = Add2(3.13, 2.895);
	auto b = Add2(std::string{ "Hello" }, std::string{ " World" });

	auto t = f();
	std::cout << "get<0>(t), get<1>(t), get<2>(t) = " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << std::endl;

	int myval;
	string myname;
	double mydecimal;
	tie(myval, myname, mydecimal) = f();
	std::cout << "tie(x,y,z) = " << myval << "," << myname << "," << mydecimal << std::endl;

	auto [x, y, z] = f();
	std::cout << "auto[x,y,z] = " << x << "," << y << "," << z << std::endl;

	fp fpp = myFunction2("function pointer");
	fpp(123);

	ShowVar("fcsi", 32.4f, 'a', "Test String", 4);

	C c;
	auto v = c.get_data();
	auto v2 = C().get_data();

	return true;
}

int myReturnFun(int index) {
	return index;
}

Function::fp Function::myFunction(const char* s) {
	std::cout << s << std::endl;

	return myReturnFun;
}

Function::fp Function::myFunction2(const char* s) {
	std::cout << s << std::endl;

	return myReturnFun;
}

void Function::ShowVar(const char* szTypes, ...) {
	va_list vl;
	int i;

	va_start(vl, szTypes);
	for (i = 0; szTypes[i] != '\0'; ++i)
	{
		union Printable_t {
			int i;
			float f;
			char c;
			char* s;
		} Printable;
		switch (szTypes[i])
		{
		case 'i':
			Printable.i = va_arg(vl, int);
			printf_s("%i\n", Printable.i);
			break;
		case 'f':
			Printable.f = va_arg(vl, double);
			printf_s("%f\n", Printable.f);
			break;
		case 'c':
			Printable.c = va_arg(vl, char);
			printf_s("%c\n", Printable.c);
			break;
		case 's':
			Printable.s = va_arg(vl, char*);
			printf_s("%s\n", Printable.s);
			break;
		default:
			break;
		}
	}
	va_end(vl);
}
