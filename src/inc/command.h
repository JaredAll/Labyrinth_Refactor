#ifndef COMMAND_H
#define COMMAND_H

#include "character.h"

class Command
{
public:
  
  virtual void execute( Character* character ) = 0;
  
};
