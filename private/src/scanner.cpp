#include "./include/scanner.h"
#include <string>

Scanner::Scanner(const std::string& buffer)
	:m_buffer(buffer), m_curPos(0)
{
	accept();
	m_isEmpty = (m_token == TOKEN_END);
}

Scanner::~Scanner()
{
}

void Scanner::skipWhite()
{
	//ÊÇ·ñ¿Õ×Ö·û
	while (isspace(m_buffer[m_curPos]))
		++m_curPos;
}

void Scanner::accept()
{
	skipWhite();
	switch (m_buffer[m_curPos])
	{
	case '+':
		m_token = EToken::TOKEN_PLUS;
		++m_curPos;
		break;
	case '-':
		m_token = EToken::TOKEN_SUBSTRACT;
		++m_curPos;
		break;
	case '*':
		m_token = EToken::TOKEN_MULTIPLY;
		++m_curPos;
		break;
	case '/':
		m_token = EToken::TOKEN_DEVIDE;
		++m_curPos;
		break;
	case '=':
		m_token = EToken::TOKEN_ASSIGN;
		++m_curPos;
		break;
	case '(':
		m_token = EToken::TOKEN_LEFTBRACKET;
		++m_curPos;
		break;
	case ')':
		m_token = EToken::TOKEN_RIGHTBRACKET;
		++m_curPos;
		break;
	case '0':case '1':case '2':case '3':case '4':case '5':
	case '6':case '7':case '8':case '9':case '.':
	{
		m_token = TOKEN_NUMBER;
		char* p = nullptr;
		m_number = strtod(&m_buffer[m_curPos], &p);
		m_curPos = p - &m_buffer[0];
		break;
	}
	case '\0':case '\n':case '\r':
		m_token = TOKEN_END;
		break;
	default:
		if (isalpha(m_buffer[m_curPos]) || '_' == m_buffer[m_curPos])
		{
			m_token = EToken::TOKEN_IDENTIFIER;
			m_symbol.erase();
			char ch = m_buffer[m_curPos];
			while (isalnum(m_buffer[m_curPos]) || '_' == m_buffer[m_curPos])
			{
				m_symbol += ch;
				++m_curPos;
				ch = { m_buffer[m_curPos] };
			}
			break;
		}
		else
		{
			m_token = TOKEN_ERROR;
		}
		break;
	}
}