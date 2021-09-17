# Factory Methods and Abstract Factory Methods
Creational Pattern

## Factory

### Structure
1. A **creator** `class` declares the factory method that returns new product objects.
2. A **product** `interface` such that the factory method return the same type

Example:

- Car Factory  
    - Sedan  
    - SUV  
    - Truck  
    - Van  

- Car Interface
    - number of wheels
    - number of doors
    - speed
    - price

(Diagram)

### Pros and Cons
* Pros
    1. decoupling between creator and products
        1. Single Responsibiltiy Principle
            - creator 
            - producer
        2. Open/Close Principle
            - introduce new product will not breaking existing client code.

* Cons
    - Implementations. A lot of subclasses. 


## Abstract Factory
The abstraction is defined the family of related products.

Example:

- Creator
    - CreatorLegacy
        - Legacy product 1
        - Legacy prodcut 2
    - CreatorNew
        - new product 1
        - new product 2

- Creator Interface

- Product Interface


