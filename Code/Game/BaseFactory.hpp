//----------------------------------------------------------------------------------------------------
// BaseFactory.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include <functional>
#include <string>
#include <unordered_map>

#include "Engine/Core/StringUtils.hpp"
#include "Game/IState.hpp"

typedef std::function<IState*()> Creator;

//----------------------------------------------------------------------------------------------------
class BaseFactory
{
public:
    void    Register(String const& name, Creator const& creator);
    IState* Create(String const& name) const;

protected:
    std::unordered_map<String, Creator> creators;
};
