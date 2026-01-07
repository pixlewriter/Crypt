#include <string>
#include <vector>
#include <map>

#pragma once
class Encryption
{
protected:
	std::map<std::string,std::string> settings;

public:
	void setInputMessage(std::string);
	virtual void setSettings() = 0;
	std::string getInputMessage();
	std::string getEncryptedMessage();
	virtual std::string encrypt() = 0;
	virtual std::string decrypt() = 0;
};

