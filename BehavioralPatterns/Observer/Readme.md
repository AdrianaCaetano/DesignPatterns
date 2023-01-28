# Observer

. A Subject object (information source)  maintain a list of its dependents (who is interested in the information), called observers, and notifies them automatically of any state changes, usually by calling one of their methods.

. Define a one-to-many dependency between objects where a state change in one object results in all its dependents being notified or updated automatically.

. Is mainly used to implement distribut4ed event handling systems in "event driven" software.

. Synchronous, if information changes all observers are notified immediately

. Observer must know subject, subject must know observer

. Observer is the "view" part of the Model-View-Controller (MVC) architectural pattern

. Basic Classes: Subject (represents the core abstraction), Observer (represents the variable - user interface - abstraction). The Subject prompts the Observer object to do their thing. Each Observer can call back to the Subject as needed.  

![Observer UML diagram](Observer/BehavioralPatterns-Observer.drawio.png)

# Publish-Subscribe 

. A messaging pattern where publishers (message senders) do not program the messages to be sent directly to specific subscribers (message receivers), but instead characterize published messages into classes without knowledge of subscribers.

. Subscribers express interest in one or more classes and only receive messages the are of interest, without knowledge of which publishers

. Asynchronous implementation using message queue 
