#pragma once
#include <string>
#include "json.hpp"
class Config
{
public:
	Config(const std::string& path);
    Config(const nlohmann::json& config);
    template<typename T>
    nlohmann::json::reference operator[](T* key)
    {
        return config[key];
    }
private:
	nlohmann::json config;
};

