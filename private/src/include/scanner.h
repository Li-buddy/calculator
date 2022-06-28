#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <string>

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_SUBSTRACT,
	TOKEN_MULTIPLY,
	TOKEN_DEVIDE,
	TOKEN_LEFTBRACKET,
	TOKEN_RIGHTBRACKET,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner {
public:
	explicit Scanner(const std::string& buffer);
	~Scanner();

	void accept();
	double getNumber()const { return m_number; }
	EToken getToken()const { return m_token; }
	std::string getSymbol()const { return m_symbol; } 
	bool IsEmpty()const { return m_isEmpty; }
	bool IsDone()const { return m_token == TOKEN_END; }  //�����Ƿ����ɨ��

private:
	void skipWhite();

private:
	const std::string m_buffer;
	unsigned int m_curPos;
	EToken m_token;
	double m_number;
	std::string m_symbol;
	bool m_isEmpty;                       //��ǿհױ��ʽ�������޸��ձ��ʽ�Ĵ���
};

#endif // !_SCANNER_H_
