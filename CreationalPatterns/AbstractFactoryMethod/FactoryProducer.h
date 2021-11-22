#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H
#include "CAMealFactory.h"
#include "NYMealFactory.h"

// Abstract Factory

using namespace std;

class FactoryProducer
{
	public:
		static AbstractMealFactory* getFactory(string name)
		{
			if(name == "ca")
				return new CAMealFactory();
			else if(name == "ny")
				return new NYMealFactory();
			else
				return nullptr;
		}
};
#endif
