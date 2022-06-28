#include <iostream>
#include "private/src/include/BinaryNode.h"
#include "private/src/include/scanner.h"
#include "private/src/include/parser.h"
#include <string>
#include "private/src/include/Calc.h"

int main()
{
	Calc calc;
	EStatus status = EStatus::STATUS_OK;
	do {
		std::string buffer;
		std::cout << ">" << std::endl;
		std::getline(std::cin, buffer);
		//std::cout << buffer << std::endl;
		Scanner scanner(buffer);
		if (!scanner.IsEmpty())
		{
			Parser parser(scanner, calc);
			//判断解析执行状态
			if (parser.parse() == STATUS_OK)
			{
				std::cout << "result : " << parser.calculate() << std::endl;
			}
			else
			{
				std::cout << "Expression is invalid!" << std::endl;
			}
		}
		else
		{
			std::cout << "Expression is empty!" << std::endl;
		}
	} while (status != EStatus::STATUS_QUIT);

	return 0;
}