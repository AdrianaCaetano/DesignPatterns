# Creational Patterns

Used to construct objects such that they can be decoupled from their implementing system.


## Most Common:

**Abstract Factory**: Creates an instance of several families of classes

**Builder**: Separates object construction from its representation

**Factory Method**: Creates an instance of several derived classes

**Object Pool**: Avoid expensive acquisition and release of resources by recycling objects that are no longer in use

**Prototype**: A fully initialized instance to be copied or cloned

**Singleton**: A class of which only a single instance can exist

## Important Notes:

Abstract Factory can use Singleton in their implementation.

Static Factory Method is simply a static method that returns an instance of a class.

Builder vs Abstract Factory: Builder focus on constructing a complex object step by step. Abstract Factory emphasizes a family of product objects (simple or complex). 

