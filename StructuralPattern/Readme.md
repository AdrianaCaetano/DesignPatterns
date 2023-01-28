# Structural Patterns

Used to form large object structures between many disparate objects


## Most Common

**Adapter**: Match interfaces of different classes

**Bridge**: Separates an object interface from its implementation

**Composite**: A tree structure of simple composite objects

**Decorator**: Add responsibilities to objects dynamically

**Facade**: A single class that represents an entire subsystem

**Flyweight**: A fine-grained instance used for efficient sharing

**Private Class Data**: Restricts accessor/mutator access

**Proxy**: An object representing another object


## Important Notes

Adapter vs. Bridge: Adapter makes things work after they are designed - retrofitt4ed to make unrelated classes work together; Bridge makes them work before - designed up-front to let the abstraction and implementation vary independently.

Adapter vs. Proxy vs. Decorator: Adapter provides a different interface to its subject. Proxy provides the same interface. Decorator provides an enhanced interface.

Proxy vs Decorator: they have different purposes but similar structures. Both provide a level of indirection to another object, and the implementation keep a reference to the object to which they forward requests. Decorator refers back to the interface (so it can compose), Proxy refers to the real object. 

Adapter vs. Decorator: Adapter changes an object interface, Decorator enhances an object's responsibility. Decorator supports recursive composition, which is not possible with Adapters.

Composite vs. Decorator: both have similar structure diagrams, reflecting the recursive composition to organize an open-ended number of objects. Decorator could be viewed as a Composite with only one component. However, Decorator adds additional responsibilities (not intended for object aggregation) without subclassing. Composite focus is on representation.

Composite could use Chain of Responsibility to let components access global properties through their parent. It could also use Decorator to override these properties on parts of the composition. 

