#include "Encryption.h"

#include <string>
#include <iostream>
#include <Eigen/Dense>


#pragma once
class Matrix :
	public Encryption
{
	void setSettings() override;
	std::string encrypt() override;
	std::string decrypt() override;
};

