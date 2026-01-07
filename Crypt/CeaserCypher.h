#include "Encryption.h"

#include <string>
#include <iostream>

#pragma once
class CeaserCypher :
    public Encryption
{
    void setSettings() override;
    std::string encrypt() override;
    std::string decrypt() override;
};

