# Behavioral Patterns

Used to manage algorithms, relationships, and reponsibilities between objects.

## Most Common
**Chain of Responsibility**: A way of passing a request between a chain of objects

**Command**: Encapsulate a command request as an object

**Interpreter**: A way to include language elements in a program

**Iterator**: Sequentially access the elements of a collection

**Mediator**: Defines simplified communication between classes

**Memento**: Capture and restore an object's internal state

**Null Object**: Designed to act as default value of an object

**Observer**: A way of notifying change to a number of classes

**State**: Encapsulates an algorithm inside a class

**Template Method**: Defer the exact steps of an algorithm to a subclass

**Visitor**: Defines a new operation to a class without change


## Observations

Observer vs Publish-subscribe : Synchronous vs asynchronous. In the Observer/Observable pattern, the observers are aware of the observable. Whereas in Publisher/Subscriber, publishers and subscribers don't need to know each other. 

Template Method vs Factory Method: both relies on inheritance. Template Method defines the steps of an algorithm, and level the task of implementing them to subclasses. In Factory Method, a superclass defines the interface to create an object, and it decides which concrete class to instantiate. Factory Method is a specialization of Template Method.

Iterator can transverse a composite. 

Visitor can apply an operation over a Composite.

Visitor is a more powerful Command because the visitor may initiate whatever is appropriate for the kind of object it encounters.


## Diagrams
